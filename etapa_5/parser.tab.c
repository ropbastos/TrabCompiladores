/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_helper.h"
#include "iloc.h"
int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();

extern void* arvore;
stack* scope_stack = NULL;
extern int return_line;
extern int expected_return_type;
extern int return_type_is_correct;
extern int prev_offset;

inst_list_item* head = NULL;

// typedef struct prod_val {
//   struct node* ast_node;
//   struct id_list_item* id_list;
//   struct arg_list_item* arg_list;
// } prod;

#line 97 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_PR_END = 283,
    TK_PR_DEFAULT = 284,
    TK_OC_LE = 285,
    TK_OC_GE = 286,
    TK_OC_EQ = 287,
    TK_OC_NE = 288,
    TK_OC_AND = 289,
    TK_OC_OR = 290,
    TK_OC_SL = 291,
    TK_OC_SR = 292,
    TK_OC_FORWARD_PIPE = 293,
    TK_OC_BASH_PIPE = 294,
    TK_LIT_INT = 295,
    TK_LIT_FLOAT = 296,
    TK_LIT_FALSE = 297,
    TK_LIT_TRUE = 298,
    TK_LIT_CHAR = 299,
    TK_LIT_STRING = 300,
    TK_IDENTIFICADOR = 301,
    TOKEN_ERRO = 302,
    TERNARY = 303,
    UNARY = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

  struct lex_val* lex_val;
  struct node* node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
  struct prod_val* prod;
  int type;

#line 208 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   628

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,     2,    60,    53,     2,
      67,    68,    58,    56,    48,    57,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    64,
      55,    49,    54,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    52,    70,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   151,   152,   156,   172,   188,   206,   210,
     214,   218,   223,   228,   236,   237,   238,   239,   240,   244,
     250,   264,   277,   293,   310,   323,   339,   344,   348,   353,
     360,   363,   368,   380,   387,   388,   395,   399,   406,   410,
     417,   421,   432,   445,   461,   478,   495,   512,   532,   538,
     545,   566,   584,   600,   617,   626,   635,   644,   653,   662,
     674,   720,   734,   748,   762,   779,   833,   868,   907,   920,
     928,   936,   944,   952,   960,   968,   976,   987,   999,  1000,
    1004,  1005,  1006,  1010,  1017,  1027,  1037,  1047,  1074,  1101,
    1102,  1107,  1111,  1112,  1120,  1130,  1139,  1148,  1157,  1162,
    1167,  1172,  1177,  1185,  1193,  1201,  1209,  1217,  1225,  1233,
    1241,  1252,  1270,  1293,  1306,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1333,  1334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_PR_END", "TK_PR_DEFAULT", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_SL", "TK_OC_SR",
  "TK_OC_FORWARD_PIPE", "TK_OC_BASH_PIPE", "TK_LIT_INT", "TK_LIT_FLOAT",
  "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_LIT_STRING",
  "TK_IDENTIFICADOR", "TOKEN_ERRO", "','", "'='", "'?'", "':'", "'|'",
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "TERNARY",
  "UNARY", "';'", "'['", "']'", "'('", "')'", "'{'", "'}'", "'!'", "'#'",
  "$accept", "root", "program", "global_decl", "global_list", "type",
  "func2", "func", "header2", "header", "params", "body", "block_start",
  "block_end", "block", "cmds", "local_decl", "local_list", "literal",
  "attrib", "io", "func_call", "exp_list", "shift", "jmp_stmt", "control",
  "if", "for", "while", "exp", "lit_exp", "unary", "bool", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    44,    61,
      63,    58,   124,    38,    62,    60,    43,    45,    42,    47,
      37,    94,   303,   304,    59,    91,    93,    40,    41,   123,
     125,    33,    35
};
# endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,  -166,  -166,  -166,  -166,  -166,   101,    25,  -166,    77,
     -28,    77,   -31,   214,   -15,    29,  -166,  -166,   -44,    12,
    -166,  -166,  -166,    26,    43,    39,   252,   420,   101,   249,
      44,  -166,  -166,   -23,  -166,    46,  -166,   214,    48,  -166,
      49,    72,    73,    74,    85,    92,   147,  -166,  -166,  -166,
    -166,   -32,    93,   113,   -25,   170,  -166,   420,   420,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,   -48,  -166,  -166,  -166,  -166,  -166,
     420,  -166,  -166,  -166,   525,  -166,   420,  -166,    46,   101,
      46,   119,    -4,     3,   420,   420,   420,   -18,  -166,   -31,
     214,   214,   214,   214,   214,   214,   214,   214,  -166,   175,
    -166,   -38,  -166,     5,   127,   101,  -166,   122,   104,   216,
     255,   420,   287,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
    -166,  -166,    46,  -166,     4,   132,  -166,   144,  -166,   145,
     525,   319,   121,   449,   352,    46,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,   126,   142,   129,   157,
     156,  -166,   -15,   194,   356,  -166,   343,   141,     7,     7,
     567,   535,   481,   271,   303,   141,   343,   -12,   -12,  -166,
    -166,  -166,  -166,  -166,   420,   420,  -166,  -166,    54,  -166,
     420,   159,   164,  -166,  -166,   113,   165,   166,   275,   205,
     -15,  -166,   420,   393,   493,    16,    18,   420,  -166,    46,
      46,  -166,   113,   275,  -166,   -15,  -166,  -166,   177,   119,
    -166,   184,  -166,   192,   525,  -166,  -166,  -166,  -166,  -166,
     167,  -166,  -166,   -15,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    14,    15,    16,    17,    18,     0,     0,     2,     3,
       0,     3,     0,    34,     0,     0,     1,     4,     8,     0,
       5,    32,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     0,    31,     0,    20,    34,     0,    30,
       0,     0,     0,     0,     0,     0,    34,    80,    81,    82,
      21,     8,     0,     0,     0,     0,     6,     0,     0,    62,
      57,    56,    55,    59,    54,    58,    63,    64,   112,   111,
     122,   123,   113,   114,    87,   120,   118,   115,   116,   119,
       0,   117,   121,    91,    77,    89,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    48,    44,     0,
      34,    34,    34,    34,    34,    34,    34,    34,    43,     0,
       7,     8,    11,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    45,     0,    47,     0,     0,    69,     0,    70,     0,
      60,     0,     0,    66,     0,     0,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    24,     0,     9,     0,     0,
      27,    23,     0,     0,     0,    92,   107,   106,   105,   108,
     104,   109,     0,   100,   101,   103,   102,    94,    95,    96,
      97,    98,    99,    46,     0,     0,    71,    72,     0,    65,
      68,    50,    51,    49,    25,     0,    10,    29,     0,    83,
       0,    88,     0,     0,     0,     0,     0,     0,    67,     0,
       0,    12,     0,     0,    26,     0,    86,   110,     0,     0,
      73,     0,    74,     0,    61,    52,    53,    13,    28,    84,
       0,    75,    76,     0,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,    13,  -166,   -13,     0,  -166,  -166,  -166,  -166,
     -75,  -166,   220,   140,  -165,    40,  -166,   -85,    86,   -90,
    -166,    -5,    41,  -166,  -166,  -166,  -166,  -166,  -166,    -7,
    -166,  -166,  -166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    19,    35,    11,    12,    13,    14,
     118,    36,    37,    22,    38,    39,    40,    98,    67,    41,
      42,    83,   152,    44,    45,    46,    47,    48,    49,   153,
      85,    86,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,   145,    52,   141,    53,   143,    15,   209,    43,    10,
      53,    10,   154,    92,    93,   113,    53,   121,    18,    96,
      84,    54,    17,    55,    20,    16,    94,    54,    88,    90,
     155,   114,    43,    54,   166,   109,   146,   123,   124,    21,
     112,    43,    95,   148,    96,   226,   136,   137,   138,   139,
     119,   120,   147,    94,    34,   117,   230,   193,   232,   149,
     239,   132,   133,   134,   135,   136,   137,   138,   139,   194,
     203,   167,   231,   122,   233,    51,    56,    99,   244,   140,
       1,     2,     3,     4,     5,    59,   108,   150,   151,   142,
     215,   216,    97,    57,     6,    43,    43,    43,    43,    43,
      43,    43,    43,   217,     1,     2,     3,     4,     5,   117,
      58,    91,   100,   101,   174,   169,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   224,   235,   236,   102,   103,   104,   240,
     157,   158,   159,   160,   161,   162,   163,   164,   238,   105,
       1,     2,     3,     4,     5,    23,   106,   110,    24,   111,
      25,    26,    27,    28,    29,   144,    30,   168,   170,    31,
      32,   123,   171,     1,     2,     3,     4,     5,     1,     2,
       3,     4,     5,   195,   196,   197,   115,   213,   214,   199,
     205,   115,   221,    33,   204,   206,   133,   134,   135,   136,
     137,   138,   139,   207,   208,   227,   210,   219,   117,   237,
     234,   107,   220,   222,   223,   225,    34,     1,     2,     3,
       4,     5,    23,   117,   241,    24,   217,    25,    26,    27,
      28,    29,   242,    30,    50,   243,    31,    32,   116,   156,
     202,   218,     0,   165,     0,     0,   123,   124,   125,   126,
     127,   128,     1,     2,     3,     4,     5,     0,     0,     0,
      33,     0,     0,     0,     0,    89,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     1,     2,
       3,     4,     5,    34,   172,   123,   124,   125,   126,   127,
     128,   115,    60,    61,    62,    63,    64,    65,    66,     0,
       0,   123,   124,   125,   126,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   123,   124,   125,
     126,   127,   128,   173,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   123,   124,   125,   126,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   123,
     124,   125,   126,   127,   128,   175,     0,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,     0,   198,   123,   124,   125,   126,
     127,   128,    60,    61,    62,    63,    64,    65,   201,   134,
     135,   136,   137,   138,   139,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,   211,   123,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,     0,   228,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
      75,     0,     0,    76,     0,     0,    77,    78,    79,   123,
     124,   125,   126,   127,   128,     0,     0,    80,     0,     0,
       0,    81,    82,     0,     0,     0,     0,   200,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   123,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,   123,   124,   125,   126,   127,   128,     0,
       0,   129,   212,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   129,   229,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   123,   124,   125,   126,   127,
     128,     0,     0,     0,     0,   123,   124,   125,   126,   127,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139
};

