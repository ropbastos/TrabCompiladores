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

  char* hole1 = "HOLE";
  char* hole2 = "HOLE";
  hole_list* test_list = new_hole_list(&hole1);
  hole_list_cat(test_list, new_hole_list(&hole2));
  char* tst_lbl = label();
  printf("Holes being patched with: %s\n", tst_lbl);
  patch(test_list, tst_lbl);
  print_hole_list(test_list);

  return ret;
}
