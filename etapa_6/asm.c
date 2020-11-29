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
    return "%rbx";
  } else if (!strcmp("r1", iloc_reg))
  {
    return "%rcx";
  } else if (!strcmp("r2", iloc_reg))
  {
    return "%rdx";
  } else if (!strcmp("r3", iloc_reg))
  {
    return "%rsi";
  } else if (!strcmp("r4", iloc_reg))
  {
    return "%rdi";
  }
  else if (!strcmp("rfp", iloc_reg))
  {
    return "%rbp";
  }
  else if (!strcmp("rsp", iloc_reg))
  {
    return "%rsp";
  }
  else
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
  int offset = atoi(iloc_offset);
  offset *= 2;
  char* offst;
  asprintf(&offst, "%d", offset);
  x86adressing = malloc(sizeof("-()")+sizeof(x86r)+sizeof(offst));
  x86adressing = strcat(x86adressing, "-");
  x86adressing = strcat(x86adressing, offst);
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
  int in_call_seq = 0;
  while(iloc_item != NULL)
  {
    inst* iloc_inst = iloc_item->instruction;

    char* label = NULL;
    if (iloc_inst->label && iloc_inst->label[0] != '/')
      label = iloc_inst->label;

    if (label && label[1] == '0')
      label = "main";
    
    if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret id"))
    {
      char* src = x86Roffset(iloc_item->next->instruction->arg1, iloc_item->next->instruction->arg2);
      char* dst = x86reg(iloc_item->next->instruction->arg3);
      asm_end(&asm_code, asm_op(label, "movq", src, dst));
      asm_end(&asm_code, asm_op(label, "movq", dst, "%rax"));
    }
    else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret lit"))
    {
      char* ret_val = x86lit(iloc_item->next->instruction->arg1);
      asm_end(&asm_code, asm_op(label, "movq", ret_val, "%rax"));
    }
    else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .ret exp"))
    {
      if (last_inst_div_mul == 0) {
        char* ret_val = x86reg(iloc_item->next->instruction->arg1);
        asm_end(&asm_code, asm_op(label, "movq", ret_val, "%rax"));
      }
    }
    else if (!strcmp(iloc_inst->op, "halt"))
    {
      char* ret = x86Roffset(iloc_item->prev->instruction->arg3, iloc_item->prev->instruction->arg4);
      asm_end(&asm_code, asm_op(label, "movq", ret, "%rax"));
      asm_end(&asm_code, asm_op(label, "movq", "%rbp", "%rsp"));
      asm_end(&asm_code, asm_op(label, "popq", "%rbp", NULL));
      asm_end(&asm_code, asm_op(label, "ret", NULL, NULL));
      in_return_seq = 0;
    }
    else if (!strcmp(iloc_inst->op, "loadI"))
    {
      asm_end(&asm_code, asm_op(label, "movq", x86lit(iloc_inst->arg1), x86reg(iloc_inst->arg3)));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "storeAI"))
    {
      char* dest = x86Roffset(iloc_inst->arg3, iloc_inst->arg4);
      asm_end(&asm_code, asm_op(label, "movq", x86reg(iloc_inst->arg1), dest));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "loadAI"))
    {
      char* src = x86Roffset(iloc_inst->arg1, iloc_inst->arg2);
      char* dst = x86reg(iloc_inst->arg3);
      asm_end(&asm_code, asm_op(label, "movq", src, dst));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "add"))
    {
      char* src = x86reg(iloc_inst->arg1);
      char* dst = x86reg(iloc_inst->arg2);
      asm_end(&asm_code, asm_op(label, "addq", src, dst));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "sub"))
    {
      char* src = x86reg(iloc_inst->arg2);
      char* dst = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "subq", src, dst));
      asm_end(&asm_code, asm_op(label, "movq", dst, src));
      last_inst_div_mul = 0;
    }
    else if (!strcmp(iloc_inst->op, "mult"))
    {
      asm_end(&asm_code, asm_op(label, "imulq", x86reg(iloc_inst->arg1), x86reg(iloc_inst->arg2)));
      last_inst_div_mul = 1;      
    }
    else if (!strcmp(iloc_inst->op, "div"))
    {
      char* divisor = (x86reg(iloc_inst->arg2)[2] == 'a') ? "%ecx" : x86reg(iloc_inst->arg2);
      char* dividend = x86reg(iloc_inst->arg1);
      asm_end(&asm_code, asm_op(label, "movq", dividend, "%rax"));
      asm_end(&asm_code, asm_op(label, "cqto", NULL, NULL));
      asm_end(&asm_code, asm_op(label, "idivq", divisor, NULL));
      asm_end(&asm_code, asm_op(label, "movq", "%rax", divisor));
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
    else if (!strcmp(iloc_inst->op, "i2i"))
    {
      char* reg1 = x86reg(iloc_inst->arg1);
      char* reg2 = x86reg(iloc_inst->arg3);
      asm_end(&asm_code, asm_op(label, "movq", x86reg(iloc_inst->arg1), x86reg(iloc_inst->arg3)));
    }
    else if (!strcmp(iloc_inst->op, "addI"))
    {
      int offset = atoi(iloc_inst->arg2);
      
      if (!strcmp(iloc_inst->arg1, "rsp"))
      {
        offset *= 2;
        char* offset_;
        asprintf(&offset_, "$%d", offset);
        asm_end(&asm_code, asm_op(label, "subq", offset_, "%rsp"));
      }
      else if (!strcmp(iloc_inst->arg1, "rpc"))
      {
        // p = numero de parametros
        // 5 + 2*p = iloc_offset
        // asm: $9 por param em var, $12 por lit
        // p = (iloc_offset - 5) / 2
        // 20 32 41 50 -> offsets p/ 0, 1, 2, 3 parametros respectivamente.
        int param_num = (offset - 5) / 2;
        int lit_params = atoi(iloc_item->prev->instruction->op);
        int var_params = param_num - lit_params;
        int rip_offset = (param_num > 0) ? 23 + 9*var_params + 12*lit_params : 20;
        char* rip_offset_;
        asprintf(&rip_offset_, "$%d", rip_offset);
        asm_end(&asm_code, asm_op(label, "lea", "0(%rip)", x86reg(iloc_inst->arg3)));
        asm_end(&asm_code, asm_op(label, "addq", rip_offset_, x86reg(iloc_inst->arg3)));
      }
    }
    else if (!strcmp(iloc_inst->op, "rsubI"))
    {
      asm_end(&asm_code, asm_op(label, "neg", x86reg(iloc_inst->arg3), NULL));
    }
    else if (iloc_inst->label && !strcmp(iloc_inst->label, "//   .func begin"))
    {
      if (!strcmp(iloc_item->prev->instruction->label, "L0"))
        asm_end(&asm_code, asm_op(label, "pushq", "%rbp", NULL));
    }
    else if (!strcmp(iloc_inst->op, "jump"))
    {
      char* target = malloc(sizeof(x86reg(iloc_inst->arg3))+sizeof("*"));
      target = strcat(target, "*");
      target = strcat(target, x86reg(iloc_inst->arg3));
      asm_end(&asm_code, asm_op(label, "jmp", target, NULL));
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