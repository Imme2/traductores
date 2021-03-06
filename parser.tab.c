/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */




#include <cstdio>
#include <iostream>
#include "declaraciones.c"
#include "instrucciones.c"
#include "expresion.c"
#include "arbolSintactico.c"
#include "listaids.c"

using namespace std;


extern int yylex(void);

ArbolSintactico *raiz;

void yyerror(char const*);


#line 89 "parser.tab.c" /* yacc.c:339  */

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
    NUM = 258,
    ID = 259,
    CARACTER = 260,
    TOKEN_TRUE = 261,
    TOKEN_FALSE = 262,
    TOKEN_PUNTO = 263,
    TOKEN_DOSPUNT = 264,
    TOKEN_PARABRE = 265,
    TOKEN_PARCIERRA = 266,
    TOKEN_SUMA = 267,
    TOKEN_RESTA = 268,
    TOKEN_MULT = 269,
    TOKEN_DIV = 270,
    TOKEN_MOD = 271,
    TOKEN_CONJ = 272,
    TOKEN_DISY = 273,
    TOKEN_NEG = 274,
    TOKEN_MENOR = 275,
    TOKEN_MAYOR = 276,
    TOKEN_MENORIG = 277,
    TOKEN_MAYORIG = 278,
    TOKEN_CREATE = 279,
    TOKEN_WHILE = 280,
    TOKEN_BOOL = 281,
    TOKEN_INT = 282,
    TOKEN_CHAR = 283,
    TOKEN_IF = 284,
    TOKEN_ELSE = 285,
    TOKEN_SEND = 286,
    TOKEN_EXECUTE = 287,
    TOKEN_ON = 288,
    TOKEN_STORE = 289,
    TOKEN_BOT = 290,
    TOKEN_DESIGUAL = 291,
    TOKEN_IGUAL = 292,
    TOKEN_COMA = 293,
    TOKEN_DEFAULT = 294,
    TOKEN_COLLECT = 295,
    TOKEN_DROP = 296,
    TOKEN_UP = 297,
    TOKEN_DOWN = 298,
    TOKEN_RIGHT = 299,
    TOKEN_LEFT = 300,
    TOKEN_READ = 301,
    TOKEN_AS = 302,
    TOKEN_RECEIVE = 303,
    TOKEN_ADVANCE = 304,
    TOKEN_ACTIVATE = 305,
    TOKEN_ACTIVATION = 306,
    TOKEN_DEACTIVATE = 307,
    TOKEN_DEACTIVATION = 308,
    TOKEN_END = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

	int value;
	char name[200];
	Expresion *exp;
	Instruccion *inst;
	Declaracion *decl;
	ListaIDs *idl;
	InstruccionRobot *instRobot;
	Comport * comp;

