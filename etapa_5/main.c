/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
#include <stdio.h>
#include "iloc.h"
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

int main (int argc, char **argv)
{
  int ret = yyparse(); 
  //exporta (arvore);
  libera(arvore);
  arvore = NULL;
  yylex_destroy();
  
  // Testing code generation/export.
  // inst_list_item* head = NULL;
  // inst* inst1 = new_inst(NULL, "sub", reg(), reg(), reg(), NULL);
  // inst* inst2 = new_inst(label(), "loadI", arg(73), NULL, reg(), NULL);
  // inst* inst3 = new_inst(label(), "store", reg(), NULL, reg(), NULL);

  // insert_start(&head, inst1);
  // insert_end(&head, inst2);
  // insert_after(head, inst3);
  // print_code(head);

  // patch_list* teste = new_patch_list();
  //char* label1 = "streng1";
  //char* label2 = "streng2";
  //printf("label1: %s\n", label1);
  //printf("label2: %s\n", label2);
  // char* hole1;
  // char* hole2;
  // insert_patch(teste, &hole1);
  // insert_patch(teste, &hole2);
  // char* label = "lenda";
  // patch(teste, label);
  // print_patch_list(teste);
  //printf("Vou modificar:\n");
  //*(teste->label) = "lol";
  //print_patch_list(teste);
  //printf("Na var label1: %s", label1);
  

  return ret;
}
