#include <stdio.h>
#include <stdlib.h>
#include "errors.h"


void syntactic_error(int error_code, int line, symbol_entry* sb)
{
  if (sb != NULL)
  {
    switch (error_code)
    {
      case ERR_DECLARED:
        fprintf(stderr, "ERROR: symbol '%s' declared multiple times; first declaration on line %d.\n", sb->label, sb->line);
        exit(error_code);
    }
  }
  else if (line != -1)
    fprintf(stderr, "ERROR %d on line %d\n", error_code, line);
  else
    fprintf(stderr, "ERROR %d\n", error_code);
}