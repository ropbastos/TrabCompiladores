/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

#include "verification_semantic.h"

int yylex(void);
void yyerror (char const *s);
int get_line_number();
int get_col();

extern void* arvore;
stack* scope_stack = NULL;
extern int return_line;
extern int expected_return_type;
extern int return_type_is_correct;

typedef struct prod_val {
  struct node* ast_node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
} prod;

#line 92 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 30 "parser.y" /* yacc.c:355  */

  struct lex_val* lex_val;
  struct node* node;
  struct id_list_item* id_list;
  struct arg_list_item* arg_list;
  struct prod_val* prod;
  int type;

#line 191 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   545

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   148,   149,   153,   161,   167,   176,   181,
     186,   191,   196,   201,   209,   210,   211,   212,   213,   217,
     230,   237,   243,   249,   258,   263,   272,   277,   289,   292,
     293,   296,   303,   304,   308,   312,   316,   320,   324,   328,
     332,   339,   405,   471,   537,   606,   617,   624,   635,   646,
     653,   663,   672,   681,   690,   699,   708,   720,   755,   790,
     804,   818,   835,   875,   923,   962,   966,   982,   997,  1012,
    1027,  1043,  1059,  1075,  1094,  1102,  1103,  1107,  1108,  1109,
    1113,  1118,  1126,  1134,  1142,  1162,  1186,  1187,  1188,  1192,
    1193,  1194,  1199,  1204,  1209,  1214,  1219,  1224,  1229,  1234,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1256,  1274,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1306,  1307
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
  "func", "header", "params", "body", "block_start", "block_end", "block",
  "cmds", "local_decl", "local_list", "literal", "attrib", "io",
  "func_call", "exp_list", "shift", "jmp_stmt", "control", "if", "for",
  "while", "exp", "num", "unary", "bool", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     213,   -92,   -92,   -92,   -92,   -92,    84,     5,   -92,   213,
     -40,   213,   -26,    10,   -92,   -92,   -21,    -7,   -92,   -92,
     -92,   134,   -92,   -18,    14,    52,     2,    13,   -92,    50,
      53,    75,   313,   119,    84,   345,    56,   -92,   -92,    -4,
      78,    21,    62,    70,    79,    80,    82,    88,    99,   100,
     -92,   -92,   -92,    18,   -92,   -39,   -92,   105,   126,    84,
     -92,   127,   106,   119,   119,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    15,   -92,
     -92,   -92,   -92,   -92,   119,   -92,   -92,   -92,   442,   -92,
     119,   -92,    78,    84,    78,   132,     8,    36,   119,   119,
     119,     7,   -92,   134,   -92,   -92,   134,   134,   134,   134,
     134,   134,   134,   -92,   111,   133,   116,   137,   139,   -92,
     179,   211,   119,   243,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   -92,   -92,    78,   -92,   -34,   143,   -92,   145,   -92,
     148,   442,   275,   136,   386,   350,    78,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,    52,   158,   159,   382,
     -26,   203,   312,   -92,   366,    11,   259,   259,   484,   474,
     398,   195,   227,    11,   366,    -8,    -8,   -92,   -92,   -92,
     -92,   -92,   119,   119,   -92,   -92,    47,   -92,   119,   173,
     174,   -92,   -92,    52,   382,   -92,   252,   -26,   -92,   119,
     349,   430,    37,    39,   119,   -92,    78,    78,   -92,   -92,
     -26,   -92,   -92,   231,   132,   -92,   183,   -92,   251,   442,
     -92,   -92,   -92,   224,   -92,   -92,   -26,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    14,    15,    16,    17,    18,     0,     0,     2,     3,
       0,     3,     0,     0,     1,     4,     8,     0,     5,    29,
      19,    32,    28,     8,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,     0,     7,     8,    11,     0,     0,     0,
      20,     0,     0,     0,     0,    59,    54,    53,    52,    56,
      51,    55,    60,    61,   109,   108,   117,   118,    84,   115,
     113,   110,   111,   114,     0,   112,   116,    88,    74,    86,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    45,    41,    32,    30,    31,    32,    32,    32,    32,
      32,    32,    32,    22,     0,     9,     0,     0,    25,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    42,     0,    44,     0,     0,    66,     0,    67,
       0,    57,     0,     0,    63,     0,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    23,     0,    10,    27,     0,
       0,     0,     0,    89,   104,   103,   102,   105,   101,   106,
       0,    97,    98,   100,    99,    91,    92,    93,    94,    95,
      96,    43,     0,     0,    68,    69,     0,    62,    65,    47,
      48,    46,    12,     0,     0,    24,    80,     0,    85,     0,
       0,     0,     0,     0,     0,    64,     0,     0,    13,    26,
       0,    83,   107,     0,     0,    70,     0,    71,     0,    58,
      49,    50,    81,     0,    72,    73,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   107,   -92,   -11,     1,   -92,   -92,   -50,   -92,
     -92,   -92,   -12,    90,   -92,   -81,   157,   -91,   -92,    19,
      96,   -92,   -92,   -92,   -92,   -92,   -92,   -25,   -92,   -92,
     -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    17,    40,    11,    12,    62,    20,
      21,   105,    41,    42,    43,   102,    73,    44,    45,    87,
     153,    47,    48,    49,    50,    51,    52,   154,    89,    90,
      91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    10,    24,   114,   146,    14,    16,    13,    88,    25,
      10,   142,    10,   144,    56,    98,     1,     2,     3,     4,
       5,     1,     2,     3,     4,     5,    26,    25,    61,    59,
      25,   192,    96,    97,    59,    92,    94,   155,   120,   121,
      46,   124,    57,    19,    26,    98,    27,    26,   147,    53,
     137,   138,   139,   140,    61,   156,    23,    28,    58,   123,
     117,    99,   191,   100,   148,   141,   134,   135,   136,   137,
     138,   139,   140,   151,   152,   201,   149,   225,    54,   227,
     122,    60,   100,   212,   213,   103,   113,     1,     2,     3,
       4,     5,   150,   226,   143,   228,   214,   172,    55,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    15,    63,    18,   205,
      64,    65,    46,    95,   101,    46,    46,    46,    46,    46,
      46,    46,   104,   233,   106,   230,   231,     1,     2,     3,
       4,     5,    29,   107,   108,    30,   109,    31,    32,    33,
      34,    35,   110,    36,   219,   202,    37,    38,   206,    74,
      75,    76,    77,   111,   112,    78,   116,   210,   211,    79,
      61,   115,    80,   118,   119,    81,    82,    83,   145,   165,
      39,   166,   167,   168,   222,   194,    84,   169,   195,   229,
      85,    86,   218,   157,   193,   221,   158,   159,   160,   161,
     162,   163,   164,    19,   197,    61,   203,   204,   232,   124,
     125,   126,   127,   128,   129,   207,     1,     2,     3,     4,
       5,   216,   217,   234,   237,   124,   125,   126,   127,   130,
       6,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   124,   125,   126,   127,   128,   129,   170,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   124,   125,   126,
     127,   130,   220,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   124,   125,   126,   127,   128,   129,   171,
     214,   133,   134,   135,   136,   137,   138,   139,   140,   124,
     125,   235,   236,   130,   215,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   124,   125,   126,   127,   128,
     129,   173,   200,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,   196,   124,   125,   126,   127,   128,   129,     1,     2,
       3,     4,     5,    66,    67,    68,    69,    70,    71,    72,
       0,    93,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,   208,   124,
     125,   126,   127,   128,   129,     1,     2,     3,     4,     5,
      66,    67,    68,    69,    70,    71,   199,     0,    59,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,   223,   124,   125,   126,   127,
     128,   129,   135,   136,   137,   138,   139,   140,   124,   125,
     126,   127,   128,   129,   198,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   130,   209,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,     0,     0,
     130,   224,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140
};

