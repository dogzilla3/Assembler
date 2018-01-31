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
#line 1 "paspar.y" /* yacc.c:339  */


/*
 * -------------------------------------------------------------------------
 * Author: Gregory Levy
 * Student ID: *20444120
 * E-Mail: glevy@uco.edu
 * Course: CMSC 4173  Translator Design
 * CRN: 25838, Spring, 2018
 * Project: p02 - Subset Pascal Parser
 * Due: January 24, 2018
 * Account: tt072
 *
 * Author: William Bohanan
 * Student ID: *20276952
 * E-Mail: wbohanan@uco.edu
 * Course: CMSC 4173  Translator Design
 * CRN: 25838, Spring, 2018
 * Project: p02 - Subset Pascal Parser
 * Due: January 24, 2018
 * Account: tt067
 * -------------------------------------------------------------------------
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "paslex.h"
#include "paspar.h"
#include "List.h"
#include "identifier_list.h"

extern ofstream fout;
extern int line;
extern int col;

using namespace std;

void yyerror(const char* m);

#line 110 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PLUS = 258,
    MINUS = 259,
    STAR = 260,
    SLASH = 261,
    ASSIGN = 262,
    PERIOD = 263,
    COMMA = 264,
    SEMICOLON = 265,
    COLON = 266,
    EQU = 267,
    NEQ = 268,
    LES = 269,
    LEQ = 270,
    GRT = 271,
    GEQ = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACKET = 275,
    RBRACKET = 276,
    RANGE = 277,
    RESERVE_WORDS = 278,
    AND = 279,
    ARRAY = 280,
    BEGIN_ = 281,
    DIV = 282,
    DO = 283,
    ELSE = 284,
    END = 285,
    FUNCTION = 286,
    IF = 287,
    MOD = 288,
    NOT = 289,
    OF = 290,
    OR = 291,
    PROCEDURE = 292,
    PROGRAM = 293,
    THEN = 294,
    TO = 295,
    TYPE = 296,
    VAR = 297,
    WHILE = 298,
    REGULAR_EXPRESSIONS = 299,
    ID = 300,
    INTLIT = 301,
    REALIT = 302,
    CHRLIT = 303,
    COMMENT = 304
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define SLASH 261
#define ASSIGN 262
#define PERIOD 263
#define COMMA 264
#define SEMICOLON 265
#define COLON 266
#define EQU 267
#define NEQ 268
#define LES 269
#define LEQ 270
#define GRT 271
#define GEQ 272
#define LPAREN 273
#define RPAREN 274
#define LBRACKET 275
#define RBRACKET 276
#define RANGE 277
#define RESERVE_WORDS 278
#define AND 279
#define ARRAY 280
#define BEGIN_ 281
#define DIV 282
#define DO 283
#define ELSE 284
#define END 285
#define FUNCTION 286
#define IF 287
#define MOD 288
#define NOT 289
#define OF 290
#define OR 291
#define PROCEDURE 292
#define PROGRAM 293
#define THEN 294
#define TO 295
#define TYPE 296
#define VAR 297
#define WHILE 298
#define REGULAR_EXPRESSIONS 299
#define ID 300
#define INTLIT 301
#define REALIT 302
#define CHRLIT 303
#define COMMENT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 45 "paspar.y" /* yacc.c:355  */
 std::string* token;
  SList<string>* strList;

