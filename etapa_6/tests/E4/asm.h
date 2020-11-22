#ifndef ASM_H
#define ASM_H

typedef struct asm_inst {
  char* label;
  char* op;
  char* arg1;
  char* arg2; 
  char* arg3; 
} asm_inst;

typedef struct inst_list_item {
  inst* instruction;
  struct inst_list_item* prev;
  struct inst_list_item* next;
} inst_list_item;

#endif