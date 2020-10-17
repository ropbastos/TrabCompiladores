/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
#include <stdio.h>
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  printf("SAIU DE EXPORTA\n");
  libera(arvore);
  printf("SAIU DE LIBERA\n");
  arvore = NULL;
  printf("NULLOU ARVORE\n");
  yylex_destroy();
  printf("SAIU YYLEX_DESTROY()\n");
  return ret;
}
