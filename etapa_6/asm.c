#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "asm.h"

int last_inst_div_mul = 0;

asm_inst* asm_op(char* lbl, char* op, char* src, char* dst)
{
  asm_inst* new_inst = malloc(sizeof(asm_inst));

  new_inst->lbl = (lbl) ? strdup(lbl) : NULL;
  new_inst->op = (op) ? strdup(op) : NULL;
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
    return "%ah";
  } else if (!strcmp("r1", iloc_reg))
  {
    return "%al";
  } else if (!strcmp("r2", iloc_reg))
  {
    return "%bh";
  } else if (!strcmp("r3", iloc_reg))
  {
    return "%bl";
  } else if (!strcmp("r4", iloc_reg))
  {
    return "%ch";
  } else if (!strcmp("r5", iloc_reg))
  {
    return "%cl";
  } else if (!strcmp("r6", iloc_reg))
  {
    return "%dh";
  }
   else if (!strcmp("r7", iloc_reg))
  {
    return "%dl";
  }
  else if (!strcmp("rfp", iloc_reg))
  {
    return "%rbp";
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

char* x86Roffset(char* iloc_reg, char* iloc_offset)
{
  char* x86adressing;
  char* x86r = x86reg(iloc_reg); 
  x86adressing = malloc(sizeof("-()")+sizeof(x86r)+sizeof(iloc_offset));
  x86adressing = strcat(x86adressing, "-");
  x86adressing = strcat(x86adressing, iloc_offset);
  x86adressing = strcat(x86adressing, "(");
  x86adressing = strcat(x86adressing, x86r);
  x86adressing = strcat(x86adressing, ")");
  return x86adressing;
}

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
  int in_return_seq = 0;
  while(iloc_item != NULL)
  {
    inst* iloc_inst = iloc_item->instruction;

    char* label = NULL;
    if (iloc_inst->label && iloc_inst->label[0] != '/')
      label = iloc_inst->label;

    if (in_return_seq) // Ignore ILOC return seq.
    { 
      if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret id"))
      {
        char* src = x86Roffset(iloc_item->next->instruction->arg1, iloc_item->next->instruction->arg2);
        char* dst = x86reg(iloc_item->next->instruction->arg3);
        asm_end(&asm_code, asm_op(label, "mov", src, dst));
        asm_end(&asm_code, asm_op(label, "mov", dst, "%al"));
      }
      else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret lit"))
      {
        char* ret_val = x86lit(iloc_item->next->instruction->arg1);
        asm_end(&asm_code, asm_op(label, "mov", ret_val, "%al"));
      }
      else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret exp"))
      {
        if (last_inst_div_mul == 0) {
          char* ret_val = x86reg(iloc_item->next->instruction->arg1);
          asm_end(&asm_code, asm_op(label, "mov", ret_val, "%al"));
        }
      }
      if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .return end"))
      {
        asm_end(&asm_code, asm_op(label, "popq", "%rbp", NULL));
        asm_end(&asm_code, asm_op(label, "ret", NULL, NULL));
        in_return_seq = 0;
      }   
    } 
    else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .func begin"))
    {
      char* func_label = iloc_item->next->instruction->label;
      if (strcmp(iloc_item->next->instruction->label, "L0") == 0)
      {
        asm_end(&asm_code, asm_op("main", "pushq", "%rbp", NULL));
        asm_end(&asm_code, asm_op(label, "movq", "%rsp", "%rbp"));
      } 
      else 
      {
        asm_end(&asm_code, asm_op(func_label, "pushq", "%rbp", NULL));
        asm_end(&asm_code, asm_op(label, "movq", "%rsp", "%rbp"));
      } 
    }
    else if ((iloc_inst->label && !strcmp(iloc_inst->label, "//   .return begin")) 
            || !strcmp(iloc_inst->op, "halt"))
    {
      in_return_seq = 1;
    }
    else if (!strcmp(iloc_inst->op, "loadI"))
    {
      asm_end(&asm_code, asm_op(label, "mov", x86lit(iloc_inst->arg1), x86reg(iloc_inst->arg3)));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "storeAI"))
    {
      char* dest = x86Roffset(iloc_inst->arg3, iloc_inst->arg4);
      asm_end(&asm_code, asm_op(label, "mov", x86reg(iloc_inst->arg1), dest));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "loadAI"))
    {
      char* src = x86Roffset(iloc_inst->arg1, iloc_inst->arg2);
      char* dst = x86reg(iloc_inst->arg3);
      asm_end(&asm_code, asm_op(label, "mov", src, dst));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "add"))
    {
      char* src = x86reg(iloc_inst->arg2);
      char* dst = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "add", src, dst));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "sub"))
    {
      char* src = x86reg(iloc_inst->arg2);
      char* dst = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "sub", src, dst));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "mult"))
    {
      char* multiplier = (x86reg(iloc_inst->arg2)[0] == 'a') ? "%cl" : x86reg(iloc_inst->arg2);
      char* multiplicand = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "mov", multiplicand, "%al"));
      asm_end(&asm_code, asm_op(label, "xor", "%ah", "%ah"));
      asm_end(&asm_code, asm_op(label, "mul", multiplier, NULL));
      asm_end(&asm_code, asm_op(label, "mov", "%al", multiplicand));
      last_inst_div_mul = 1;
            
    }
    else if (!strcmp(iloc_inst->op, "div"))
    {
      char* divisor = (x86reg(iloc_inst->arg2)[0] == 'a') ? "%cl" : x86reg(iloc_inst->arg2);
      char* dividend = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "mov", dividend, "%al"));
      asm_end(&asm_code, asm_op(label, "xor", "%ah", "%ah"));
      asm_end(&asm_code, asm_op(label, "div", divisor, NULL));
      asm_end(&asm_code, asm_op(label, "mov", "%al", dividend));
      last_inst_div_mul = 1;
    }
    else if (!strcmp(iloc_inst->op, "cmp_EQ"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg1, reg2));
      asm_end(&asm_code, asm_op(label, "jne", false_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "je", true_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "cmp_NE"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg1, reg2));
      asm_end(&asm_code, asm_op(label, "jne", true_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "je", false_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "cmp_LT"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg2, reg1));
      asm_end(&asm_code, asm_op(label, "jl", true_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "jmp", false_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "cmp_GT"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg2, reg1));
      asm_end(&asm_code, asm_op(label, "jg", true_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "jmp", false_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "cmp_GE"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg1, reg2));
      asm_end(&asm_code, asm_op(label, "jle", true_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "jnle", false_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "cmp_LE"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg2);
      char* false_lbl = iloc_item->next->instruction->arg4;
      char* true_lbl = iloc_item->next->instruction->arg3;
      asm_end(&asm_code, asm_op(label, "cmp", reg1, reg2));
      asm_end(&asm_code, asm_op(label, "jge", true_lbl, NULL));
      asm_end(&asm_code, asm_op(label, "jnge", false_lbl, NULL));
    }
    else if (!strcmp(iloc_inst->op, "nop"))
    {
      asm_end(&asm_code, asm_op(label, NULL, NULL, NULL));
    }
    else if (!strcmp(iloc_inst->op, "jumpI"))
    {
      asm_end(&asm_code, asm_op(label, "jmp", iloc_inst->arg3, NULL));
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
    if (current->inst->op != NULL)
    {
      if (current->inst->src == NULL)
        printf("  %s", current->inst->op);
      else
        printf("  %s %s", current->inst->op, current->inst->src);
      if (current->inst->dst)
        printf(", %s\n", current->inst->dst);
      else
        printf("\n");
    }
    current = current->next;
  }
}