static const yytype_int16 yycheck[] =
{
      12,     0,    13,    53,    95,     0,    46,     6,    33,    48,
       9,    92,    11,    94,    25,    49,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    65,    48,    27,    16,
      48,    65,    36,    37,    16,    34,    35,    30,    63,    64,
      21,    30,    40,    69,    65,    49,    67,    65,    40,    67,
      58,    59,    60,    61,    53,    48,    46,    64,    56,    84,
      59,    65,   143,    67,    56,    90,    55,    56,    57,    58,
      59,    60,    61,    98,    99,   156,    40,    40,    64,    40,
      65,    68,    67,    36,    37,    64,    68,     3,     4,     5,
       6,     7,    56,    56,    93,    56,    49,   122,    46,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     9,    67,    11,   169,
      67,    46,   103,    67,    46,   106,   107,   108,   109,   110,
     111,   112,    70,   224,    64,   216,   217,     3,     4,     5,
       6,     7,     8,    64,    64,    11,    64,    13,    14,    15,
      16,    17,    64,    19,   204,   166,    22,    23,   170,    40,
      41,    42,    43,    64,    64,    46,    40,   192,   193,    50,
     169,    66,    53,    46,    68,    56,    57,    58,    46,    68,
      46,    48,    66,    46,   209,    40,    67,    48,    40,   214,
      71,    72,   203,   103,    51,   207,   106,   107,   108,   109,
     110,   111,   112,    69,    68,   204,    48,    48,   220,    30,
      31,    32,    33,    34,    35,    12,     3,     4,     5,     6,
       7,    48,    48,    40,   236,    30,    31,    32,    33,    50,
      17,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    30,    31,    32,    33,    34,    35,    68,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    30,    31,    32,
      33,    50,    10,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    30,    31,    32,    33,    34,    35,    68,
      49,    54,    55,    56,    57,    58,    59,    60,    61,    30,
      31,    40,    68,    50,   198,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    30,    31,    32,    33,    34,
      35,    68,   155,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    30,    31,    32,    33,    34,    35,     3,     4,
       5,     6,     7,    40,    41,    42,    43,    44,    45,    46,
      -1,    16,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    30,
      31,    32,    33,    34,    35,     3,     4,     5,     6,     7,
      40,    41,    42,    43,    44,    45,    46,    -1,    16,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    30,    31,    32,    33,
      34,    35,    56,    57,    58,    59,    60,    61,    30,    31,
      32,    33,    34,    35,    48,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    74,    75,    76,
      78,    79,    80,    78,     0,    75,    46,    77,    75,    69,
      82,    83,    85,    46,    77,    48,    65,    67,    64,     8,
      11,    13,    14,    15,    16,    17,    19,    22,    23,    46,
      78,    85,    86,    87,    90,    91,    92,    94,    95,    96,
      97,    98,    99,    67,    64,    46,    77,    40,    56,    16,
      68,    78,    81,    67,    67,    46,    40,    41,    42,    43,
      44,    45,    46,    89,    40,    41,    42,    43,    46,    50,
      53,    56,    57,    58,    67,    71,    72,    92,   100,   101,
     102,   103,    78,    16,    78,    67,    36,    37,    49,    65,
      67,    46,    88,    64,    70,    84,    64,    64,    64,    64,
      64,    64,    64,    68,    81,    66,    40,    78,    46,    68,
     100,   100,    65,   100,    30,    31,    32,    33,    34,    35,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   100,    88,    78,    88,    46,    90,    40,    56,    40,
      56,   100,   100,    93,   100,    30,    48,    86,    86,    86,
      86,    86,    86,    86,    86,    68,    48,    66,    46,    48,
      68,    68,   100,    68,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,    88,    65,    51,    40,    40,    66,    68,    48,    46,
      89,    88,    77,    48,    48,    81,    85,    12,    66,    51,
     100,   100,    36,    37,    49,    93,    48,    48,    77,    81,
      10,    85,   100,    66,    51,    40,    56,    40,    56,   100,
      88,    88,    85,    90,    40,    40,    68,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      80,    80,    80,    80,    81,    81,    81,    81,    82,    83,
      84,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    91,    92,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     3,     4,     1,     4,
       5,     3,     6,     7,     1,     1,     1,     1,     1,     2,
       4,     5,     5,     6,     4,     2,     5,     3,     1,     1,
       1,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     4,     3,     1,     3,     3,     3,     5,
       5,     1,     1,     1,     1,     1,     1,     3,     6,     2,
       2,     2,     4,     1,     3,     0,     3,     3,     4,     4,
       6,     6,     7,     7,     2,     1,     1,     1,     1,     1,
       5,     7,     9,     6,     1,     4,     1,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 145 "parser.y" /* yacc.c:1646  */
    { arvore = (yyvsp[0].node); }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 150 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) != NULL) (yyval.node) = (yyvsp[0].node); else (yyval.node) = NULL;
    }
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 154 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[-1].node);
      add_children((yyval.node), 1, (yyvsp[0].node));
    }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 162 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** global_scope =  get_scope(&scope_stack);
      global_scope = add_to_global_scope( (yyvsp[-1].id_list), (yyvsp[-2].type), VAR, global_scope);
      push(&scope_stack, global_scope);
    }
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** global_scope =  get_scope(&scope_stack);
      global_scope = add_to_global_scope( (yyvsp[-1].id_list), (yyvsp[-2].type), VAR, global_scope);
      push(&scope_stack, global_scope);
    }
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 177 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_id = get_global_id((yyvsp[0].lex_val), NOT_A_VECTOR);
      (yyval.id_list) = global_id;
    }
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 182 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_id = get_global_id((yyvsp[-3].lex_val), NOT_A_VECTOR);
      (yyval.id_list) = global_id;
    }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_id = get_global_id((yyvsp[-4].lex_val), (yyvsp[-1].lex_val)->value.i);
      (yyval.id_list) = global_id;
    }
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 192 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].id_list), (yyvsp[-2].lex_val), NOT_A_VECTOR);
      (yyval.id_list) = (yyvsp[0].id_list);
    }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 197 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].id_list), (yyvsp[-5].lex_val), (yyvsp[-3].lex_val)->value.i);
      (yyval.id_list) = (yyvsp[0].id_list);
    }
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 202 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].id_list), (yyvsp[-6].lex_val), (yyvsp[-3].lex_val)->value.i);
      (yyval.id_list) = (yyvsp[0].id_list);
    }
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = INT; }
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = FLOAT; }
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = BOOL; }
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = CHAR; }
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = STR; }
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 218 "parser.y" /* yacc.c:1646  */
    {
      expected_return_type = (yyvsp[-1].node)->data_type;
      check_return_type((yyvsp[0].node));
      if (!return_type_is_correct)
      {
        syntactic_error(ERR_WRONG_PAR_RETURN, (yyvsp[-1].node)->label, return_line, NULL);
      }
      (yyval.node) = (yyvsp[-1].node); if ((yyvsp[0].node) != NULL) add_children((yyval.node), 1, (yyvsp[0].node));
    }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** scope =  get_scope(&scope_stack);
      symbol_entry* sb = add_to_func_scope((yyvsp[-2].lex_val), (yyvsp[-3].type), &scope_stack, scope, NULL, NULL);
      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); (yyval.node)->data_type = sb->data_type;

    }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 238 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** scope =  get_scope(&scope_stack);
      symbol_entry* sb = add_to_func_scope((yyvsp[-3].lex_val), (yyvsp[-4].type), &scope_stack, scope, (yyvsp[-1].arg_list), (yyvsp[-3].lex_val));
      (yyval.node) = lexval_node((yyvsp[-3].lex_val)); (yyval.node)->data_type = sb->data_type;
    }
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** scope =  get_scope(&scope_stack);
      symbol_entry* sb = add_to_func_scope((yyvsp[-2].lex_val), (yyvsp[-3].type), &scope_stack, scope, NULL, (yyvsp[-2].lex_val));
      (yyval.node) = lexval_node((yyvsp[-2].lex_val));
    }
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 250 "parser.y" /* yacc.c:1646  */
    {
      ht_entry** scope =  get_scope(&scope_stack);
      symbol_entry* sb = add_to_func_scope((yyvsp[-3].lex_val), (yyvsp[-4].type), &scope_stack, scope, (yyvsp[-1].arg_list), (yyvsp[-3].lex_val));
      (yyval.node) = lexval_node((yyvsp[-3].lex_val));
    }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 259 "parser.y" /* yacc.c:1646  */
    {
      add_arg((yyvsp[0].arg_list), (yyvsp[-2].lex_val), (yyvsp[-3].type));
      (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 264 "parser.y" /* yacc.c:1646  */
    {
      arg_list* param_list = malloc(sizeof(struct arg_list_item));
      param_list->id = (yyvsp[0].lex_val)->value.s;
      param_list->line = (yyvsp[0].lex_val)->line;
      param_list->type = (yyvsp[-1].type);
      param_list->next = NULL;
      (yyval.arg_list) = param_list;
    }
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 273 "parser.y" /* yacc.c:1646  */
    {
      add_arg((yyvsp[0].arg_list), (yyvsp[-2].lex_val), (yyvsp[-3].type));
      (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 278 "parser.y" /* yacc.c:1646  */
    {
      arg_list* param_list = malloc(sizeof(struct arg_list_item));
      param_list->id = (yyvsp[0].lex_val)->value.s;
      param_list->line = (yyvsp[0].lex_val)->line;
      param_list->type = (yyvsp[-1].type);
      param_list->next = NULL;
      (yyval.arg_list) = param_list;
    }
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "parser.y" /* yacc.c:1646  */
    { push(&scope_stack, hash_table()); }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "parser.y" /* yacc.c:1646  */
    { pop(&scope_stack); }
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 297 "parser.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 309 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 313 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 317 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 321 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 325 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 329 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 333 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); add_children((yyval.node), 1, (yyvsp[0].node));} else {(yyval.node) = (yyvsp[0].node);};
    }
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 340 "parser.y" /* yacc.c:1646  */
    {
      // Get scope
      ht_entry** local_scope;
      local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      id_list* current = (yyvsp[0].prod)->id_list;
      int size;
      while(current != NULL)
      {
        if (current->vec_size == NOT_A_VECTOR)
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1;
              break;
            case INT:
              size = 4;
              break;
            case FLOAT:
              size = 8;
              break;
            default:
              size = -1;
          }
        }
        else
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1 * current->vec_size;
              break;
            case INT:
              size = 4 * current->vec_size;
              break;
            case FLOAT:
              size = 8 * current->vec_size;
              break;
            default:
              size = -1;
          }
        }

        symbol_entry* sb = new_symbol_entry(current->id, current->line, VAR, (yyvsp[-1].type), size, NULL, NULL);
        if (ht_lookup(sb->label, local_scope) != NULL)
        {
         syntactic_error(ERR_DECLARED, NULL, -1, ht_lookup(sb->label, local_scope));
        }
        ht_insert(sb, local_scope);
        current = current->next;
      }
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node;
    }
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 406 "parser.y" /* yacc.c:1646  */
    {
      // Get scope
      ht_entry** local_scope;
      local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      id_list* current = (yyvsp[0].prod)->id_list;
      int size;
      while(current != NULL)
      {
        if (current->vec_size == NOT_A_VECTOR)
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1;
              break;
            case INT:
              size = 4;
              break;
            case FLOAT:
              size = 8;
              break;
            default:
              size = -1;
          }
        }
        else
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1 * current->vec_size;
              break;
            case INT:
              size = 4 * current->vec_size;
              break;
            case FLOAT:
              size = 8 * current->vec_size;
              break;
            default:
              size = -1;
          }
        }

        symbol_entry* sb = new_symbol_entry(current->id, current->line, VAR, (yyvsp[-1].type), size, NULL, NULL);
        if (ht_lookup(sb->label, local_scope) != NULL)
        {
         syntactic_error(ERR_DECLARED, NULL, -1, sb);
        }
        ht_insert(sb, local_scope);
        current = current->next;
      }
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node;
    }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 472 "parser.y" /* yacc.c:1646  */
    {
      // Get scope
      ht_entry** local_scope;
      local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      id_list* current = (yyvsp[0].prod)->id_list;
      int size;
      while(current != NULL)
      {
        if (current->vec_size == NOT_A_VECTOR)
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1;
              break;
            case INT:
              size = 4;
              break;
            case FLOAT:
              size = 8;
              break;
            default:
              size = -1;
          }
        }
        else
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1 * current->vec_size;
              break;
            case INT:
              size = 4 * current->vec_size;
              break;
            case FLOAT:
              size = 8 * current->vec_size;
              break;
            default:
              size = -1;
          }
        }

        symbol_entry* sb = new_symbol_entry(current->id, current->line, VAR, (yyvsp[-1].type), size, NULL, NULL);
        if (ht_lookup(sb->label, local_scope) != NULL)
        {
         syntactic_error(ERR_DECLARED, NULL, -1, sb);
        }
        ht_insert(sb, local_scope);
        current = current->next;
      }
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node;
    }
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 538 "parser.y" /* yacc.c:1646  */
    {
      // Get scope
      ht_entry** local_scope;
      local_scope = pop(&scope_stack);

      if (local_scope == NULL)
      {
        printf("ERROR local scope is NULL\n");
        printf("id on top of id_list: %s\n", (yyvsp[0].prod)->id_list->id);
      }

      // Add locals to symbol table.
      id_list* current = (yyvsp[0].prod)->id_list;
      int size;
      while(current != NULL)
      {
        if (current->vec_size == NOT_A_VECTOR)
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1;
              break;
            case INT:
              size = 4;
              break;
            case FLOAT:
              size = 8;
              break;
            default:
              size = -1;
          }
        }
        else
        {
          switch ((yyvsp[-1].type))
          {
            case CHAR:
            case BOOL:
              size = 1 * current->vec_size;
              break;
            case INT:
              size = 4 * current->vec_size;
              break;
            case FLOAT:
              size = 8 * current->vec_size;
              break;
            default:
              size = -1;
          }
        }

        symbol_entry* sb = new_symbol_entry(current->id, current->line, VAR, (yyvsp[-1].type), size, NULL, NULL);
        if (ht_lookup(sb->label, local_scope) != NULL)
        {
         syntactic_error(ERR_DECLARED, NULL, -1, sb);
        }
        ht_insert(sb, local_scope);
        current = current->next;
      }
      push(&scope_stack, local_scope);

      (yyval.node) = (yyvsp[0].prod)->ast_node;
    }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 607 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_ids = malloc(sizeof(struct id_list_item));
      global_ids->id = (yyvsp[0].lex_val)->value.s;
      global_ids->line = (yyvsp[0].lex_val)->line;
      global_ids->vec_size = NOT_A_VECTOR;
      global_ids->next = NULL;
      (yyval.prod)->id_list = global_ids;

      (yyval.prod)->ast_node = NULL;
    }
