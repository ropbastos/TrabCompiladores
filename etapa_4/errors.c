#include <stdio.h>
#include "errors.h"

void syntactic_error(int error_code)
{
  fprintf(stderr, "ERRO: %d\n", error_code);
}