#include "iloc.h"

int reg_num = -1;
int label_num = -1;

int label()
{
  return ++label_num;
};

int reg()
{
  return ++reg_num;
};