#line 195 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "parser.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    75,    76,    79,    80,    83,    84,
      85,    88,    89,    92,    93,    96,    97,    98,   101,   102,
     105,   106,   107,   108,   109,   110,   113,   116,   117,   120,
     123,   126,   127,   130,   133,   134,   135,   136,   139,   142,
     143,   146,   147,   148,   149,   150,   151,   154,   157,   158,
     161,   164,   167,   171,   174,   177,   178,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "CARACTER", "TOKEN_TRUE",
  "TOKEN_FALSE", "TOKEN_PUNTO", "TOKEN_DOSPUNT", "TOKEN_PARABRE",
  "TOKEN_PARCIERRA", "TOKEN_SUMA", "TOKEN_RESTA", "TOKEN_MULT",
  "TOKEN_DIV", "TOKEN_MOD", "TOKEN_CONJ", "TOKEN_DISY", "TOKEN_NEG",
  "TOKEN_MENOR", "TOKEN_MAYOR", "TOKEN_MENORIG", "TOKEN_MAYORIG",
  "TOKEN_CREATE", "TOKEN_WHILE", "TOKEN_BOOL", "TOKEN_INT", "TOKEN_CHAR",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_SEND", "TOKEN_EXECUTE", "TOKEN_ON",
  "TOKEN_STORE", "TOKEN_BOT", "TOKEN_DESIGUAL", "TOKEN_IGUAL",
  "TOKEN_COMA", "TOKEN_DEFAULT", "TOKEN_COLLECT", "TOKEN_DROP", "TOKEN_UP",
  "TOKEN_DOWN", "TOKEN_RIGHT", "TOKEN_LEFT", "TOKEN_READ", "TOKEN_AS",
  "TOKEN_RECEIVE", "TOKEN_ADVANCE", "TOKEN_ACTIVATE", "TOKEN_ACTIVATION",
  "TOKEN_DEACTIVATE", "TOKEN_DEACTIVATION", "TOKEN_END", "$accept",
  "PROGRAMA", "CREATE", "SECUENCIA_DECLAR", "DECLARATION", "TIPO",
  "SECUENCIA_COMPORT", "COMPORTAMIENTO", "CONDITION",
  "SECUENCIA_ROBOTINSTR", "ROBOTINSTR", "STORE", "COLLECT", "DROP", "MOVE",
  "READ", "SEND", "DIRECTION", "EXECUTE", "SECUENCIA_INSTRUC",
  "INSTRUCCION", "CONDICIONAL", "ELSE", "ACTIVATE", "ADVANCE",
  "DEACTIVATE", "LOOP", "INCORPALCANCE", "LISTA_IDS", "EXPRESSION", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    11,     7,   -18,  -102,  -102,  -102,    11,  -102,   -17,
    -102,   102,  -102,  -102,    13,   266,   266,    13,    13,    13,
     -18,    30,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
     -25,  -102,  -102,  -102,  -102,  -102,   266,   266,   266,    97,
     123,    -5,    -3,    -2,  -102,  -102,  -102,    21,    16,  -102,
     -24,  -102,   176,   166,  -102,   102,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   102,
    -102,  -102,  -102,  -102,  -102,  -102,     6,   149,  -102,  -102,
    -102,  -102,    42,   166,   166,    -6,    -6,    -6,  -102,    45,
     214,   214,   202,   202,   161,   161,    73,   246,   246,  -102,
      54,    10,  -102,   266,    18,   266,  -102,  -102,  -102,  -102,
      22,   203,  -102,    62,    65,    68,    69,    70,    75,   266,
     221,   102,  -102,   188,    77,   188,    81,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,   188,  -102,   102,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     8,     9,    10,     3,     5,     0,
       1,     0,     2,     4,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    44,    42,    41,    43,    45,    46,    55,
       0,    73,    76,    77,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    38,    40,     0,     0,     7,
       0,    12,     0,    59,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    50,    52,    17,    15,    16,     0,     0,    56,     6,
      11,    57,     0,    68,    70,    69,    71,    72,    66,    67,
      60,    61,    62,    63,    65,    64,    49,     0,     0,    53,
       0,     0,    33,     0,    27,     0,    34,    35,    37,    36,
      31,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    26,     0,    29,     0,    13,    18,    20,
      21,    22,    23,    24,    25,    30,    14,    48,    28,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,    86,  -102,    80,  -102,  -102,    43,  -102,    -9,
    -101,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    79,   -53,
     -21,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    39,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    20,     7,     8,     9,    50,    51,    76,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    12,    21,
      22,    23,   101,    24,    25,    26,    27,    28,    30,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    40,    82,    70,     1,    71,    72,    10,    47,    47,
     128,    61,    62,    48,    11,    97,    96,    29,    14,   128,
      78,    52,    53,    54,    31,    32,    33,    34,    35,    49,
      79,    36,    77,    48,    37,    48,    48,     4,     5,     6,
      38,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     1,    15,    41,    42,    43,    16,
      73,    46,    61,   121,   122,   124,     1,    15,   137,   126,
     129,    16,    74,   130,    75,    46,   131,   132,   133,    17,
      18,   138,    19,   134,    45,   139,     3,    13,   123,   120,
     125,    17,    18,    80,    19,     0,    99,     1,    15,    44,
       0,     0,    16,   100,   135,     0,    55,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    46,    63,    64,    65,
      66,     0,    17,    18,     0,    19,     1,    15,     0,     0,
       0,    16,    69,    67,    68,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,     0,     0,     0,
       0,    17,    18,     0,    19,     0,     0,     0,    98,    67,
      68,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    56,    57,    58,    59,    60,    61,    62,
      58,    59,    60,    61,    62,    67,    68,    81,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    67,    68,    56,    57,    58,    59,
      60,    61,    62,     0,   102,     0,     0,   103,    67,    68,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
      67,    68,   102,     0,     0,   103,     0,   127,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,     0,    31,
      32,    33,    34,    35,     0,   136,    36,   102,     0,    37,
     103,     0,     0,     0,     0,    38,   104,   105,   106,   107,
     108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      21,    16,    55,     8,    24,     8,     8,     0,    33,    33,
     111,    17,    18,    38,    32,     9,    69,     4,    35,   120,
       4,    36,    37,    38,     3,     4,     5,     6,     7,    54,
      54,    10,    47,    38,    13,    38,    38,    26,    27,    28,
      19,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    24,    25,    17,    18,    19,    29,
      39,    82,    17,     9,    54,    47,    24,    25,   121,    47,
       8,    29,    51,     8,    53,    96,     8,     8,     8,    49,
      50,     4,    52,     8,    54,     4,     0,     7,   103,    98,
     105,    49,    50,    50,    52,    -1,    54,    24,    25,    20,
      -1,    -1,    29,    30,   119,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,   137,    20,    21,    22,
      23,    -1,    49,    50,    -1,    52,    24,    25,    -1,    -1,
      -1,    29,     9,    36,    37,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    -1,    -1,     9,    36,
      37,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    12,    13,    14,    15,    16,    17,    18,
      14,    15,    16,    17,    18,    36,    37,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    36,    37,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    36,    37,    12,    13,    14,    15,
      16,    17,    18,    -1,    31,    -1,    -1,    34,    36,    37,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      36,    37,    31,    -1,    -1,    34,    -1,    54,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,     3,
       4,     5,     6,     7,    -1,    54,    10,    31,    -1,    13,
      34,    -1,    -1,    -1,    -1,    19,    40,    41,    42,    43,
      44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    56,    57,    26,    27,    28,    58,    59,    60,
       0,    32,    73,    59,    35,    25,    29,    49,    50,    52,
      57,    74,    75,    76,    78,    79,    80,    81,    82,     4,
      83,     3,     4,     5,     6,     7,    10,    13,    19,    84,
      84,    83,    83,    83,    73,    54,    75,    33,    38,    54,
      61,    62,    84,    84,    84,     9,    12,    13,    14,    15,
      16,    17,    18,    20,    21,    22,    23,    36,    37,     9,
       8,     8,     8,    39,    51,    53,    63,    84,     4,    54,
      62,    11,    74,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    74,     9,     9,    54,
      30,    77,    31,    34,    40,    41,    42,    43,    44,    45,
      46,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      64,     9,    54,    84,    47,    84,    47,    54,    65,     8,
       8,     8,     8,     8,     8,    84,    54,    74,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      69,    70,    70,    71,    72,    72,    72,    72,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    76,    77,    77,
      78,    79,    80,    81,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     5,     4,     1,     1,
       1,     2,     1,     5,     5,     1,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     6,     3,     0,
       3,     3,     3,     5,     2,     1,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 69 "parser.y" /* yacc.c:1646  */
    {raiz = new ArbolSintactico((yyvsp[-1].decl),(yyvsp[0].inst),yylloc.first_line);}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl);}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.decl) = new SecuenciaDeclaraciones((yyvsp[-1].decl),(yyvsp[0].decl),yylloc.first_line);}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.decl) = new SecuenciaDeclaraciones((yyvsp[0].decl),yylloc.first_line);}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.decl) = new DeclaracionRobot((yyvsp[-4].value),(yyvsp[-2].idl),(yyvsp[-1].comp),yylloc.first_line);}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.decl) = new DeclaracionRobot((yyvsp[-3].value),(yyvsp[-1].idl),NULL,yylloc.first_line);}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 0;}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 1;}
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 2;}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.comp) = new SecuenciaComportamiento((yyvsp[-1].comp),(yyvsp[0].comp),yylloc.first_line);}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.comp) = new SecuenciaComportamiento((yyvsp[0].comp),yylloc.first_line);}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.comp) = new Comportamiento((yyvsp[-3].value),NULL,(yyvsp[-1].instRobot),yylloc.first_line);}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.comp) = new Comportamiento(0,(yyvsp[-3].exp),(yyvsp[-1].instRobot),yylloc.first_line);}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 1;}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 2;}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 3;}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.instRobot) = new SecuenciaRoboInstruccion((yyvsp[-1].instRobot),(yyvsp[0].instRobot),yylloc.first_line);}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.instRobot) = new SecuenciaRoboInstruccion((yyvsp[0].instRobot),yylloc.first_line);}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = (yyvsp[-1].instRobot);}
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Almacenamiento((yyvsp[0].exp),yylloc.first_line);}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Coleccion(yylloc.first_line);}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Coleccion(string((yyvsp[0].name)),yylloc.first_line);}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Soltado((yyvsp[0].exp),yylloc.first_line);}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Movimiento((yyvsp[-1].value),(yyvsp[0].exp),yylloc.first_line);}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Leer(yylloc.first_line);}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.instRobot) = new Leer(string((yyvsp[0].name)),yylloc.first_line);}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.instRobot) = new Escribir(yylloc.first_line);}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 0;}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 1;}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 2;}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.value) = 3;}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[-1].inst);}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new SecuenciaInstrucciones((yyvsp[0].inst),yylloc.first_line);}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new SecuenciaInstrucciones((yyvsp[-1].inst),(yyvsp[0].inst),yylloc.first_line);}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new Condicional((yyvsp[-4].exp),(yyvsp[-2].inst),(yyvsp[-1].inst),yylloc.first_line);}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = NULL;}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.inst) = new ActivateInst((yyvsp[-1].idl),yylloc.first_line);}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new AdvanceInst((yyvsp[-1].idl),yylloc.first_line);}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new DeactivateInst((yyvsp[-1].idl),yylloc.first_line);}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new LoopInst((yyvsp[-3].exp),(yyvsp[-1].inst),yylloc.first_line);}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.inst) = new IncorpAlcance((yyvsp[-1].decl),(yyvsp[0].inst),yylloc.first_line);}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.idl) = new ListaIDs(string((yyvsp[0].name)),yylloc.first_line);}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.idl) = new ListaIDs((yyvsp[-2].idl),string((yyvsp[0].name)),yylloc.first_line);}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[-1].exp);}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("NEGACION",(yyvsp[0].exp),yylloc.first_line);}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("RESTA",(yyvsp[0].exp),yylloc.first_line);}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MENOR",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MAYOR",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MENORIGUAL",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MAYORIGUAL",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("IGUAL",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("DESIGUAL",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("CONJUNCION",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("DISYUNCION",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("SUMA",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MULTIPLICACION",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("RESTA",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("DIVISION",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion("MODULO",(yyvsp[-2].exp),(yyvsp[0].exp),yylloc.first_line);}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion((yyvsp[0].value),1,yylloc.first_line);}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion(true,0,yylloc.first_line);}
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion(false,0,yylloc.first_line);}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion(string((yyvsp[0].name)),3,yylloc.first_line);}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = new Expresion(string((yyvsp[0].name)),2,yylloc.first_line);}
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1986 "parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 206 "parser.y" /* yacc.c:1906  */



void yyerror(char const* s){
	cout <<"En la fila:" << yylloc.first_line << ", columna" << yylloc.first_column;
	cout <<"ocurrio: " << s << endl;
}