#line 2134 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 618 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].prod)->id_list, (yyvsp[-2].lex_val), NOT_A_VECTOR);
      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list;

      if ((yyvsp[0].prod)->ast_node != NULL ) { (yyval.prod)->ast_node = (yyvsp[0].prod)->ast_node; } else { (yyval.prod)->ast_node = NULL; };
    }
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 625 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_ids = malloc(sizeof(struct id_list_item));
      global_ids->id = (yyvsp[-2].lex_val)->value.s;
      global_ids->line = (yyvsp[-2].lex_val)->line;
      global_ids->vec_size = NOT_A_VECTOR;
      global_ids->next = NULL;
      (yyval.prod)->id_list = global_ids;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.prod)->ast_node, 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
    }
#line 2160 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 636 "parser.y" /* yacc.c:1646  */
    {
      id_list* global_ids = malloc(sizeof(struct id_list_item));
      global_ids->id = (yyvsp[-2].lex_val)->value.s;
      global_ids->line = (yyvsp[-2].lex_val)->line;
      global_ids->vec_size = NOT_A_VECTOR;
      global_ids->next = NULL;
      (yyval.prod)->id_list = global_ids;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.prod)->ast_node, 2, lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].node));
    }
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 647 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR);
      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.prod)->ast_node, 3, lexval_node((yyvsp[-4].lex_val)), lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].prod)->ast_node);
    }
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 654 "parser.y" /* yacc.c:1646  */
    {
      add_id((yyvsp[0].prod)->id_list, (yyvsp[-4].lex_val), NOT_A_VECTOR);
      (yyval.prod)->id_list = (yyvsp[0].prod)->id_list;

      (yyval.prod)->ast_node = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.prod)->ast_node, 3, lexval_node((yyvsp[-4].lex_val)), (yyvsp[-2].node), (yyvsp[0].prod)->ast_node);
    }
