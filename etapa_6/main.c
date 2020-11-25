#include <stdio.h>
#include <string.h>
#include "iloc.h"
#include "stack.h"
#include "asm.h"
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

stack* scope_stack_final = NULL;

int main (int argc, char **argv)
{
  int ret = yyparse(); 
  if (argc == 2)
  {
    if (!strcmp(argv[1], "-asm"))
      print_asm(iloc_to_asm(((node*) arvore)->code), peek(scope_stack_final));
    else if (!strcmp(argv[1], "-iloc"))
      print_code(((node*) arvore)->code);
    else if (!strcmp(argv[1], "-tree"))
      exporta(arvore);
    else
      printf("usage: ./etapa6 [-tree | -iloc | -asm] < source\n");
  } else
  {
    print_asm(iloc_to_asm(((node*) arvore)->code), peek(scope_stack_final));
  }
  libera(arvore);
  arvore = NULL;
  yylex_destroy();

  return ret;
}
