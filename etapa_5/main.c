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
  inst_list_item* head = NULL;
  inst* inst1 = new_inst(load, 1, 2, 3);
  inst* inst2 = new_inst(add, 1, 2, 3);
  inst* inst3 = new_inst(store, 1, 2, 3);

  insert_start(&head, inst1);
  insert_end(&head, inst2);
  insert_after(head, inst3);
  print_code(head);

  return ret;
}