#line 2197 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 664 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, CHAR,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 673 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, BOOL,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 682 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, FLOAT,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 691 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, INT,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2249 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 700 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, STR,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2262 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 709 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = lexval_node((yyvsp[0].lex_val));
      symbol_entry* new_lit = new_symbol_entry((yyval.node)->label, get_line_number(), LIT, BOOL,
                                              1, NULL, (yyvsp[0].lex_val));
      ht_entry** scope = pop(&scope_stack);
      ht_insert(new_lit, scope);
      push(&scope_stack, scope);
    }
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 721 "parser.y" /* yacc.c:1646  */
    {
      //printf("Antes do primeiro st_lookup em attrib.\n");
      symbol_entry* dst_lookup = st_lookup((yyvsp[-2].lex_val)->value.s, scope_stack);
      //printf("Depois do primeiro st_lookup em attrib.\n");
      symbol_entry* src_lookup = st_lookup((yyvsp[0].node)->label, scope_stack);
      // See if dst is declared.
      if (dst_lookup == NULL)
      {
        printf("Aqui22 \n");
        syntactic_error(ERR_UNDECLARED, (yyvsp[-2].lex_val)->value.s, get_line_number(), NULL);
      }

      // See if exp is declared.
      if (src_lookup == NULL && (yyvsp[0].node)->val != NULL)
      {
        printf("Aqui \n");
        syntactic_error(ERR_UNDECLARED, (yyvsp[0].node)->label, get_line_number(), NULL);
      }

      // Check types.
      if (dst_lookup->data_type != (yyvsp[0].node)->data_type)
      {
        syntactic_error(ERR_WRONG_TYPE, (yyvsp[-2].lex_val)->value.s, get_line_number(), dst_lookup);
      }

      // See if dst is a variable.
      else if (dst_lookup->symbol_type != VAR)
      {
        syntactic_error(ERR_VECTOR, (yyvsp[-2].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = named_node("="); add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), (yyvsp[0].node));
      (yyval.node)->children[0]->data_type = dst_lookup->data_type;
    }
#line 2314 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 756 "parser.y" /* yacc.c:1646  */
    {
      symbol_entry* dst_lookup = st_lookup((yyvsp[-5].lex_val)->value.s, scope_stack);
      symbol_entry* src_lookup = st_lookup((yyvsp[0].node)->label, scope_stack);
      // See if dst is declared.
      if (dst_lookup == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-5].lex_val)->value.s, get_line_number(), NULL);
      }

      // See if src is declared.
      if (src_lookup == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[0].node)->label, get_line_number(), NULL);
      }

      // Check types.
      if (dst_lookup->data_type != (yyvsp[-3].node)->data_type)
      {
        syntactic_error(ERR_WRONG_TYPE, (yyvsp[-5].lex_val)->value.s, get_line_number(), dst_lookup);
      }

      // See if dst is a vector.
      else if (dst_lookup->symbol_type != VEC)
      {
        syntactic_error(ERR_VARIABLE, (yyvsp[-5].lex_val)->value.s, get_line_number(), NULL);
      }

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node));
      (yyval.node) = named_node("="); add_children((yyval.node), 2, vector, (yyvsp[0].node));
    }