#line 252 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   102,   106,   110,   114,   117,   121,   125,
     130,   135,   138,   142,   146,   150,   154,   157,   161,   165,
     169,   173,   176,   180,   184,   188,   192,   195,   199,   203,
     207,   211,   215,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   279,   283,
     287,   291,   295,   299,   303,   307,   311,   315,   319,   323,
     327,   331,   335,   339,   343,   347,   351,   355,   359,   363,
     367,   371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "STAR", "SLASH",
  "ASSIGN", "PERIOD", "COMMA", "SEMICOLON", "COLON", "EQU", "NEQ", "LES",
  "LEQ", "GRT", "GEQ", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "RANGE",
  "RESERVE_WORDS", "AND", "ARRAY", "BEGIN_", "DIV", "DO", "ELSE", "END",
  "FUNCTION", "IF", "MOD", "NOT", "OF", "OR", "PROCEDURE", "PROGRAM",
  "THEN", "TO", "TYPE", "VAR", "WHILE", "REGULAR_EXPRESSIONS", "ID",
  "INTLIT", "REALIT", "CHRLIT", "COMMENT", "$accept", "program",
  "program_head", "program_declarations", "program_body",
  "program_parameters", "program_parameter_list", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "subprogram_head", "subprogram_parameters",
  "parameter_list", "compound_statement", "optional_statements",
  "statement_list", "statement", "variable", "procedure_statement",
  "expression_list", "expression", "relop", "simple_expression", "sign",
  "addop", "term", "mulop", "factor", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -36

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -21,   -27,    27,  -112,    10,  -112,     6,    11,    18,    64,
      40,  -112,    72,    18,   -15,  -112,    60,    77,  -112,     3,
       3,    71,  -112,    57,    83,  -112,    87,  -112,  -112,    59,
      50,    52,    86,  -112,  -112,    53,  -112,  -112,     3,    13,
      51,  -112,  -112,  -112,    61,    26,    13,    49,  -112,    73,
       3,     3,  -112,    40,     3,     0,    84,    84,  -112,   -16,
    -112,    80,  -112,     3,     3,    40,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,     3,    13,    49,  -112,  -112,
    -112,  -112,  -112,    13,    40,     4,  -112,    82,  -112,  -112,
      85,  -112,    94,  -112,    18,    95,    97,  -112,  -112,     5,
      88,    89,     8,    49,  -112,  -112,     3,  -112,  -112,    65,
    -112,    66,    46,    67,  -112,  -112,  -112,    40,  -112,    91,
       0,    18,  -112,   100,  -112,    68,  -112,    81,  -112,    96,
       0,    90,  -112,    67,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     6,     1,     0,    16,     0,     0,
      26,     2,     0,     0,     4,     9,     0,     8,     3,     0,
       0,    37,    32,     0,    27,    28,     0,    31,     5,     0,
       0,     0,     0,    11,     7,     0,    52,    53,     0,     0,
      64,    69,    70,    71,     0,    41,     0,    49,    57,     0,
       0,     0,    25,     0,     0,     0,    21,    21,    17,     0,
      10,     0,    68,     0,     0,     0,    54,    55,    43,    44,
      45,    46,    47,    48,    56,     0,     0,    50,    59,    60,
      63,    61,    62,     0,     0,     0,    39,     0,    29,    30,
       0,    15,     0,    13,     0,     0,     0,    18,    67,     0,
       0,     0,    42,    51,    58,    34,     0,    38,    36,     0,
      12,     0,     0,     0,    20,    66,    65,     0,    40,     0,
       0,     0,    22,     0,    33,     0,    23,     0,    19,     0,
       0,     0,    24,     0,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,  -112,  -112,  -112,  -112,  -112,   -13,    93,  -111,
     -49,  -112,  -112,  -112,    58,  -112,    -2,  -112,  -112,   -50,
    -112,  -112,    56,   -18,  -112,    41,  -112,  -112,   -41,  -112,
     -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    11,     9,    16,    17,     7,    92,
      93,    14,    32,    33,    95,   112,    22,    23,    24,    25,
      26,    27,    85,    86,    75,    45,    46,    76,    47,    83,
      48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    44,    49,    88,    12,    77,    36,    37,    62,   126,
      10,    66,    67,   106,   106,   101,    30,     1,     4,   132,
      61,    38,    31,   107,   115,    90,    13,     5,     8,    66,
      67,    38,    10,    87,   105,   103,    89,    39,    68,    69,
      70,    71,    72,    73,    74,    91,   100,    39,    40,    41,
      42,    43,   104,    13,    78,    79,   121,    97,    40,    41,
      42,    43,    74,    15,   123,   122,    10,   124,    35,    63,
      55,    64,    19,    80,    18,    35,    81,   120,   -35,    34,
      28,   111,    82,    20,   134,    21,    35,    52,   118,    50,
      35,    51,   130,    53,    54,    56,    58,    57,    60,    98,
      65,    84,    94,   108,   110,   109,   113,   114,   127,   116,
     128,   119,    91,   125,   129,    96,   102,   131,   117,    99,
       0,     0,     0,     0,     0,   133,    59
};

