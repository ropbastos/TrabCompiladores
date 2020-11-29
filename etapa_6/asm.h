#ifndef ASM_H
#define ASM_H
#include "iloc.h"
#include "stack.h"

typedef struct asm_inst {
  char* lbl;
  char* op;
  char* src;
  char* dst; 
} asm_inst;

typedef struct asm_inst_list_item {
  asm_inst* inst;
  struct asm_inst_list_item* prev;
  struct asm_inst_list_item* next;
} asm_inst_list_item;

asm_inst* asm_op(char* lbl, char* op, char* src, char* dst);
void asm_start(asm_inst_list_item** head, asm_inst* new_inst);
void asm_end(asm_inst_list_item** head, asm_inst* new_inst);
void asm_cat(asm_inst_list_item** dst_list, asm_inst_list_item* src_list);

extern int reg_num;
extern int label_num;

char* x86label();
char* x86reg(char* iloc_reg);
char* x86lit(char* iloc_lit);
char* x86global(char* global_name);
char* x86Roffset(char* iloc_reg, char* iloc_offset);

asm_inst_list_item* iloc_to_asm(inst_list_item* iloc);
void asm_print_globals(ht_entry** table);
void print_asm(asm_inst_list_item* asm_code, symb_table* scope);

#endif