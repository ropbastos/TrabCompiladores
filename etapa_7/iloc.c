#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "iloc.h"

int reg_num = -1; 
int label_num = 0;

char* label()
{
  char* label_name;
  asprintf(&label_name,"L%d", ++label_num);
  return label_name;
};

char* reg(int new_reg)
{
  char* reg_name;
  if (new_reg)
    asprintf(&reg_name,"r%d", ++reg_num%5);
  else
  {
    if (reg_num == -1) reg_num++;
    asprintf(&reg_name,"r%d", reg_num%5);
  }
  return reg_name;
};

char* arg(int arg_val)
{
  char* arg_string;
  asprintf(&arg_string,"%d", arg_val);
  return arg_string;
}

char* format_arg(char* arg)
{
  if (arg == NULL) return arg;
  
  char* arg_string;  
  arg_string = malloc(sizeof(", ")+sizeof(arg));
  arg_string = strcpy(arg_string, ", ");
  arg_string = strcat(arg_string, arg);

  return arg_string;
}

inst* new_inst(char* label, char* opcode, char* arg1, char* arg2, char* arg3, char* arg4)
{
  inst* new_inst = malloc(sizeof(inst));

  new_inst->label = (label) ? strdup(label) : NULL;
  new_inst->op = strdup(opcode);
  new_inst->arg1 = (arg1) ? strdup(arg1) : NULL;
  new_inst->arg2 = (arg2) ? strdup(arg2) : NULL;
  new_inst->arg3 = (arg3) ? strdup(arg3) : NULL;
  new_inst->arg4 = (arg4) ? strdup(arg4) : NULL;

  return new_inst;
}


void insert_start(inst_list_item** head, inst* new_inst)
{
  // Allocate node.
  inst_list_item* new_item = (inst_list_item*) malloc(sizeof(inst_list_item));

  // Put in the new instruction.
  new_item->instruction = new_inst;

  // Make next of new item as head and previous as NULL.
  new_item->next = (*head);
  new_item->prev = NULL;

  // Change prev of head item to new item.
  if ((*head) != NULL) (*head)->prev = new_item;

  // Move the head to point to the new item.
  (*head) = new_item;
}

void insert_after(inst_list_item* prev_item, inst* new_inst)
{
  // Check if the given prev item is NULL.
  if (prev_item == NULL)
  {
    printf("Previous item cannot be NULL.\n");
    return;
  }

  // Allocate new item.
  inst_list_item* new_item = (inst_list_item*) malloc(sizeof(inst_list_item));

  // Put in the new instruction.
  new_item->instruction = new_inst;

  // Make next of new item as next of previous item.
  new_item->next = prev_item->next;

  // Make the next of prev item as new item.
  prev_item->next = new_item;

  // Make prev item as prev of new item.
  new_item->prev = prev_item;

  // Change prev of new item's next.
  if (new_item->next != NULL) new_item->next->prev = new_item; 
}

void insert_end(inst_list_item** head, inst* new_inst)
{
  // Allocate new item.
  inst_list_item* new_item = malloc(sizeof(inst_list_item));

  inst_list_item* last = *head;

  // Put in the new instruction.
  new_item->instruction = new_inst;

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
}

void insert_before(inst_list_item** head, inst_list_item* next, inst* new_inst)
{
  // Check if the given next item is NULL.
  if (next == NULL)
  {
    printf("Given next item cannot be NULL.\n");
    return;
  }

  // Allocate new item.
  inst_list_item* new_item = (inst_list_item*) malloc(sizeof(inst_list_item));

  // Put in the new instruction.
  new_item->instruction = new_inst;

  // Make prev of new item as prev of next item.
  new_item->prev = next->prev;

  // Make the prev of next item as new item.
  next->prev = new_item;

  // Make next as next of new item.
  new_item->next = next;

  // Change next of new item's prev.
  if (new_item->prev != NULL)
    new_item->prev->next = new_item;
  // If the prev of new_item is NULL, it will be the new head.
  else
    (*head) = new_item;
}

void delete_item(inst_list_item** head, inst_list_item* del)
{
  if (*head == NULL || del == NULL) return;

  if (*head == del) *head = del->next;

  // Change next only if item to be deleted is NOT the last item.
  if (del->next != NULL)
    del->next->prev = del->prev;

  // Change prev only if item to be deleted is NOT the first item.
  if (del->prev != NULL)
    del->prev->next = del->next;

  free(del);
}

void concat_end(inst_list_item** dst_list, inst_list_item* src_list)
{
  if (*dst_list == NULL)
  {
    *dst_list = src_list;
    return;
  }

  inst_list_item* current = *dst_list;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = src_list;
}

void print_code(inst_list_item* item)
{
  printf("     loadI 1024 => rfp\n");
  printf("     loadI 1024 => rsp\n");

  int inst_num = count_instructions(item);
  printf("     loadI %d => rbss\n", inst_num + 4);
  printf("     jumpI => L0\n");

  while (item != NULL)
  {
    inst* inst = item->instruction;

    // label: opcode arg1[, arg2] => arg3[, arg4] 
    char* label = "    ";
    char* op = inst->op;
    char* arg1 = (inst->arg1) ? inst->arg1 : "";
    char* arg2 = (inst->arg2) ? format_arg(inst->arg2) : "";
    char* arg3 = (inst->arg3) ? inst->arg3 : "";
    char* arg4 = (inst->arg4) ? format_arg(inst->arg4) : "";

    char* formatted_label;
    if (inst->label)
    {
      label = inst->label;
      formatted_label = malloc(sizeof(label)+sizeof(": "));
      formatted_label = strcpy(formatted_label, label);
      if (label[0] != '/')
        formatted_label = strcat(formatted_label, ": ");
      label = formatted_label;
    }

    if (strcmp(op, "nop") == 0)
      printf("%s nop\n", label);
    else if (strcmp(op, "halt") == 0)
      printf("%s halt\n", label);
    else if (label && label[0] == '/') // "Compiler directives" as ILOC comments.
      printf("%s %s\n", label, op);
    else
      printf("%s %s %s%s => %s%s\n", label, op, arg1, arg2, arg3, arg4);

    item = item->next;
  }
}

int count_instructions(inst_list_item* code)
{
  int inst_num = 0;

  while (code != NULL)
  {
    inst_num++;
    code = code->next;
  }

  return inst_num;
}


// Backpatching.

char* hole()
{
  char* new_hole;
  new_hole = NULL;
  return new_hole;
}

hole_list* new_hole_list(char** hole)
{
  hole_list* new_list = malloc(sizeof(hole_list));
  new_list->label = hole;
  new_list->next = NULL;

  return new_list;
}

void hole_list_cat(hole_list** dst, hole_list** src)
{
  if(*src == NULL)
  {
    return;
  }
  if (*dst == NULL)
  {
    *dst = *src;
    return;
  }

  hole_list* current = *dst;
  while (current->next != NULL)
    current = current->next;

  current->next = *src;
}

void patch(hole_list* list, char* label)
{
  if (list == NULL) return;
  if (label == NULL) return;

  hole_list* current = list;
  while (current != NULL)
  {
    *(current->label) = label;
    current = current->next;
  };
}

void print_hole_list(hole_list* list)
{
  if (list == NULL) return;

  hole_list* current = list;
  while(current != NULL)
  {
    printf("Label: %s\n", *(current->label));
    current = current->next;
  };
}

int hole_list_len(hole_list* list)
{
  int len = 0;
  if (list == NULL) return len;

  hole_list* current = list;
  while (current != NULL) 
  {
    len++;
    current = current->next;
  }
  return len;
}