static const yytype_int16 yycheck[] =
{
       0,    91,    15,    88,    48,    90,     6,   172,    13,     9,
      48,    11,    30,    36,    37,    40,    48,    65,    46,    67,
      27,    65,     9,    67,    11,     0,    49,    65,    28,    29,
      48,    56,    37,    65,   109,    67,    40,    30,    31,    70,
      53,    46,    65,    40,    67,   210,    58,    59,    60,    61,
      57,    58,    56,    49,    69,    55,    40,   142,    40,    56,
     225,    54,    55,    56,    57,    58,    59,    60,    61,    65,
     155,    66,    56,    80,    56,    46,    64,    37,   243,    86,
       3,     4,     5,     6,     7,    46,    46,    94,    95,    89,
      36,    37,    46,    67,    17,   100,   101,   102,   103,   104,
     105,   106,   107,    49,     3,     4,     5,     6,     7,   109,
      67,    67,    64,    64,   121,   115,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   208,   219,   220,    64,    64,    64,   229,
     100,   101,   102,   103,   104,   105,   106,   107,   223,    64,
       3,     4,     5,     6,     7,     8,    64,    64,    11,    46,
      13,    14,    15,    16,    17,    46,    19,    40,    46,    22,
      23,    30,    68,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    51,    40,    40,    16,   194,   195,    68,
      48,    16,   205,    46,    68,    66,    55,    56,    57,    58,
      59,    60,    61,    46,    48,   212,    12,    48,   208,   222,
     217,    64,    48,    48,    48,    10,    69,     3,     4,     5,
       6,     7,     8,   223,    40,    11,    49,    13,    14,    15,
      16,    17,    40,    19,    14,    68,    22,    23,    68,    99,
     154,   200,    -1,    68,    -1,    -1,    30,    31,    32,    33,
      34,    35,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    16,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     3,     4,
       5,     6,     7,    69,    68,    30,    31,    32,    33,    34,
      35,    16,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    30,    31,    32,    33,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    30,    31,    32,
      33,    34,    35,    68,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    30,    31,    32,    33,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    30,
      31,    32,    33,    34,    35,    68,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    30,    31,    32,    33,
      34,    35,    40,    41,    42,    43,    44,    45,    46,    56,
      57,    58,    59,    60,    61,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    30,
      31,    32,    33,    34,    35,    -1,    -1,    67,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    74,    75,    76,
      78,    79,    80,    81,    82,    78,     0,    75,    46,    77,
      75,    70,    86,     8,    11,    13,    14,    15,    16,    17,
      19,    22,    23,    46,    69,    78,    84,    85,    87,    88,
      89,    92,    93,    94,    96,    97,    98,    99,   100,   101,
      85,    46,    77,    48,    65,    67,    64,    67,    67,    46,
      40,    41,    42,    43,    44,    45,    46,    91,    40,    41,
      42,    43,    44,    45,    46,    50,    53,    56,    57,    58,
      67,    71,    72,    94,   102,   103,   104,   105,    78,    16,
      78,    67,    36,    37,    49,    65,    67,    46,    90,    88,
      64,    64,    64,    64,    64,    64,    64,    64,    88,    67,
      64,    46,    77,    40,    56,    16,    68,    78,    83,   102,
     102,    65,   102,    30,    31,    32,    33,    34,    35,    50,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     102,    90,    78,    90,    46,    92,    40,    56,    40,    56,
     102,   102,    95,   102,    30,    48,    86,    88,    88,    88,
      88,    88,    88,    88,    88,    68,    83,    66,    40,    78,
      46,    68,    68,    68,   102,    68,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,    90,    65,    51,    40,    40,    66,    68,
      48,    46,    91,    90,    68,    48,    66,    46,    48,    87,
      12,    66,    51,   102,   102,    36,    37,    49,    95,    48,
      48,    77,    48,    48,    83,    10,    87,   102,    66,    51,
      40,    56,    40,    56,   102,    90,    90,    77,    83,    87,
      92,    40,    40,    68,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      80,    81,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    85,    86,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    93,    93,    93,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     3,     4,     1,     4,
       5,     3,     6,     7,     1,     1,     1,     1,     1,     2,
       2,     2,     4,     5,     5,     6,     4,     2,     5,     3,
       1,     1,     1,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     4,     3,     1,     3,
       3,     3,     5,     5,     1,     1,     1,     1,     1,     1,
       3,     6,     2,     2,     2,     4,     1,     3,     0,     3,
       3,     4,     4,     6,     6,     7,     7,     2,     1,     1,
       1,     1,     1,     5,     7,     9,     6,     1,     4,     1,
       1,     1,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 148 "parser.y"
              { arvore = (yyvsp[0].node); print_code((yyvsp[0].node)->code); }
#line 1636 "parser.tab.c"
    break;

  case 3:
#line 151 "parser.y"
           { (yyval.node) = NULL; }
#line 1642 "parser.tab.c"
    break;

  case 4:
#line 153 "parser.y"
    { 
      if ((yyvsp[0].node) != NULL) (yyval.node) = (yyvsp[0].node); else (yyval.node) = NULL; 
    }
#line 1650 "parser.tab.c"
    break;

  case 5:
#line 157 "parser.y"
    { 
      (yyval.node) = (yyvsp[-1].node);
      add_children((yyval.node), 1, (yyvsp[0].node));

      if ((yyvsp[0].node) != NULL)
      {
        if ((yyvsp[0].node)->code != NULL)
        {
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
        }
      }
    }
#line 1667 "parser.tab.c"
    break;

  case 6:
#line 173 "parser.y"
    {
      // Find global scope.
      symb_table* global_scope = pop(&scope_stack);
      if (global_scope == NULL)
      {
        // Create new global scope symbol table if one doesn't already exist.
        global_scope = symbol_table(0);
        global_scope->is_global = 1;
      }

      add_variables_to_scope((yyvsp[-2].type), (yyvsp[-1].id_list), global_scope);

      // Stack global sb table.
      push(&scope_stack, global_scope);
    }
#line 1687 "parser.tab.c"
    break;

  case 7:
#line 189 "parser.y"
    {
      // Find global scope.
      symb_table* global_scope = pop(&scope_stack);
      if (global_scope == NULL)
      {
        // Create new global scope symbol table if one doesn't already exist.
        global_scope = symbol_table(0);
      }

      add_variables_to_scope((yyvsp[-2].type), (yyvsp[-1].id_list), global_scope);

      // Stack global sb table.
      push(&scope_stack, global_scope);
    }
#line 1706 "parser.tab.c"
    break;

  case 8:
#line 207 "parser.y"
    { 
      (yyval.id_list) = new_id_list((yyvsp[0].lex_val), NOT_A_VECTOR);
    }
#line 1714 "parser.tab.c"
    break;

  case 9:
#line 211 "parser.y"
    { 
      (yyval.id_list) = new_id_list((yyvsp[-3].lex_val), (yyvsp[-1].lex_val)->value.i);
    }
#line 1722 "parser.tab.c"
    break;

  case 10:
#line 215 "parser.y"
    { 
      (yyval.id_list) = new_id_list((yyvsp[-4].lex_val), (yyvsp[-1].lex_val)->value.i);
    }
#line 1730 "parser.tab.c"
    break;

  case 11:
#line 219 "parser.y"
    { 
      add_id(&(yyvsp[0].id_list), (yyvsp[-2].lex_val), NOT_A_VECTOR, NOT_A_STRING, NOT_INITIALIZED); 
      (yyval.id_list) = (yyvsp[0].id_list); 
    }
#line 1739 "parser.tab.c"
    break;

  case 12:
#line 224 "parser.y"
    { 
      add_id(&(yyvsp[0].id_list), (yyvsp[-5].lex_val), (yyvsp[-3].lex_val)->value.i, NOT_A_STRING, NOT_INITIALIZED); 
      (yyval.id_list) = (yyvsp[0].id_list); 
    }
#line 1748 "parser.tab.c"
    break;

  case 13:
#line 229 "parser.y"
    { 
      add_id(&(yyvsp[0].id_list), (yyvsp[-6].lex_val), (yyvsp[-3].lex_val)->value.i, NOT_A_STRING, NOT_INITIALIZED); 
      (yyval.id_list) = (yyvsp[0].id_list); 
    }
#line 1757 "parser.tab.c"
    break;

  case 14:
#line 236 "parser.y"
              { (yyval.type) = INT; }
#line 1763 "parser.tab.c"
    break;

  case 15:
#line 237 "parser.y"
                { (yyval.type) = FLOAT; }
#line 1769 "parser.tab.c"
    break;

  case 16:
#line 238 "parser.y"
               { (yyval.type) = BOOL; }
#line 1775 "parser.tab.c"
    break;

  case 17:
#line 239 "parser.y"
               { (yyval.type) = CHAR; }
#line 1781 "parser.tab.c"
    break;

  case 18:
#line 240 "parser.y"
                 { (yyval.type) = STR; }
#line 1787 "parser.tab.c"
    break;

  case 19:
#line 245 "parser.y"
    {
      (yyval.node) = (yyvsp[-1].node);
    }
#line 1795 "parser.tab.c"
    break;

  case 20:
#line 251 "parser.y"
    {
      expected_return_type = (yyvsp[-1].node)->data_type;
      check_return_type((yyvsp[0].node));
      if (!return_type_is_correct)
      {
        syntactic_error(ERR_WRONG_PAR_RETURN, (yyvsp[-1].node)->label, return_line, NULL);
      } 
      (yyval.node) = (yyvsp[-1].node); if ((yyvsp[0].node) != NULL) add_children((yyval.node), 1, (yyvsp[0].node)); 
      gen_func_code((yyval.node), (yyvsp[0].node), prev_offset, peek(scope_stack), scope_stack);
    }
#line 1810 "parser.tab.c"
    break;

  case 21:
#line 265 "parser.y"
    {
      (yyval.node) = (yyvsp[-1].node);

      symbol_entry* func = st_lookup((yyvsp[-1].node)->label, scope_stack);
      symb_table* scope = pop(&scope_stack);

      add_args_to_scope(scope, func->args); // Did that work?

      push(&scope_stack, scope);
    }
#line 1825 "parser.tab.c"
    break;

  case 22:
#line 278 "parser.y"
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
      {
        scope = symbol_table(0);
        scope->is_global = 1;
      }

      add_functions_to_scope((yyvsp[-3].type), (yyvsp[-2].lex_val), NULL, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); (yyval.node)->data_type = (yyvsp[-3].type);
    }
