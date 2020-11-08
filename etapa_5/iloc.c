#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "iloc.h"

int reg_num = -1; 
int label_num = -1;

char* label()
{
  char* label_name;
  asprintf(&label_name,"L%d", ++label_num);
  return label_name;
};

char* reg()
{
  char* reg_name;
  asprintf(&reg_name,"r%d", ++reg_num);
  return reg_name;
};

char* arg(int arg_val)
{
  char* arg_string;
  asprintf(&arg_string,"%d", arg_val);
  return arg_string;
}

void format_arg(char** arg, char** arg_string)
{
  if (arg == NULL || *arg == NULL)
  {
    arg_string = arg;
    return;
  }
   
  *arg_string = malloc(sizeof(", ")+sizeof(*arg));
  *arg_string = strcpy(*arg_string, ", ");
  *arg_string = strcat(*arg_string, *arg);

  return;
}

inst* new_inst(char* label, char* opcode, char** arg1, char** arg2, char** arg3, char** arg4)
{
  inst* new_inst = malloc(sizeof(inst));
  new_inst->arg2 = malloc(sizeof(char**));
  new_inst->arg4 = malloc(sizeof(char**));

  new_inst->label = label;
  new_inst->op = opcode;
  
  new_inst->arg1 = arg1;
  format_arg(arg2, new_inst->arg2);
  new_inst->arg3 = arg3;
  format_arg(arg4, new_inst->arg4);
  
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

patch_list* new_patch_list()
{
  patch_list* list = malloc(sizeof(patch_list));
  list->label = NULL;
  list->next = NULL;
  return list;
};

void insert_patch(patch_list* list, char** label)
{
  if (list->label == NULL)
  {
    list->label = label;
    return;
  }

  patch_list* current = list;
  while (current->next != NULL)
  {
    current = current->next;
  }

  patch_list* new = malloc(sizeof(patch_list));
  new->label = label;
  new->next = NULL;

  current->next = new;
};

void concat_patch_list(patch_list* dst, patch_list* src)
{
  if (dst == NULL)
  {
    dst = src;
    return;
  }
  patch_list* current = dst;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = src;
}

void patch(patch_list* list, char* label)
{
  if (list == NULL)
  {
    printf("Tentando dar patch numa lista nula.\n");
    return;
  } 

  patch_list* current = list;
  do
  {
    *(current->label) = label; 
    current = current->next;
  } while (current != NULL);
}

void print_patch_list(patch_list* list)
{
  if (list->label == NULL) return;

  patch_list* current = list;
  do
  {
    printf("Label: %s\n", *(current->label));
    current = current->next;
  } while (current != NULL);
}


void print_code(inst_list_item* item)
{
  while (item != NULL)
  {
    inst* inst = item->instruction;
    
    if (inst->label != NULL)
      if (strcmp(inst->op, "nop") == 0)
        printf("%s: %s\n", inst->label, inst->op);
      else
        printf("%s: %s %s%s => %s%s\n", 
                inst->label, 
                inst->op, 
                (inst->arg1) ? *(inst->arg1) : "", 
                (inst->arg2) ? *(inst->arg2) : "", 
                (inst->arg3) ? *(inst->arg3) : "", 
                (inst->arg4) ? *(inst->arg4) : "");
    else
       if (strcmp(inst->op, "nop") == 0)
        printf("    %s\n", inst->op);
      else
        printf("    %s %s%s => %s%s\n", 
                inst->op, 
                (inst->arg1) ? *(inst->arg1) : "", 
                (inst->arg2) ? *(inst->arg2) : "", 
                (inst->arg3) ? *(inst->arg3) : "", 
                (inst->arg4) ? *(inst->arg4) : "");

    item = item->next;
  }
}