#line 2350 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 791 "parser.y" /* yacc.c:1646  */
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
#line 2368 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 805 "parser.y" /* yacc.c:1646  */
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
#line 2386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 819 "parser.y" /* yacc.c:1646  */
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
#line 2404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 836 "parser.y" /* yacc.c:1646  */
    {
      // Check if function is declared.
      //printf("Antes do st_lookup em func_call.\n");
      symbol_entry* lookup_res = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);

      if (lookup_res == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
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

      arg_list* table_entry_arg = lookup_res->args;
      arg_list* call_arg = (yyvsp[-1].prod)->arg_list;
      do
      {
        if (table_entry_arg->type != call_arg->type)
        {
          syntactic_error(ERR_WRONG_TYPE_ARGS, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
        }
        table_entry_arg = table_entry_arg->next;
        call_arg = call_arg->next;
      } while (table_entry_arg != NULL && call_arg != NULL);


      (yyval.node) = lexval_node((yyvsp[-3].lex_val)); add_children((yyval.node), 1, (yyvsp[-1].prod)->ast_node);
      (yyval.node)->data_type = lookup_res->data_type;
    }
#line 2445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 876 "parser.y" /* yacc.c:1646  */
    {
      //printf(" 1 Endereco de $1: %p - Endereco de $$: %p\n", &$1, &$$);
      arg_list* exp_list = malloc(sizeof(struct arg_list_item));

      if ((yyvsp[0].node)->val != NULL)
      {
        //printf("exp_list: exp $1->val != NULL.\n");
        exp_list->id = (yyvsp[0].node)->val->value.s;
        //printf("exp_list->id: %s\n", exp_list->id);
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
        //printf("else sozinho da exp_list: exp\n");
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


      // printf("Antes das atribs a kbca em exp_list: exp, cif1->label: %s\n", $1->label);
      //printf(" 2 Endereco de $1: %p - Endereco de $$: %p\n", &$1, &$$);
      //$$->ast_node = $1; // Isso aqui de alguma maneira poe lixo em $1->label.
      //$$->arg_list = exp_list;
      // printf("No final de exp_list: exp, cif1->label: %s\n", $1->label);
      // printf("Em exp_list: exp, kbca->ast_node->label: %s\n", $$->ast_node->label);
      // printf("No final, exp_list->id: %s\n", exp_list->id);
    }
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 924 "parser.y" /* yacc.c:1646  */
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
#line 2540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 962 "parser.y" /* yacc.c:1646  */
    { (yyval.prod)->ast_node = NULL; (yyval.prod)->arg_list = NULL; }
#line 2546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 967 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-2].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-2].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = lexval_node((yyvsp[-1].lex_val));
      add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
      (yyval.node)->children[0]->data_type = lookup_result->data_type;
    }
#line 2566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 983 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-2].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-2].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = lexval_node((yyvsp[-1].lex_val));
      add_children((yyval.node), 2, lexval_node((yyvsp[-2].lex_val)), lexval_node((yyvsp[0].lex_val)));
    }