#line 1845 "parser.tab.c"
    break;

  case 23:
#line 294 "parser.y"
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
      {
        scope = symbol_table(0);
        scope->is_global = 1;
      }

      add_functions_to_scope((yyvsp[-4].type), (yyvsp[-3].lex_val), (yyvsp[-1].arg_list), scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      (yyval.node) = lexval_node((yyvsp[-3].lex_val)); (yyval.node)->data_type = (yyvsp[-4].type); 

    }
#line 1866 "parser.tab.c"
    break;

  case 24:
#line 311 "parser.y"
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope((yyvsp[-3].type), (yyvsp[-2].lex_val), NULL, scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      (yyval.node) = lexval_node((yyvsp[-2].lex_val));  (yyval.node)->data_type = (yyvsp[-3].type); 
    }
#line 1883 "parser.tab.c"
    break;

  case 25:
#line 324 "parser.y"
    { 
      symb_table* scope = pop(&scope_stack);
      if (scope == NULL)
        scope = symbol_table(0);

      add_functions_to_scope((yyvsp[-4].type), (yyvsp[-3].lex_val), (yyvsp[-1].arg_list), scope);

      // Re-stack scope.
      push(&scope_stack, scope);

      (yyval.node) = lexval_node((yyvsp[-3].lex_val));  (yyval.node)->data_type = (yyvsp[-4].type); 
    }
