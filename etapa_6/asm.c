#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "asm.h"

asm_inst* asm_op(char* lbl, char* op, char* src, char* dst)
{
  asm_inst* new_inst = malloc(sizeof(asm_inst));

  new_inst->lbl = (lbl) ? strdup(lbl) : NULL;
  new_inst->op = strdup(op);
  new_inst->src = (src) ? strdup(src) : NULL;
  new_inst->dst = (dst) ? strdup(dst) : NULL;

  return new_inst;
};

void asm_start(asm_inst_list_item** head, asm_inst* new_inst)
{
  // Allocate node.
  asm_inst_list_item* new_item = malloc(sizeof(asm_inst_list_item));

  // Put in the new instruction.
  new_item->inst = new_inst;

  // Make next of new item as head and previous as NULL.
  new_item->next = (*head);
  new_item->prev = NULL;

  // Change prev of head item to new item.
  if ((*head) != NULL) (*head)->prev = new_item;

  // Move the head to point to the new item.
  (*head) = new_item;
};

void asm_end(asm_inst_list_item** head, asm_inst* new_inst)
{
  // Allocate new item.
  asm_inst_list_item* new_item = malloc(sizeof(asm_inst_list_item));

  asm_inst_list_item* last = *head;

  // Put in the new instruction.
  new_item->inst = new_inst;

  // Gonna be the last one, so next of it should be NULL.
  new_item->next = NULL;

  // If list is empty, then make new item as HEAD.
  if (*head == NULL)
  {
    new_item->prev = NULL;
    *head = new_item;
    return;
  }

  // Else traverse till last node.
  while (last->next != NULL) last = last->next;

  // Change the next of the last item.
  last->next = new_item;

  // Make last item as prev of new item.
  new_item->prev = last;
};

void asm_cat(asm_inst_list_item** dst_list, asm_inst_list_item* src_list)
{
  if (*dst_list == NULL)
  {
    *dst_list = src_list;
    return;
  }

  asm_inst_list_item* current = *dst_list;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = src_list;
};

char* x86label()
{
  char* label_name;
  asprintf(&label_name,"L%d", ++label_num);
  return label_name;
};

char* x86reg(char* iloc_reg)
{
  if (!strcmp("r0", iloc_reg))
  {
    return "%eax";
  } else if (!strcmp("r1", iloc_reg))
  {
    return "%ebx";
  } else if (!strcmp("r2", iloc_reg))
  {
    return "%ecx";
  } else if (!strcmp("r3", iloc_reg))
  {
    return "%edx";
  } else
  {
    return NULL;
  }
};

char* x86lit(char* iloc_lit)
{
  char* lit_string = malloc(strlen("$")+strlen(iloc_lit));
  lit_string = strdup("$");
  lit_string = strcat(lit_string, iloc_lit);
  return lit_string;
};

void asm_print_globals(ht_entry** table)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    ht_entry* current = table[i];
    while(current != NULL)
    {
      if (current->symbol->symbol_type == VAR)
      {
        printf("%s:\n  .zero 4\n", current->symbol->label);
      }
      current = current->next;
    }
  }
};

asm_inst_list_item* iloc_to_asm(inst_list_item* iloc)
{
  asm_inst_list_item* asm_code = NULL;

  inst_list_item* iloc_item = iloc;
  while(iloc_item != NULL)
  {
    inst* iloc_inst = iloc_item->instruction;

    // ASM de entrada em funcoes.
    if (iloc_inst->label && !strcmp(iloc_inst->label, "// FUNC BEGIN"))
    {
      char* func_label = iloc_item->next->instruction->label;
      if (strcmp(iloc_item->next->instruction->label, "L0") == 0)
      {
        asm_end(&asm_code, asm_op("main", "pushq", "%rbp", NULL));
        asm_end(&asm_code, asm_op(NULL, "movq", "%rsp", "%rbp"));
      } 
      else 
      {
        asm_end(&asm_code, asm_op(func_label, "pushq", "%rbp", NULL));
        asm_end(&asm_code, asm_op(NULL, "movq", "%rsp", "%rbp"));
      } 
    }
    // ASM de retorno de funcoes.
    else if ((iloc_inst->label && !strcmp(iloc_inst->label, "// RETURN BEGIN")) 
            || !strcmp(iloc_inst->op, "halt"))
    {
      asm_end(&asm_code, asm_op(NULL, "popq", "%rbp", NULL));
      asm_end(&asm_code, asm_op(NULL, "ret", NULL, NULL));
    }


    iloc_item = iloc_item->next;
  }

  return asm_code;
};

void print_asm(asm_inst_list_item* asm_code, symb_table* scope)
{
  // Declare main.
  printf("  .globl main\n  .type main, @function\n");

  // Declare globals.
  ht_entry** global_table = scope->table;
  asm_print_globals(global_table);

  asm_inst_list_item* current = asm_code;
  while (current != NULL)
  {
    if (current->inst->lbl)
      printf("%s:\n", current->inst->lbl);
    if (strcmp(current->inst->op, "ret") == 0)
      printf("  %s", current->inst->op);
    else
      printf("  %s %s", current->inst->op, current->inst->src);
    if (current->inst->dst)
      printf(", %s\n", current->inst->dst);
    else
      printf("\n");

    current = current->next;
  }
}