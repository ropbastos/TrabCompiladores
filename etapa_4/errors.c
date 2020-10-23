#include <stdio.h>
#include <stdlib.h>
#include "errors.h"


void syntactic_error(int error_code, char* symbol_name, int line, symbol_entry* sb)
{
  if (sb != NULL)
  {
    switch (error_code)
    {
      case ERR_DECLARED:
        switch (sb->symbol_type)
        {
          case VAR:
            fprintf(stderr, "ERROR: variable '%s' declared multiple times; first declaration on line %d.\n", sb->label, sb->line);
            break;
          case FUNC:
            fprintf(stderr, "ERROR: function '%s' defined multiple times; first definition on line %d.\n", sb->label, sb->line);
            break;
        }
      case ERR_WRONG_TYPE:
        fprintf(stderr, "ERROR: wrong type for expression being attributed to '%s' on line %d.\n", symbol_name, line);
        break;
    }
  }
  else if (line != -1)
  {
    switch (error_code)
    {
      case ERR_UNDECLARED:
        fprintf(stderr, "ERROR: undeclared symbol '%s' used on line %d.\n", symbol_name, line);
        break;
      case ERR_VARIABLE:
        fprintf(stderr, "ERROR: variable '%s' used as vector on line %d.\n", symbol_name, line);
        break;
      case ERR_VECTOR:
        fprintf(stderr, "ERROR: vector '%s' used as variable on line %d.\n", symbol_name, line);
        break;
      case ERR_FUNCTION:
        fprintf(stderr, "ERROR: function '%s' used as variable on line %d.\n", symbol_name, line);
        break;
    }
  }
  else
    fprintf(stderr, "ERROR %d\n", error_code);

  exit(error_code);
}