#line 1900 "parser.tab.c"
    break;

  case 26:
#line 340 "parser.y"
    {
      add_arg((yyvsp[0].arg_list), (yyvsp[-2].lex_val), (yyvsp[-3].type));
      (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 1909 "parser.tab.c"
    break;

  case 27:
#line 345 "parser.y"
    {
      (yyval.arg_list) = new_arg_list((yyvsp[-1].type), (yyvsp[0].lex_val));
    }
#line 1917 "parser.tab.c"
    break;

  case 28:
#line 349 "parser.y"
    {
      add_arg((yyvsp[0].arg_list), (yyvsp[-2].lex_val), (yyvsp[-3].type));
      (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 1926 "parser.tab.c"
    break;

  case 29:
#line 354 "parser.y"
    {
      (yyval.arg_list) = new_arg_list((yyvsp[-1].type), (yyvsp[0].lex_val));
    }
#line 1934 "parser.tab.c"
    break;

  case 30:
#line 360 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1940 "parser.tab.c"
    break;

  case 31:
#line 364 "parser.y"
{ 
  push(&scope_stack,
    (peek(scope_stack)->is_global) ? symbol_table(20) : symbol_table(peek(scope_stack)->offset));  
}
#line 1949 "parser.tab.c"
    break;

  case 32:
#line 369 "parser.y"
{ 
  int offset_to_inherit = peek(scope_stack)->offset; 
  prev_offset = peek(scope_stack)->offset;
  pop(&scope_stack)->table;
  if (peek(scope_stack)->is_global == 0)
  {
    peek(scope_stack)->offset = offset_to_inherit;
  } 
}
#line 1963 "parser.tab.c"
    break;

  case 33:
#line 381 "parser.y"
  { 
    (yyval.node) = (yyvsp[-1].node); 
  }
#line 1971 "parser.tab.c"
    break;

  case 34:
#line 387 "parser.y"
              { (yyval.node) = NULL; }
#line 1977 "parser.tab.c"
    break;

  case 35:
#line 389 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};

      if ((yyvsp[0].node) != NULL)
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
    }
#line 1988 "parser.tab.c"
    break;

  case 36:
#line 396 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1996 "parser.tab.c"
    break;

  case 37:
#line 400 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};

      if ((yyvsp[0].node) != NULL)
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
    }
#line 2007 "parser.tab.c"
    break;

  case 38:
#line 407 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 2015 "parser.tab.c"
    break;

  case 39:
#line 411 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};

      if ((yyvsp[0].node) != NULL)
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
    }
#line 2026 "parser.tab.c"
    break;

  case 40:
#line 418 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 2034 "parser.tab.c"
    break;

  case 41:
#line 422 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) 
      {
        (yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));
      } 
      else 
      {
        (yyval.node) = (yyvsp[0].node);
      };
    }
#line 2049 "parser.tab.c"
    break;

  case 42:
#line 433 "parser.y"
    {
      if ((yyvsp[-2].node) != NULL) 
      {
        (yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));
        if ((yyvsp[0].node) != NULL)
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
      } 
      else 
      {
        (yyval.node) = (yyvsp[0].node);
      };
    }
#line 2066 "parser.tab.c"
    break;

  case 43:
#line 446 "parser.y"
    {
      if ((yyvsp[-1].node) != NULL) 
      {
        (yyval.node) = (yyvsp[-1].node); add_children((yyval.node), 1, (yyvsp[0].node));
        if ((yyvsp[0].node) != NULL)
          concat_end(&(yyval.node)->code, (yyvsp[0].node)->code);
      } 
      else 
      {
        (yyval.node) = (yyvsp[0].node);
      };
    }
#line 2083 "parser.tab.c"
    break;

  case 44:
#line 462 "parser.y"
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope((yyvsp[-1].type), (yyvsp[0].prod)->id_list, local_scope);
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node;
    }
#line 2104 "parser.tab.c"
    break;

  case 45:
#line 479 "parser.y"
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope((yyvsp[-1].type), (yyvsp[0].prod)->id_list, local_scope);
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node; 
    }
#line 2125 "parser.tab.c"
    break;

  case 46:
#line 496 "parser.y"
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope((yyvsp[-1].type), (yyvsp[0].prod)->id_list, local_scope);
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node; 
    }
#line 2146 "parser.tab.c"
    break;

  case 47:
#line 513 "parser.y"
    { 
      // Get scope
      symb_table* local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      add_variables_to_scope((yyvsp[-1].type), (yyvsp[0].prod)->id_list, local_scope);
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node; 
    }
#line 2167 "parser.tab.c"
    break;

  case 48:
#line 533 "parser.y"
    {
      (yyval.prod)->id_list = new_id_list((yyvsp[0].lex_val), NOT_A_VECTOR);

      (yyval.prod)->ast_node = NULL;
    }
#line 2177 "parser.tab.c"
    break;

  case 49:
#line 539 "parser.y"
    {
      add_id(&(yyvsp[0].prod)->id_list, (yyvsp[-2].lex_val), NOT_A_VECTOR, NOT_A_STRING, NOT_INITIALIZED); 
      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list; 

      if ((yyvsp[0].prod)->ast_node != NULL ) { (yyval.prod)->ast_node = (yyvsp[0].prod)->ast_node; } else { (yyval.prod)->ast_node = NULL; };
    }