#line 2585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 998 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = lexval_node((yyvsp[-2].lex_val));
      add_children((yyval.node), 2, lexval_node((yyvsp[-3].lex_val)), lexval_node((yyvsp[0].lex_val)));
    }
#line 2604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1013 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }

      (yyval.node) = lexval_node((yyvsp[-2].lex_val));
      add_children((yyval.node), 2, lexval_node((yyvsp[-3].lex_val)), lexval_node((yyvsp[0].lex_val)));
    }
#line 2623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1028 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-5].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-5].lex_val)->value.s, get_line_number(), NULL);
      }

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node));
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1044 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-5].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-5].lex_val)->value.s, get_line_number(), NULL);
      }

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-5].lex_val)), (yyvsp[-3].node));
      (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-6].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-6].lex_val)->value.s, get_line_number(), NULL);
      }

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-6].lex_val)), (yyvsp[-4].node));
      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1076 "parser.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].lex_val)->value.i > 16)
      {
        syntactic_error(ERR_WRONG_PAR_SHIFT, NULL, get_line_number(), NULL);
      }
      symbol_entry* lookup_result = st_lookup((yyvsp[-6].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-6].lex_val)->value.s, get_line_number(), NULL);
      }

      node* vector = named_node("[]");
      add_children(vector, 2, lexval_node((yyvsp[-6].lex_val)), (yyvsp[-4].node));
      (yyval.node) = lexval_node((yyvsp[-2].lex_val)); add_children((yyval.node), 2, vector, lexval_node((yyvsp[0].lex_val)));
    }
