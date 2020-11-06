#ifndef ILOC_H
#define ILOC_H

enum OPCODE { load, loadAI, loadA0, loadI, store, storeAI, jumpI, jump,
i2i, add, addI, sub, subI, mult, multI, div_, divI, halt };

// ILOC TAC instruction.
typedef struct inst {
  int op;
  int arg1; // Everything is an int because it's easier to
  int arg2; // work with, and when exporting it suffices
  int arg3; // to print "L" or "r" before the numbers for 
            // register and label names.
} inst;

typedef struct inst_list_item {
  inst* instruction;
  struct inst_list_item* prev;
  struct inst_list_item* next;
} inst_list_item;

inst* new_inst(int opcode, int arg1, int arg2, int arg3);

void insert_start(inst_list_item** head, inst* new_inst);
void insert_end(inst_list_item** head, inst* new_inst);
void insert_after(inst_list_item* prev_item, inst* new_inst);
void insert_before(inst_list_item** head, inst_list_item* next, inst* new_inst);
void delete_item(inst_list_item** head, inst_list_item* del);

void print_code(inst_list_item* item);


extern int reg_num;
extern int label_num;

int label();
int reg();

#endif