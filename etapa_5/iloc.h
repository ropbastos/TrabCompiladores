#ifndef ILOC_H
#define ILOC_H

enum OPCODE { load, loadAI, loadA0, loadI, add, sub, mult, div };

// ILOC TAC instruction.
typedef struct inst {
  int op;
  int arg1; // Everything is an int because it's easier to
  int arg2; // work with, and when exporting it suffices
  int arg3; // to print "L" or "r" before the numbers for 
            // register and label names.
  struct inst* prev;
  struct inst* next;
} inst;

extern int reg_num;
extern int label_num;

int label();
int reg();

#endif