#line 2703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("return"); add_children((yyval.node), 1, (yyvsp[0].node));
      (yyval.node)->data_type = (yyvsp[0].node)->data_type;
      //printf("Em jmp_stmt, $$->data_type: %d\n", $$->data_type);
      (yyval.node)->is_return = 1;
      (yyval.node)->return_line = get_line_number();
    }
#line 2715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1102 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("break"); }
#line 2721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1103 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("continue"); }
#line 2727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1107 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1108 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1109 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1114 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = named_node("if");
        add_children((yyval.node), 3, (yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 2754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = named_node("if");
        add_children((yyval.node), 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1127 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = named_node("for");
        add_children((yyval.node), 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1135 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = named_node("while");
        add_children((yyval.node), 2, (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 2781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1143 "parser.y" /* yacc.c:1646  */
    {
      //printf(" 0 Endereco de $1: %p - Endereco de $$: %p\n", $1, $$);
      //printf("Antes de chamar st_lookup em exp: TK_IDENTIFICADOR, linha %d.\n", get_line_number());
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
      //printf("Em exp: TK_ID, $$->label: %s\n", $$->label);
    }
#line 2805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1163 "parser.y" /* yacc.c:1646  */
    {
      symbol_entry* lookup_result = st_lookup((yyvsp[-3].lex_val)->value.s, scope_stack);
      if(lookup_result == NULL)
      {
        syntactic_error(ERR_UNDECLARED, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
      }
      else if (lookup_result->symbol_type != VEC)
      {
        syntactic_error(ERR_VARIABLE, (yyvsp[-3].lex_val)->value.s, get_line_number(), NULL);
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
#line 2833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1186 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1187 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 2853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1192 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1193 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); add_children((yyval.node), 1, (yyvsp[0].node)); (yyval.node)->data_type = (yyvsp[0].node)->data_type;}
#line 2865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1195 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1200 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1205 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2901 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1215 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1220 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1225 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1230 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("+"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->data_type = get_data_type((yyvsp[-2].node), (yyvsp[0].node), get_line_number());
    }
#line 2937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1235 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node) = named_node("<"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL;
    }
#line 2945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1238 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node(">"); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1240 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1241 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1242 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1243 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2981 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1244 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[-1].lex_val)); add_children((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->data_type = BOOL; }
#line 2987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1246 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = named_node("?:");
        add_children((yyval.node), 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        if ((yyvsp[-4].node)->data_type != BOOL && (yyvsp[-4].node)->data_type != INT
          	&& (yyvsp[-4].node)->data_type != FLOAT)
          syntactic_error(ERR_WRONG_TYPE, NULL, get_line_number(), NULL);
    }
#line 2999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
      char float_to_str[7];
      gcvt((yyvsp[0].lex_val)->value.f, 4, float_to_str);
      // Check if literal already on table.
      //printf("Antes de chamar st_lookup em num.\n");
      symbol_entry* sb = st_lookup(float_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        sb = new_symbol_entry(float_to_str, get_line_number(), LIT, FLOAT, 8, NULL, (yyvsp[0].lex_val));
        ht_entry** scope = pop(&scope_stack);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }
      (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = FLOAT;
    }
#line 3021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1275 "parser.y" /* yacc.c:1646  */
    {
      int len = snprintf(NULL, 0, "%d", (yyvsp[0].lex_val)->value.i) + 1;
      char* int_to_str = malloc(len);
      snprintf(int_to_str, len, "%d", (yyvsp[0].lex_val)->value.i);
      // Check if literal already on table.
      symbol_entry* sb = st_lookup(int_to_str, scope_stack);
      if (sb == NULL)
      {
        // If not, put it.
        sb = new_symbol_entry(int_to_str, get_line_number(), LIT, INT, 4, NULL, (yyvsp[0].lex_val));
        ht_entry** scope = pop(&scope_stack);
        if (scope == NULL) printf("Scope is null on num.\n");
        ht_insert(sb, scope);
        push(&scope_stack, scope);
      }

      (yyval.node) = lexval_node((yyvsp[0].lex_val)); (yyval.node)->data_type = INT;
    }
#line 3044 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1296 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("+"); }
#line 3050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1297 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("-"); }
#line 3056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1298 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("!"); }
#line 3062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1299 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("&"); }
#line 3068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1300 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("*"); }
#line 3074 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1301 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("?"); }
#line 3080 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1302 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = named_node("#"); }
#line 3086 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1306 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[0].lex_val)); }
#line 3092 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1307 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = lexval_node((yyvsp[0].lex_val)); }
#line 3098 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3102 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1310 "parser.y" /* yacc.c:1906  */


void yyerror(char const *s) {
    fprintf(stderr, "%s on line %d at column %d\n",\
            s, get_line_number(), get_col());
}