#line 2188 "parser.tab.c"
    break;

  case 50:
#line 546 "parser.y"
    {
      symbol_entry* lookup_res = st_lookup((yyvsp[0].lex_val)->value.s, scope_stack);
      if (lookup_res == NULL)
        syntactic_error(ERR_UNDECLARED, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
      if (lookup_res->symbol_type == VEC)
        syntactic_error(ERR_VECTOR, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);

      id_list* local_ids = malloc(sizeof(struct id_list_item));
      local_ids->id = (yyvsp[-2].lex_val)->value.s;
      local_ids->line = (yyvsp[-2].lex_val)->line;
      local_ids->vec_size = NOT_A_VECTOR;
      local_ids->ini_type = lookup_res->data_type;
      if (lookup_res->data_type == STR) local_ids->str_size = lookup_res->size;
      else local_ids->str_size = NOT_A_STRING;
      local_ids->next = NULL;
      (yyval.prod)->id_list = local_ids;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.prod)->ast_node, 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.prod)->ast_node->children[0]->data_type = lookup_res->data_type;
    }
#line 2213 "parser.tab.c"
    break;

  case 51:
#line 567 "parser.y"
    {
      id_list* local_ids = malloc(sizeof(struct id_list_item));
      local_ids->id = (yyvsp[-2].lex_val)->value.s;
      local_ids->line = (yyvsp[-2].lex_val)->line;
      local_ids->vec_size = NOT_A_VECTOR;
      local_ids->ini_type = (yyvsp[0].node)->data_type;
      if ((yyvsp[0].node)->data_type == STR)
      {
        local_ids->str_size = strlen((yyvsp[0].node)->label);
      }
      else local_ids->str_size = NOT_A_STRING;
      local_ids->next = NULL;
      (yyval.prod)->id_list = local_ids;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.prod)->ast_node, 2, lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].node));
      (yyval.prod)->ast_node->children[0]->data_type = (yyvsp[0].node)->data_type;
    }
#line 2235 "parser.tab.c"
    break;

  case 52:
#line 585 "parser.y"
    {
      symbol_entry* lookup_res = st_lookup((yyvsp[-2].lex_val)->value.s, scope_stack);
      if (lookup_res == NULL)
        syntactic_error(ERR_UNDECLARED, (yyvsp[-2].lex_val)->value.s, get_line_number(), NULL);

      if (lookup_res->data_type != STR)
        add_id(&(yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR, NOT_A_STRING, lookup_res->data_type); 
      else
        add_id(&(yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR, lookup_res->size, lookup_res->data_type);

      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list; 

      (yyval.prod)->ast_node = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.prod)->ast_node, 3, lexval_node((yyvsp[-4].lex_val)), lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].prod)->ast_node);
      (yyval.prod)->ast_node->children[0]->data_type = lookup_res->data_type;
    }
#line 2255 "parser.tab.c"
    break;

  case 53:
#line 601 "parser.y"
    {
      if ((yyvsp[-2].node)->data_type == STR)
      {
        add_id(&(yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR, strlen((yyvsp[-2].node)->label), (yyvsp[-2].node)->data_type); 
      }
      else
        add_id(&(yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR, NOT_A_STRING, (yyvsp[-2].node)->data_type);

      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list; 

      (yyval.prod)->ast_node = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.prod)->ast_node, 3, lexval_node((yyvsp[-4].lex_val)), (yyvsp[-2].node), (yyvsp[0].prod)->ast_node);
      (yyval.prod)->ast_node->children[0]->data_type = (yyvsp[-2].node)->data_type;
    }
#line 2273 "parser.tab.c"
    break;

  case 54:
#line 618 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, CHAR,
                                              1, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2286 "parser.tab.c"
    break;

  case 55:
#line 627 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, BOOL,
                                              1, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2299 "parser.tab.c"
    break;

  case 56:
#line 636 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, FLOAT,
                                              8, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2312 "parser.tab.c"
    break;

  case 57:
#line 645 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, INT,
                                              4, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2325 "parser.tab.c"
    break;

  case 58:
#line 654 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, STR,
                                              strlen((yyval.node)->label), NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2338 "parser.tab.c"
    break;

  case 59:
#line 663 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); 
      symb_table* scope = pop(&scope_stack);
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, BOOL,
                                              1, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2351 "parser.tab.c"
    break;

  case 60:
#line 675 "parser.y"
    { 
      symbol_entry* dst = st_lookup((yyvsp[-2].lex_val)->value.s, scope_stack);
      generic_attrib_errors_check((yyvsp[-2].lex_val), (yyvsp[0].node), 0, scope_stack, get_line_number());

      (yyval.node) = named_node("="); add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].node)); 
      (yyval.node)->children[0]->data_type = dst->data_type;

      concat_end(&((yyval.node)->code), (yyvsp[0].node)->code);

      char* label_end = label();
      inst *loadI, *jumpI;
      if ((yyvsp[0].node)->t != NULL)
      {
        char* label_true = label();
        patch((yyvsp[0].node)->t, label_true);

        loadI = new_inst(label_true, "loadI", "1", NULL, (yyvsp[0].node)->temp, NULL);
        jumpI = new_inst(NULL, "jumpI", NULL, NULL, label_end, NULL);

        insert_end(&(yyval.node)->code, loadI);
        insert_end(&(yyval.node)->code, jumpI);
      }
      if ((yyvsp[0].node)->f != NULL)
      {
        char* label_false = label();
        patch((yyvsp[0].node)->f, label_false);

        loadI = new_inst(label_false, "loadI", "0", NULL, (yyvsp[0].node)->temp, NULL);
        jumpI = new_inst(NULL, "jumpI", NULL, NULL, label_end, NULL);

        insert_end(&(yyval.node)->code, loadI);
        insert_end(&(yyval.node)->code, jumpI);
      }

      if ((yyvsp[0].node)->t != NULL || (yyvsp[0].node)->f != NULL)
      {
        inst* nop = new_inst(label_end, "nop", NULL, NULL, NULL, NULL);
        insert_end(&(yyval.node)->code, nop);
      }

      if (dst->is_global)
        insert_end(&((yyval.node)->code), new_inst(NULL, "storeAI", (yyvsp[0].node)->temp, NULL, "rbss", arg(dst->offset)));
      else
        insert_end(&((yyval.node)->code), new_inst(NULL, "storeAI", (yyvsp[0].node)->temp, NULL, "rfp", arg(dst->offset)));
    }
#line 2401 "parser.tab.c"
    break;

  case 61:
#line 721 "parser.y"
    { 
      symbol_entry* dst_lookup = st_lookup((yyvsp[-5].lex_val)->value.s, scope_stack);
      
      generic_attrib_errors_check((yyvsp[-5].lex_val), (yyvsp[0].node), 1, scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node));
      vector->children[0]->data_type = dst_lookup->data_type;
      (yyval.node) = named_node("="); add_children((yyval.node), 2, vector, (yyvsp[0].node)); 
    }