static const yytype_int16 yycheck[] =
{
      13,    19,    20,    53,     6,    46,     3,     4,    39,   120,
      26,     3,     4,     9,     9,    65,    31,    38,    45,   130,
      38,    18,    37,    19,    19,    25,    42,     0,    18,     3,
       4,    18,    26,    51,    84,    76,    54,    34,    12,    13,
      14,    15,    16,    17,    36,    45,    64,    34,    45,    46,
      47,    48,    83,    42,     5,     6,    10,    59,    45,    46,
      47,    48,    36,    45,   113,    19,    26,   117,     9,    18,
      11,    20,    32,    24,    10,     9,    27,    11,     7,    19,
       8,    94,    33,    43,   133,    45,     9,    30,   106,    18,
       9,    20,    11,    10,     7,    45,    10,    45,    45,    19,
      39,    28,    18,    21,    10,    20,    11,    10,   121,    21,
      10,    46,    45,    22,    46,    57,    75,    21,    29,    63,
      -1,    -1,    -1,    -1,    -1,    35,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    51,    52,    45,     0,    53,    58,    18,    55,
      26,    54,    66,    42,    61,    45,    56,    57,    10,    32,
      43,    45,    66,    67,    68,    69,    70,    71,     8,    57,
      31,    37,    62,    63,    19,     9,     3,     4,    18,    34,
      45,    46,    47,    48,    73,    75,    76,    78,    80,    73,
      18,    20,    30,    10,     7,    11,    45,    45,    10,    58,
      45,    73,    80,    18,    20,    39,     3,     4,    12,    13,
      14,    15,    16,    17,    36,    74,    77,    78,     5,     6,
      24,    27,    33,    79,    28,    72,    73,    73,    69,    73,
      25,    45,    59,    60,    18,    64,    64,    66,    19,    72,
      73,    69,    75,    78,    80,    69,     9,    19,    21,    20,
      10,    57,    65,    11,    10,    19,    21,    29,    73,    46,
      11,    10,    19,    60,    69,    22,    59,    57,    10,    46,
      11,    21,    59,    35,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     2,     0,     3,     1,     1,
       3,     0,     6,     1,     8,     1,     0,     3,     3,     6,
       4,     0,     3,     3,     5,     3,     0,     1,     1,     3,
       3,     1,     1,     6,     4,     1,     4,     1,     4,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     2,     1,
       1,     1
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
#line 99 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#01 program -> program_head program_declarations program_body";
	}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#02 program_head -> program ID(" << (*(yyvsp[-2].token)) << ") program_parameters SEMICOLON";
	}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 107 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#03 program_declarations -> declarations subprogram_declarations";
	}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 111 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#04 program_body -> compound_statement PERIOD";
	}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#05 program_parameters -> EMPTY";
	}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#06 program_parameters -> ( program_parameters )";
	}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#07 program_parameter_list -> identifier_list";
	}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#08 identifier_list -> ID(" << (*(yyvsp[0].token)) << ")";
	(yyval.strList)=id_list((yyvsp[0].token));
	}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 131 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#09 identifier_list -> identifier_list , ID(" << (*(yyvsp[0].token)) << ")";
	(yyval.strList)=id_list((yyvsp[-2].strList),(yyvsp[0].token));
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 135 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#10 declarations -> EMPTY";
	}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#11 declarations -> declarations VAR identifier_list " << ((yyvsp[-3].strList))->printList() << " : type SEMICOLON";
	}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#12 type -> standard_type";
	}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#13 type -> array [ intlit .. intlit ] of standard_type";
	}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#14 standard_type -> ID(" << (*(yyvsp[0].token)) << ")";
	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#15 subprogram_declarations -> EMPTY";
	}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#16 subprogram_declarations -> subprogram_declarations subprogram_declaration ;";
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#17 subprogram_declarations -> subprogram_head declarations compound_statement";
	}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#18 subprogram_head -> function ID(" << (*(yyvsp[-4].token)) << ") subprogram_parameters : standard_type ;";
	}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#19 subprogram_head -> procedure ID(" << (*(yyvsp[-2].token)) << ") subprogram_parameters ;";
	}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#20 subprogram_parameters -> EMPTY";
	}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 177 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#21 subprogram_parameters -> ( parameter_list )";
	}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 181 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#22 parameter_list -> identifier_list : type";
	}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 185 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#23 parameter_list -> parameter_list ; identifier_list : type";
	}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#24 compound_statement -> BEGIN optional_statements END";
	}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#25 optional_statements -> EMPTY";
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 196 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#26 optional_statements -> statement_list";
	}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 200 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#27 statement_list -> statement";
	}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 204 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#28 statement_list -> statement_list SEMICOLON statement";
	}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#29 statement -> variable := expression";
	}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#30 statement -> procedure_statement";
	}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 216 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#31 statement -> compound_statement";
	}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#32 statement -> if expression then statement else statement";
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 224 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#33 statement -> while expression do statement";
	}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 228 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#34 variable -> ID(" << (*(yyvsp[0].token)) << ")";
	}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#35 variable -> ID(" << (*(yyvsp[-3].token)) << ") LPAREN expression RPAREN";
	}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 236 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#36 procedure_statement -> ID(" << (*(yyvsp[0].token)) << ")";
	}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#37 ID(" << (*(yyvsp[-3].token)) << ") ( expression_list )";
	}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#38 expression_list -> expression";
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 248 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#39 expression_list -> expression_list , expression";
	}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#40 expression -> simple_expression";
	}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 256 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#41 expression -> simple_expression relop simple_expression";
	}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#42 relop -> =";
	}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 264 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#43 relop -> <>";
	}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#44 relop -> <";
	}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#45 relop -> <=";
	}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 276 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#46 relop -> >";
	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 280 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#47 relop -> >=";
	}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 284 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#48 simple_expression -> term";
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 288 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#49 simple_expression -> sign term";
	}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 292 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#50 simple_expression -> simple_expression addop term";
	}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 296 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#51 sign -> +";
	}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 300 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#52 sign -> -";
	}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 304 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#53 addop -> +";
	}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 308 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#54 addop -> -";
	}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 312 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#55 procedure_statement -> or";
	}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 316 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#56 term -> factor";
	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 320 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#57 term -> term mulop factor";
	}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 324 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#58 mulop -> *";
	}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 328 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#59 mulop -> /";
	}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 332 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#60 mulop -> DIV";
	}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 336 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#61 mulop -> MOD";
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 340 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#62 mulop -> AND";
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 344 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#63 factor -> ID(" << (*(yyvsp[0].token)) << ")";
	}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 348 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#64 factor -> ID(" << (*(yyvsp[-3].token)) << ") RBRACKET expression RBRACKET";
	}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 352 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#65 factor -> ID(" << (*(yyvsp[-3].token)) << ") LPAREN expression_list RPAREN";
	}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 356 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#66 mulop -> LPAREN expression RPAREN";
	}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 360 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#67 mulop -> NOT factor";
	}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 364 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#68 factor -> INTLIT(" << (*(yyvsp[0].token)) << ")";
	}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 368 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#69 factor -> REALIT(" << (*(yyvsp[0].token)) << ")";
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 372 "paspar.y" /* yacc.c:1646  */
    {fout << endl << "#70 factor -> CHRLIT(" << (*(yyvsp[0].token)) << ")";
	}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1934 "y.tab.c" /* yacc.c:1646  */
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
#line 374 "paspar.y" /* yacc.c:1906  */

void yyerror(const char* m)
{	
	cout << endl << "line(" << line << ") col(" << col << ") " << m;
	cout << endl; 
}
