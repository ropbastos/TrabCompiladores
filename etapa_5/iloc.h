#ifndef ILOC_H
#define ILOC_H

// ILOC TAC instruction.
typedef struct inst {
  char* label;
  char* op;
  char* arg1;
  char* arg2; 
  char* arg3; 
  char* arg4;
} inst;

typedef struct inst_list_item {
  inst* instruction;
  struct inst_list_item* prev;
  struct inst_list_item* next;
} inst_list_item;

// label: opcode arg1[, arg2] => arg3[, arg4] 
inst* new_inst(char* label, char* opcode, char* arg1, char* arg2, char* arg3, char* arg4);

void insert_start(inst_list_item** head, inst* new_inst);
void insert_end(inst_list_item** head, inst* new_inst);
void insert_after(inst_list_item* prev_item, inst* new_inst);
void insert_before(inst_list_item** head, inst_list_item* next, inst* new_inst);
void delete_item(inst_list_item** head, inst_list_item* del);

void print_code(inst_list_item* item);


extern int reg_num;
extern int label_num;

char* label();
char* reg();
char* arg(int arg_val);

#endif