#line 2416 "parser.tab.c"
    break;

  case 62:
#line 735 "parser.y"
    {
      symbol_entry* lookup_res = st_lookup((yyvsp[0].lex_val)->value.s, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_INPUT, NULL, get_line_number(), NULL);
      }
      (yyval.node) = named_node("input"); add_children((yyval.node), 1, lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = lookup_res->data_type;
    }
#line 2434 "parser.tab.c"
    break;

  case 63:
#line 749 "parser.y"
    {
      symbol_entry* lookup_res = st_lookup((yyvsp[0].lex_val)->value.s, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_OUTPUT, NULL, get_line_number(), NULL);
      }

      (yyval.node) = named_node("output"); add_children((yyval.node), 1, lexval_node((yyvsp[0].lex_val)));
    }
#line 2452 "parser.tab.c"
    break;

  case 64:
#line 763 "parser.y"
    {
      symbol_entry* lookup_res = st_lookup((yyvsp[0].node)->label, scope_stack);
      if (lookup_res == NULL)
      {
       syntactic_error(ERR_UNDECLARED, (yyvsp[0].node)->label, get_line_number(), NULL);
      }
      if (lookup_res->data_type != INT && lookup_res->data_type != FLOAT)
      {
        syntactic_error(ERR_WRONG_PAR_OUTPUT, NULL, get_line_number(), NULL);
      }

      (yyval.node) = named_node("output"); add_children((yyval.node), 1, (yyvsp[0].node));
    }
#line 2470 "parser.tab.c"
    break;

  case 65:
#line 780 "parser.y"
    { 
      // Check if function is declared.
      symbol_entry* lookup_res = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);

      if (lookup_res == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      // Check if symbol is a function.
      if (lookup_res->symbol_type != FUNC)
      {
        if (lookup_res->symbol_type == VAR)
          syntactic_error(ERR_VARIABLE, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
        if (lookup_res->symbol_type == VEC)
          syntactic_error(ERR_VECTOR, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      // Check arguments.
      if (arg_list_len((yyvsp[-1].prod)->arg_list) < arg_list_len(lookup_res->args))
      {
        syntactic_error(ERR_MISSING_ARGS, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }
      else if (arg_list_len((yyvsp[-1].prod)->arg_list) > arg_list_len(lookup_res->args))
      {
        syntactic_error(ERR_EXCESS_ARGS, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      if (arg_list_len((yyvsp[-1].prod)->arg_list) != 0)
      {
        arg_list* table_entry_arg = lookup_res->args;
        arg_list* call_arg = (yyvsp[-1].prod)->arg_list;
        do
        {
          if (table_entry_arg->type == CHAR && call_arg->type != CHAR || table_entry_arg->type == STR && call_arg->type != STR
              || table_entry_arg->type != CHAR && call_arg->type == CHAR || table_entry_arg->type != STR && call_arg->type == STR)
          {
            syntactic_error(ERR_WRONG_TYPE_ARGS, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
          }
          table_entry_arg = table_entry_arg->next;
          call_arg = call_arg->next;
        } while (table_entry_arg != NULL && call_arg != NULL);
      }

      
      (yyval.node) = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.node), 1, (yyvsp[-1].prod)->ast_node);
      (yyval.node)->data_type = lookup_res->data_type;

      gen_func_call_code((yyval.node), (yyvsp[-1].prod), lookup_res, scope_stack);
    }
#line 2525 "parser.tab.c"
    break;

  case 66:
#line 834 "parser.y"
    { 
      arg_list* exp_list = malloc(sizeof(struct arg_list_item));

      if ((yyvsp[0].node)->val != NULL)
      {
        exp_list->id = (yyvsp[0].node)->label;
        exp_list->line = (yyvsp[0].node)->val->line;
        exp_list->type = (yyvsp[0].node)->data_type;
        exp_list->next = NULL;
      }
      else if (strcmp((yyvsp[0].node)->label, "[]") == 0)
      {
        exp_list->id = (yyvsp[0].node)->children[0]->val->value.s;
        exp_list->line = get_line_number();
        exp_list->type = (yyvsp[0].node)->data_type;
        exp_list->next = NULL;
      }
      else
      {
        exp_list->id = (yyvsp[0].node)->label;
        exp_list->line = get_line_number();
        exp_list->type = (yyvsp[0].node)->data_type;
        exp_list->next = NULL;
      }

      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;

      memcpy(head->ast_node, (yyvsp[0].node), sizeof(struct node));
      head->arg_list = exp_list;
      (yyval.prod) = head;
    }
#line 2564 "parser.tab.c"
    break;

  case 67:
#line 869 "parser.y"
    { 
      arg_list* exp_list_item = malloc(sizeof(struct arg_list_item));

      if ((yyvsp[-2].node)->val != NULL)
      {
        exp_list_item->id = (yyvsp[-2].node)->val->value.s;
        exp_list_item->line = (yyvsp[-2].node)->val->line;
        exp_list_item->type = (yyvsp[-2].node)->data_type;
        exp_list_item->next = NULL;
      }
      else if (strcmp((yyvsp[-2].node)->label, "[]") == 0)
      {
        exp_list_item->id = (yyvsp[-2].node)->children[0]->val->value.s;
        exp_list_item->line = get_line_number();
        exp_list_item->type = (yyvsp[-2].node)->data_type;
        exp_list_item->next = NULL;
      }
      else
      {
        exp_list_item->id = (yyvsp[-2].node)->label;
        exp_list_item->line = get_line_number();
        exp_list_item->type = (yyvsp[-2].node)->data_type;
        exp_list_item->next = NULL;
      }

      add_arg_call((yyvsp[0].prod)->arg_list, exp_list_item);

      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;

      memcpy(head->ast_node, (yyvsp[-2].node), sizeof(struct node));
      head->arg_list = (yyvsp[0].prod)->arg_list;
      (yyval.prod) = head;

      add_children((yyval.prod)->ast_node, 1, (yyvsp[0].prod)->ast_node);
    }
#line 2607 "parser.tab.c"
    break;

  case 68:
#line 908 "parser.y"
    { 
      struct prod_val* head = (struct prod_val*) malloc(sizeof(struct prod_val));
      head->ast_node = (struct node*) malloc(sizeof(struct node));
      head->arg_list = (struct arg_list_item*) malloc(sizeof(struct arg_list_item));
      head->id_list = NULL;
      head->arg_list = NULL;
      head->ast_node = NULL;
      (yyval.prod) = head; 
    }
#line 2621 "parser.tab.c"
    break;

  case 69:
#line 921 "parser.y"
    {
      int type = shift_val_check((yyvsp[-2].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); 
      add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = type;
    }
#line 2633 "parser.tab.c"
    break;

  case 70:
#line 929 "parser.y"
    {
      int type = shift_val_check((yyvsp[-2].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); 
      add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = type;
    }
#line 2645 "parser.tab.c"
    break;

  case 71:
#line 937 "parser.y"
    {
      int type = shift_val_check((yyvsp[-3].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); 
      add_children((yyval.node), 2, lexval_node((yyvsp[-3].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = type;
    }
#line 2657 "parser.tab.c"
    break;

  case 72:
#line 945 "parser.y"
    {
      int type = shift_val_check((yyvsp[-3].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); 
      add_children((yyval.node), 2, lexval_node((yyvsp[-3].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = type;
    }
#line 2669 "parser.tab.c"
    break;

  case 73:
#line 953 "parser.y"
    {
      int type = shift_val_check((yyvsp[-5].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node)); vector->children[0]->data_type = type;
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2681 "parser.tab.c"
    break;

  case 74:
#line 961 "parser.y"
    {
      int type = shift_val_check((yyvsp[-5].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node)); vector->children[0]->data_type = type;
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2693 "parser.tab.c"
    break;

  case 75:
#line 969 "parser.y"
    {
      int type = shift_val_check((yyvsp[-6].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-6].lex_val)), (yyvsp[-4].node)); vector->children[0]->data_type = type;
      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2705 "parser.tab.c"
    break;

  case 76:
#line 977 "parser.y"
    {
      int type = shift_val_check((yyvsp[-6].lex_val), (yyvsp[0].lex_val), scope_stack, get_line_number());

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-6].lex_val)), (yyvsp[-4].node)); vector->children[0]->data_type = type;
      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2717 "parser.tab.c"
    break;

  case 77:
#line 988 "parser.y"
    {      
      (yyval.node) = named_node("return"); add_children((yyval.node), 1, (yyvsp[0].node)); 
      (yyval.node)->data_type = (yyvsp[0].node)->data_type;
      (yyval.node)->is_return = 1;
      (yyval.node)->return_line = get_line_number();
      concat_end(&((yyval.node)->code), (yyvsp[0].node)->code); // Causes freezing.
      (yyval.node)->temp = (yyvsp[0].node)->temp;
      printf("Codigo na regra do return:\n");
      print_code((yyval.node)->code);
      printf("SAINDO DA REGRA DO RETURN\n");
    }
#line 2733 "parser.tab.c"
    break;

  case 78:
#line 999 "parser.y"
                { (yyval.node) = named_node("break"); }
#line 2739 "parser.tab.c"
    break;

  case 79:
#line 1000 "parser.y"
                   { (yyval.node) = named_node("continue"); }
#line 2745 "parser.tab.c"
    break;

  case 80:
#line 1004 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 2751 "parser.tab.c"
    break;

  case 81:
#line 1005 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 2757 "parser.tab.c"
    break;

  case 82:
#line 1006 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 2763 "parser.tab.c"
    break;

  case 83:
#line 1011 "parser.y"
    {  
        (yyval.node) = named_node("if");
        add_children((yyval.node), 3, (yyvsp[-2].node), (yyvsp[0].node), NULL);

        gen_if_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 2774 "parser.tab.c"
    break;

  case 84:
#line 1018 "parser.y"
    {  
        (yyval.node) = named_node("if");
        add_children((yyval.node), 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));

        gen_if_code((yyval.node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2785 "parser.tab.c"
    break;

  case 85:
#line 1028 "parser.y"
    {  
        (yyval.node) = named_node("for");
        add_children((yyval.node), 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));

        gen_for_code((yyval.node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2796 "parser.tab.c"
    break;

  case 86:
#line 1038 "parser.y"
    {  
        (yyval.node) = named_node("while");
        add_children((yyval.node), 2, (yyvsp[-3].node), (yyvsp[0].node));

        gen_while_code((yyval.node), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 2807 "parser.tab.c"
    break;

  case 87:
#line 1048 "parser.y"
    { 
      symbol_entry* lookup_result = st_lookup((yyvsp[0].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
      }
      else if (lookup_result->symbol_type != VAR)
      {
        if (lookup_result->symbol_type == VEC)
          syntactic_error(ERR_VECTOR, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
        if (lookup_result->symbol_type == FUNC)
          syntactic_error(ERR_FUNCTION, (yyvsp[0].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = lookup_result->data_type;
      (yyval.node)->size = lookup_result->size;

      char* temp = reg();
      (yyval.node)->temp = temp;
      if (lookup_result->is_global)
        insert_end(&((yyval.node)->code),
         new_inst(NULL, "loadAI", "rbss", arg(lookup_result->offset), temp, NULL));
      else
        insert_end(&((yyval.node)->code),
         new_inst(NULL, "loadAI", "rfp", arg(lookup_result->offset), temp, NULL));
    }
#line 2838 "parser.tab.c"
    break;

  case 88:
#line 1075 "parser.y"
    {
      symbol_entry* lookup_result = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }
      else if (lookup_result->symbol_type != VEC)
      {
        if (lookup_result->symbol_type == VAR)
          syntactic_error(ERR_VARIABLE, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
        if (lookup_result->symbol_type == FUNC)
          syntactic_error(ERR_FUNCTION, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      if ((yyvsp[-1].node)->data_type == CHAR)
      {
        syntactic_error(ERR_CHAR_TO_X, (yyvsp[-1].node)->label, get_line_number(), NULL);
      }
      if ((yyvsp[-1].node)->data_type == STR)
      {
        syntactic_error(ERR_STRING_TO_X, (yyvsp[-1].node)->label, get_line_number(), NULL);
      }

      (yyval.node) = named_node("[]"); (yyval.node)->data_type = lookup_result->data_type;
      add_children((yyval.node), 2, lexval_node((yyvsp[-3].lex_val)), (yyvsp[-1].node));
    }
#line 2869 "parser.tab.c"
    break;

  case 89:
#line 1101 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2875 "parser.tab.c"
    break;

  case 90:
#line 1103 "parser.y"
    { 
      (yyval.node) = (yyvsp[0].node); 
      gen_bool_lit_exp_code((yyval.node));
    }
#line 2884 "parser.tab.c"
    break;

  case 91:
#line 1108 "parser.y"
    { 
      (yyval.node) = (yyvsp[0].node); 
    }
#line 2892 "parser.tab.c"
    break;

  case 92:
#line 1111 "parser.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2898 "parser.tab.c"
    break;

  case 93:
#line 1113 "parser.y"
    { 
      (yyval.node) = (yyvsp[-1].node); 
      add_children((yyval.node), 1, (yyvsp[0].node)); 
      (yyval.node)->data_type = (yyvsp[0].node)->data_type;

      gen_logicop_code((yyval.node), (yyvsp[0].node), NULL);
    }
#line 2910 "parser.tab.c"
    break;

  case 94:
#line 1121 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      char* temp = reg();
      generate_binary_exp_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), 
        new_inst(NULL, "add", (yyvsp[-2].node)->temp, (yyvsp[0].node)->temp, temp, NULL),
        temp);

    }
#line 2924 "parser.tab.c"
    break;

  case 95:
#line 1131 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      char* temp = reg();
      generate_binary_exp_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), 
        new_inst(NULL, "sub", (yyvsp[-2].node)->temp, (yyvsp[0].node)->temp, temp, NULL),
        temp);
    }
#line 2937 "parser.tab.c"
    break;

  case 96:
#line 1140 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      char* temp = reg();
      generate_binary_exp_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), 
        new_inst(NULL, "mult", (yyvsp[-2].node)->temp, (yyvsp[0].node)->temp, temp, NULL),
        temp);
    }
#line 2950 "parser.tab.c"
    break;

  case 97:
#line 1149 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      char* temp = reg();
      generate_binary_exp_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), 
        new_inst(NULL, "div", (yyvsp[-2].node)->temp, (yyvsp[0].node)->temp, temp, NULL),
        temp);
    }
#line 2963 "parser.tab.c"
    break;

  case 98:
#line 1158 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2972 "parser.tab.c"
    break;

  case 99:
#line 1163 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2981 "parser.tab.c"
    break;

  case 100:
#line 1168 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2990 "parser.tab.c"
    break;

  case 101:
#line 1173 "parser.y"
    { 
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2999 "parser.tab.c"
    break;

  case 102:
#line 1178 "parser.y"
    { 
      (yyval.node) = named_node("<"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); 
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node));      
    }
#line 3011 "parser.tab.c"
    break;

  case 103:
#line 1186 "parser.y"
    { 
      (yyval.node) = named_node(">"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 3023 "parser.tab.c"
    break;

  case 104:
#line 1194 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_logicop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3035 "parser.tab.c"
    break;

  case 105:
#line 1202 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 3047 "parser.tab.c"
    break;

  case 106:
#line 1210 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 3059 "parser.tab.c"
    break;

  case 107:
#line 1218 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 3071 "parser.tab.c"
    break;

  case 108:
#line 1226 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_relop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 3083 "parser.tab.c"
    break;

  case 109:
#line 1234 "parser.y"
    { 
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      binary_exp_type_and_error_check((yyval.node), (yyvsp[-2].node), (yyvsp[0].node), get_line_number());
      (yyval.node)->data_type = BOOL;

      gen_logicop_code((yyval.node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3095 "parser.tab.c"
    break;

  case 110:
#line 1242 "parser.y"
    { 
      (yyval.node) = named_node("?:");
      add_children((yyval.node), 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      if ((yyvsp[-4].node)->data_type != BOOL && (yyvsp[-4].node)->data_type != INT
          && (yyvsp[-4].node)->data_type != FLOAT)
        syntactic_error(ERR_WRONG_TYPE, NULL, get_line_number(), NULL);
    }
#line 3107 "parser.tab.c"
    break;

  case 111:
#line 1253 "parser.y"
    { 
      char float_to_str[7];
      gcvt((yyvsp[0].lex_val)->value.f, 4, float_to_str);
      // Check if literal already on table.
      //printf("Antes de chamar st_lookup em num.\n");
      symbol_entry* sb = st_lookup(float_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        symb_table* scope = pop(&scope_stack);
        sb = new_symbol_entry(float_to_str, get_line_number(), LIT, FLOAT, 8, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = FLOAT; 
    }
#line 3129 "parser.tab.c"
    break;

  case 112:
#line 1271 "parser.y"
    { 
      int len = snprintf(NULL, 0, "%d", (yyvsp[0].lex_val)->value.i) + 1; 
      char* int_to_str = malloc(len);
      snprintf(int_to_str, len, "%d", (yyvsp[0].lex_val)->value.i);
      // Check if literal already on table.
      symbol_entry* sb = st_lookup(int_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        symb_table* scope = pop(&scope_stack);
        sb = new_symbol_entry(int_to_str, get_line_number(), LIT, INT, 4, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }
      
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = INT;
      char* temp = reg();
      insert_end(&((yyval.node)->code), 
        new_inst(NULL, "loadI", arg((yyvsp[0].lex_val)->value.i), NULL, temp, NULL));
      (yyval.node)->temp = temp;
    }
#line 3156 "parser.tab.c"
    break;

  case 113:
#line 1294 "parser.y"
  {
    (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = CHAR;
    symbol_entry* sb = st_lookup((yyval.node)->label, scope_stack);
    if (sb == NULL)
    {
      symb_table* scope = pop(&scope_stack);
      sb = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, CHAR, 1, NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      if (scope == NULL) printf("Scope is null on num.\n");
      ht_insert(sb, scope);
      push(&scope_stack, scope);
    }
  }
#line 3173 "parser.tab.c"
    break;

  case 114:
#line 1307 "parser.y"
  {
    (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = STR; (yyval.node)->size = strlen((yyval.node)->label);

    symbol_entry* sb = st_lookup((yyval.node)->label, scope_stack);
    if (sb == NULL)
    {
      symb_table* scope = pop(&scope_stack);
      sb = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, STR, strlen((yyval.node)->label), NULL, (yyvsp[0].lex_val), 0, scope->is_global, NULL);
      if (scope == NULL) printf("Scope is null on num.\n");
      ht_insert(sb, scope);
      push(&scope_stack, scope);
    }
  }
#line 3191 "parser.tab.c"
    break;

  case 115:
#line 1323 "parser.y"
        { (yyval.node) = named_node("+"); }
#line 3197 "parser.tab.c"
    break;

  case 116:
#line 1324 "parser.y"
        { (yyval.node) = named_node("-"); }
#line 3203 "parser.tab.c"
    break;

  case 117:
#line 1325 "parser.y"
        { (yyval.node) = named_node("!"); }
#line 3209 "parser.tab.c"
    break;

  case 118:
#line 1326 "parser.y"
        { (yyval.node) = named_node("&"); }
#line 3215 "parser.tab.c"
    break;

  case 119:
#line 1327 "parser.y"
        { (yyval.node) = named_node("*"); }
#line 3221 "parser.tab.c"
    break;

  case 120:
#line 1328 "parser.y"
        { (yyval.node) = named_node("?"); }
#line 3227 "parser.tab.c"
    break;

  case 121:
#line 1329 "parser.y"
        { (yyval.node) = named_node("#"); }
#line 3233 "parser.tab.c"
    break;

  case 122:
#line 1333 "parser.y"
                 { (yyval.node) = lexval_node((yyvsp[0].lex_val)); }
#line 3239 "parser.tab.c"
    break;

  case 123:
#line 1334 "parser.y"
                { (yyval.node) = lexval_node((yyvsp[0].lex_val)); }
#line 3245 "parser.tab.c"
    break;


#line 3249 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1337 "parser.y"


void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

