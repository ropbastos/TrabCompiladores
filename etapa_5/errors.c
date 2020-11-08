#include <stdio.h>
#include <stdlib.h>
#include "errors.h"


void syntactic_error(int error_code, char* symbol_name, int line, symbol_entry* sb)
{
  //exit(error_code); // Remove that line to see error messages.
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
        break;
      case ERR_WRONG_TYPE:
        fprintf(stderr, "ERROR: wrong type for expression being attributed to '%s' on line %d.\n", symbol_name, line);
        break;
      case ERR_CHAR_TO_X:
        fprintf(stderr, "ERROR: char '%s' used as non-char type on line %d.\n", symbol_name, line);
        break;
      case ERR_STRING_TO_X:
        fprintf(stderr, "ERROR: string '%s' used as non-string type on line %d.\n", symbol_name, line);
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
        fprintf(stderr, "ERROR: variable '%s' used as vector/function on line %d.\n", symbol_name, line);
        break;
      case ERR_VECTOR:
        fprintf(stderr, "ERROR: vector '%s' used as variable/function on line %d.\n", symbol_name, line);
        break;
      case ERR_FUNCTION:
        fprintf(stderr, "ERROR: function '%s' used as variable/vector on line %d.\n", symbol_name, line);
        break;
      case ERR_MISSING_ARGS:
        fprintf(stderr, "ERROR: function '%s' is missing args on line %d.\n", symbol_name, line);
        break;
      case ERR_EXCESS_ARGS:
        fprintf(stderr, "ERROR: function '%s' has excess args on line %d.\n", symbol_name, line);
        break;
      case ERR_WRONG_TYPE_ARGS:
        fprintf(stderr, "ERROR: function '%s' has wrong type args on line %d.\n", symbol_name, line);
        break;
      case ERR_WRONG_PAR_INPUT:
        fprintf(stderr, "ERROR: 'input' command has wrong type paramater on line %d (expects INT or FLOAT).\n", line);
        break;
      case ERR_WRONG_PAR_OUTPUT:
        fprintf(stderr, "ERROR: 'output' command has wrong type paramater on line %d (expects INT or FLOAT).\n", line);
        break;
      case ERR_WRONG_PAR_SHIFT:
        fprintf(stderr, "ERROR: 'shift' command's argument is too big on line %d (number should not be greater than 16).\n", line);
        break;
      case ERR_WRONG_PAR_RETURN:
        fprintf(stderr, "ERROR: function '%s' has incompatible return type on line %d.\n", symbol_name, line);
        break;
      case ERR_CHAR_TO_X:
        fprintf(stderr, "ERROR: char '%s' used as non-char type on line %d.\n", symbol_name, line);
        break;
      case ERR_STRING_TO_X:
        fprintf(stderr, "ERROR: string '%s' used as non-string type on line %d.\n", symbol_name, line);
        break;
      case ERR_WRONG_TYPE:
        fprintf(stderr, "ERROR: wrong type for expression being attributed to '%s' on line %d.\n", symbol_name, line);
        break;
      case ERR_STRING_SIZE:
        fprintf(stderr, "ERROR: string '%s' is too small on line %d.\n", symbol_name, line);
        break;
    }
  }
  else
    fprintf(stderr, "ERROR %d\n", error_code);

  exit(error_code);
}