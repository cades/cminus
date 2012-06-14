/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 3 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <typeinfo>
#include "ASTHeaders.h"
#include "visitorsHeaders.h"
using namespace std;
static int linenumber = 1;
int yylex(void);    
int yyerror (AbstractNode* node, char *mesg);



    
void error(string msg) {
  cout << "Error found in line " << linenumber << endl << msg << endl;
}
    
TypeSpecifier* makeTypeSpecifier(AbstractNode*) {
    return 0;
}



/* Line 268 of yacc.c  */
#line 99 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CONST = 259,
     OP_ASSIGN = 260,
     OP_OR = 261,
     OP_AND = 262,
     OP_NOT = 263,
     OP_PLUS = 264,
     OP_MINUS = 265,
     OP_TIMES = 266,
     OP_DIVIDE = 267,
     OP_EQ = 268,
     OP_NE = 269,
     OP_GT = 270,
     OP_LT = 271,
     OP_GE = 272,
     OP_LE = 273,
     WHILE = 274,
     FOR = 275,
     IF = 276,
     ELSE = 277,
     VOID = 278,
     INT = 279,
     FLOAT = 280,
     STRUCT = 281,
     TYPEDEF = 282,
     MK_COMMA = 283,
     MK_DOT = 284,
     MK_LB = 285,
     MK_LBRACE = 286,
     MK_LPAREN = 287,
     MK_RB = 288,
     MK_RBRACE = 289,
     MK_RPAREN = 290,
     MK_SEMICOLON = 291,
     RETURN = 292,
     ERROR = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 178 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    23,    32,
      41,    49,    57,    65,    69,    71,    74,    77,    81,    85,
      90,    95,    96,    98,    99,   102,   104,   106,   107,   110,
     112,   114,   116,   121,   126,   131,   134,   139,   143,   147,
     151,   155,   159,   161,   163,   166,   172,   177,   179,   183,
     188,   191,   195,   200,   204,   208,   210,   214,   218,   220,
     222,   226,   228,   232,   234,   237,   241,   244,   246,   250,
     256,   266,   269,   275,   283,   285,   288,   292,   294,   295,
     299,   301,   305,   307,   309,   313,   315,   319,   321,   325,
     327,   329,   331,   333,   335,   337,   339,   340,   344,   346,
     350,   354,   356,   360,   364,   366,   370,   375,   380,   382,
     385,   388,   393,   399,   405,   407,   410,   413,   415,   418,
     421,   425
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    41,    42,    -1,    -1,    50,
      43,    -1,    43,    -1,    54,     3,    32,    44,    35,    31,
      49,    34,    -1,    55,     3,    32,    44,    35,    31,    49,
      34,    -1,    23,     3,    32,    44,    35,    31,    49,    34,
      -1,    54,     3,    32,    35,    31,    49,    34,    -1,    55,
       3,    32,    35,    31,    49,    34,    -1,    23,     3,    32,
      35,    31,    49,    34,    -1,    44,    28,    45,    -1,    45,
      -1,    54,     3,    -1,    55,     3,    -1,    54,     3,    46,
      -1,    55,     3,    46,    -1,    30,    48,    33,    47,    -1,
      30,    76,    33,    47,    -1,    -1,    76,    -1,    -1,    50,
      65,    -1,    65,    -1,    50,    -1,    -1,    50,    51,    -1,
      51,    -1,    52,    -1,    53,    -1,    27,    54,    58,    36,
      -1,    27,    23,    58,    36,    -1,    27,    55,    58,    36,
      -1,    56,    36,    -1,    27,    57,    58,    36,    -1,    54,
      63,    36,    -1,    55,    58,    36,    -1,    56,    58,    36,
      -1,    57,    58,    36,    -1,     3,    58,    36,    -1,    24,
      -1,    25,    -1,    26,     3,    -1,    26,     3,    31,    50,
      34,    -1,    26,    31,    50,    34,    -1,     3,    -1,    58,
      28,     3,    -1,    58,    28,     3,    59,    -1,     3,    59,
      -1,    30,    60,    33,    -1,    30,    60,    33,    59,    -1,
      60,     9,    61,    -1,    60,    10,    61,    -1,    61,    -1,
      61,    11,    62,    -1,    61,    12,    62,    -1,    62,    -1,
       4,    -1,    32,    60,    35,    -1,    64,    -1,    63,    28,
      64,    -1,     3,    -1,     3,    59,    -1,     3,     5,    70,
      -1,    65,    66,    -1,    66,    -1,    31,    49,    34,    -1,
      19,    32,    74,    35,    66,    -1,    20,    32,    67,    36,
      74,    36,    67,    35,    66,    -1,    69,    36,    -1,    21,
      32,    74,    35,    66,    -1,    21,    32,    74,    35,    66,
      22,    66,    -1,    36,    -1,    37,    36,    -1,    37,    70,
      36,    -1,    68,    -1,    -1,    68,    28,    69,    -1,    69,
      -1,    79,     5,    70,    -1,    70,    -1,    71,    -1,    70,
       6,    71,    -1,    72,    -1,    71,     7,    72,    -1,    76,
      -1,    76,    73,    76,    -1,    13,    -1,    17,    -1,    18,
      -1,    14,    -1,    15,    -1,    16,    -1,    75,    -1,    -1,
      75,    28,    70,    -1,    70,    -1,    76,     9,    77,    -1,
      76,    10,    77,    -1,    77,    -1,    77,    11,    78,    -1,
      77,    12,    78,    -1,    78,    -1,    32,    70,    35,    -1,
      10,    32,    70,    35,    -1,     8,    32,    70,    35,    -1,
       4,    -1,    10,     4,    -1,     8,     4,    -1,     3,    32,
      74,    35,    -1,    10,     3,    32,    74,    35,    -1,     8,
       3,    32,    74,    35,    -1,    79,    -1,    10,    79,    -1,
       8,    79,    -1,     3,    -1,    79,    80,    -1,    79,    81,
      -1,    30,    76,    33,    -1,    29,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    60,    61,    64,    65,    68,    70,    72,
      74,    76,    78,    82,    83,    86,    87,    88,    89,    91,
      93,    94,    96,    97,   100,   101,   102,   103,   106,   107,
     110,   111,   114,   115,   116,   117,   118,   121,   122,   123,
     124,   125,   128,   129,   132,   134,   136,   139,   140,   141,
     142,   144,   145,   147,   148,   149,   151,   152,   153,   155,
     156,   159,   160,   163,   164,   165,   168,   169,   172,   174,
     176,   178,   180,   182,   183,   184,   185,   188,   189,   192,
     193,   196,   197,   200,   201,   204,   205,   208,   209,   234,
     235,   236,   237,   238,   239,   242,   243,   246,   247,   250,
     251,   252,   254,   255,   256,   259,   260,   261,   263,   264,
     265,   267,   268,   269,   271,   272,   273,   275,   276,   277,
     281,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST", "OP_ASSIGN", "OP_OR",
  "OP_AND", "OP_NOT", "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIVIDE",
  "OP_EQ", "OP_NE", "OP_GT", "OP_LT", "OP_GE", "OP_LE", "WHILE", "FOR",
  "IF", "ELSE", "VOID", "INT", "FLOAT", "STRUCT", "TYPEDEF", "MK_COMMA",
  "MK_DOT", "MK_LB", "MK_LBRACE", "MK_LPAREN", "MK_RB", "MK_RBRACE",
  "MK_RPAREN", "MK_SEMICOLON", "RETURN", "ERROR", "$accept", "program",
  "global_decl_list", "global_decl", "function_decl", "param_list",
  "param", "dim_fn", "dimfn1", "expr_null", "block", "decl_list", "decl",
  "type_decl", "var_decl", "type", "struct_type", "struct_decl",
  "anonymous_struct", "id_list", "dim_decl", "cexpr", "mcexpr", "cfactor",
  "init_id_list", "init_id", "stmt_list", "stmt", "assign_expr_list",
  "nonempty_assign_expr_list", "assign_expr", "relop_expr", "relop_term",
  "relop_factor", "rel_op", "relop_expr_list", "nonempty_relop_expr_list",
  "expr", "term", "factor", "var_ref", "dim", "struct_tail", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    45,    45,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    55,    56,    57,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      80,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     8,     8,     8,
       7,     7,     7,     3,     1,     2,     2,     3,     3,     4,
       4,     0,     1,     0,     2,     1,     1,     0,     2,     1,
       1,     1,     4,     4,     4,     2,     4,     3,     3,     3,
       3,     3,     1,     1,     2,     5,     4,     1,     3,     4,
       2,     3,     4,     3,     3,     1,     3,     3,     1,     1,
       3,     1,     3,     1,     2,     3,     2,     1,     3,     5,
       9,     2,     5,     7,     1,     2,     3,     1,     0,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     4,     4,     1,     2,
       2,     4,     5,     5,     1,     2,     2,     1,     2,     2,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,    42,    43,     0,     0,
       3,     6,     0,    29,    30,    31,     0,     0,     0,     0,
      47,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       5,    28,    63,     0,    61,    47,     0,    35,     0,     0,
       0,    50,     0,    41,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    64,     0,    37,     0,
      38,    39,    40,    59,     0,     0,    55,    58,    48,     0,
       0,     0,    14,     0,     0,     0,    46,    63,    33,    32,
      34,    36,   117,   108,     0,     0,     0,    65,    83,    85,
      87,   101,   104,   114,     0,     0,    62,     0,     0,     0,
       0,     0,    51,     0,     0,    49,    27,     0,     0,    15,
      16,    45,    96,   117,   110,     0,   116,   117,   109,     0,
     115,     0,     0,     0,     0,     0,    89,    92,    93,    94,
      90,    91,     0,     0,     0,     0,     0,   118,   119,    27,
       0,    27,     0,    60,    53,    54,    52,    56,    57,   117,
       0,     0,     0,    27,    74,     0,     0,    26,    25,    67,
       0,    82,   114,    13,    27,    23,    17,    18,    98,     0,
      95,    96,     0,    96,     0,   105,    84,    86,    99,   100,
      88,   102,   103,   121,     0,     0,    27,     0,    27,    96,
      78,    96,     0,    75,     0,    12,    24,    66,    71,     0,
       0,     0,    22,   111,     0,     0,   107,     0,   106,   120,
      10,     0,    11,     0,     0,     0,    77,    80,     0,    68,
      76,    81,     9,    21,    97,   113,   112,     7,     8,     0,
      96,     0,     0,     0,    19,    69,     0,    79,    72,     0,
      78,     0,    21,     0,    73,    20,     0,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    11,    71,    72,   166,   234,   201,
     156,   157,    13,    14,    15,    47,    48,    18,    19,    21,
      41,    65,    66,    67,    33,    34,   158,   159,   215,   216,
     160,   161,    88,    89,   132,   169,   170,    90,    91,    92,
      93,   137,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -188
static const yytype_int16 yypact[] =
{
    -188,    16,   205,  -188,    66,    83,  -188,  -188,    23,   218,
    -188,  -188,   205,  -188,  -188,  -188,    88,   106,     9,    66,
     -11,    98,    80,    92,   199,    66,    32,    66,    66,    66,
    -188,  -188,    76,   116,  -188,   240,   145,  -188,   164,   171,
      47,  -188,   138,  -188,   163,   199,   188,   152,    66,   222,
    -188,   231,   232,   233,    84,   211,  -188,   152,  -188,   214,
    -188,  -188,  -188,  -188,    47,   115,    18,  -188,   -11,   198,
     141,    72,  -188,   200,   213,   193,  -188,     6,  -188,  -188,
    -188,  -188,   189,  -188,    10,    52,    84,   256,   259,  -188,
     238,    85,  -188,   131,   248,   155,  -188,   253,   169,   123,
      47,    47,   -11,    47,    47,  -188,   143,   239,   254,   215,
     215,  -188,    84,   255,  -188,    84,   131,   257,  -188,    84,
     131,     2,    84,    84,    84,    84,  -188,  -188,  -188,  -188,
    -188,  -188,    84,    84,    84,   268,    84,  -188,  -188,   143,
     260,   143,   261,  -188,    18,    18,  -188,  -188,  -188,    30,
     258,   262,   263,   143,  -188,    95,   252,   143,   174,  -188,
     265,   256,   113,  -188,   143,    84,  -188,  -188,   256,   267,
     269,    84,    12,    84,    69,  -188,   259,  -188,    85,    85,
     264,  -188,  -188,  -188,   176,   266,   143,   270,   143,    84,
      84,    84,   271,  -188,    14,  -188,   174,  -188,  -188,    84,
     272,   274,   264,  -188,    84,   273,  -188,   275,  -188,  -188,
    -188,   277,  -188,   278,   279,   280,   281,  -188,   282,  -188,
    -188,   256,  -188,   283,   256,  -188,  -188,  -188,  -188,   174,
      84,    84,   174,    84,  -188,  -188,   284,  -188,   276,   224,
      84,   174,   283,   286,  -188,  -188,   174,  -188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -188,   287,    55,   181,   183,    54,  -188,
     -93,     4,    -8,  -188,  -188,    13,    15,  -188,   294,   111,
     -25,   251,   175,   177,  -188,   285,   161,  -156,    79,  -188,
    -187,   -54,   201,   202,  -188,  -150,  -188,  -131,   153,   149,
     -75,  -188,  -188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      87,   180,   197,   217,    31,   184,    12,    56,   122,   116,
     120,    54,    20,   113,   114,    16,     3,    17,   122,    40,
     122,   205,    27,   207,    28,    16,    23,    17,    46,   103,
     104,   162,   121,    20,   202,    50,    40,   175,    31,   214,
     197,   218,   115,   105,   237,    37,   185,   206,   187,    75,
     220,    63,    56,   217,    24,   117,   118,    73,   168,    74,
     192,   172,   112,    24,   162,   174,   162,    31,    73,    20,
      74,   200,    73,   235,    74,   122,   238,   146,   162,    64,
     236,    54,   162,   162,   119,   244,    22,    82,    83,   162,
     247,    32,    84,   211,    85,   213,   133,   134,    82,    83,
     107,   194,   239,    84,   208,    85,    40,   108,    55,    35,
      95,   162,    44,   162,    98,   162,    86,   168,   199,   168,
      73,   162,    74,    45,   100,   101,    42,    86,    36,    38,
      39,   193,   100,   101,    43,   168,    49,   168,    51,    52,
      53,    68,   135,   136,    57,   221,   149,    83,   102,    31,
     224,    84,    58,    85,   162,    77,   162,   162,   143,    36,
     135,   136,   150,   151,   152,   162,   162,     6,     7,     8,
       9,   162,   106,    42,   153,    86,   168,    82,    83,   154,
     155,    60,    84,   107,    85,   124,   125,     6,     7,    69,
     140,     4,    42,   150,   151,   152,     4,   107,    70,    42,
      61,    50,     4,   109,   142,   153,    86,    62,     4,   209,
     154,   155,     6,     7,     8,     9,   110,     6,     7,     8,
       9,   112,    76,     6,     7,     8,     9,   111,     5,     6,
       7,     8,     9,   124,   125,     6,     7,    69,     6,     7,
      69,    25,     6,     7,    26,   165,    94,   124,   125,    97,
      42,   126,   127,   128,   129,   130,   131,   242,    78,    42,
      42,    42,   122,     6,     7,    69,   123,    79,    80,    81,
      40,   183,    59,   124,   125,   144,   145,   178,   179,   139,
     147,   148,   181,   182,   141,   164,   195,   171,   163,   173,
     189,   186,   188,   167,   190,   191,   245,   204,   241,    30,
     210,   198,   203,    29,   212,   219,   222,   223,   225,   231,
     226,   227,   228,   233,   229,    99,   230,   232,   196,   243,
     240,   246,     0,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-188))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      54,   132,   158,   190,    12,   136,     2,    32,     6,    84,
      85,     5,     3,     3,     4,     2,     0,     2,     6,    30,
       6,   171,     9,   173,     9,    12,     3,    12,    24,    11,
      12,   106,    86,     3,   165,     3,    30,    35,    46,   189,
     196,   191,    32,    68,   231,    36,   139,    35,   141,    45,
      36,     4,    77,   240,    31,     3,     4,    44,   112,    44,
     153,   115,    32,    31,   139,   119,   141,    75,    55,     3,
      55,   164,    59,   229,    59,     6,   232,   102,   153,    32,
     230,     5,   157,   158,    32,   241,     3,     3,     4,   164,
     246,     3,     8,   186,    10,   188,    11,    12,     3,     4,
      28,   155,   233,     8,    35,    10,    30,    35,    32,     3,
      55,   186,    32,   188,    59,   190,    32,   171,     5,   173,
     107,   196,   107,    31,     9,    10,    28,    32,    17,    18,
      19,    36,     9,    10,    36,   189,    25,   191,    27,    28,
      29,     3,    29,    30,    28,   199,     3,     4,    33,   157,
     204,     8,    36,    10,   229,     3,   231,   232,    35,    48,
      29,    30,    19,    20,    21,   240,   241,    24,    25,    26,
      27,   246,    31,    28,    31,    32,   230,     3,     4,    36,
      37,    36,     8,    28,    10,     9,    10,    24,    25,    26,
      35,     3,    28,    19,    20,    21,     3,    28,    35,    28,
      36,     3,     3,     3,    35,    31,    32,    36,     3,    33,
      36,    37,    24,    25,    26,    27,     3,    24,    25,    26,
      27,    32,    34,    24,    25,    26,    27,    34,    23,    24,
      25,    26,    27,     9,    10,    24,    25,    26,    24,    25,
      26,    23,    24,    25,    26,    30,    35,     9,    10,    35,
      28,    13,    14,    15,    16,    17,    18,    33,    36,    28,
      28,    28,     6,    24,    25,    26,     7,    36,    36,    36,
      30,     3,    32,     9,    10,   100,   101,   124,   125,    31,
     103,   104,   133,   134,    31,    31,    34,    32,   107,    32,
      32,    31,    31,   110,    32,    32,   242,    28,    22,    12,
      34,    36,    35,     9,    34,    34,    34,    33,    35,    28,
      35,    34,    34,    30,    35,    64,    36,    35,   157,   240,
      36,    35,    -1,   122,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     3,    23,    24,    25,    26,    27,
      42,    43,    50,    51,    52,    53,    54,    55,    56,    57,
       3,    58,     3,     3,    31,    23,    26,    54,    55,    57,
      43,    51,     3,    63,    64,     3,    58,    36,    58,    58,
      30,    59,    28,    36,    32,    31,    50,    54,    55,    58,
       3,    58,    58,    58,     5,    32,    59,    28,    36,    32,
      36,    36,    36,     4,    32,    60,    61,    62,     3,    26,
      35,    44,    45,    54,    55,    50,    34,     3,    36,    36,
      36,    36,     3,     4,     8,    10,    32,    70,    71,    72,
      76,    77,    78,    79,    35,    44,    64,    35,    44,    60,
       9,    10,    33,    11,    12,    59,    31,    28,    35,     3,
       3,    34,    32,     3,     4,    32,    79,     3,     4,    32,
      79,    70,     6,     7,     9,    10,    13,    14,    15,    16,
      17,    18,    73,    11,    12,    29,    30,    80,    81,    31,
      35,    31,    35,    35,    61,    61,    59,    62,    62,     3,
      19,    20,    21,    31,    36,    37,    49,    50,    65,    66,
      69,    70,    79,    45,    31,    30,    46,    46,    70,    74,
      75,    32,    70,    32,    70,    35,    71,    72,    77,    77,
      76,    78,    78,     3,    76,    49,    31,    49,    31,    32,
      32,    32,    49,    36,    70,    34,    65,    66,    36,     5,
      49,    48,    76,    35,    28,    74,    35,    74,    35,    33,
      34,    49,    34,    49,    74,    67,    68,    69,    74,    34,
      36,    70,    34,    33,    70,    35,    35,    34,    34,    35,
      36,    28,    35,    30,    47,    66,    74,    69,    66,    76,
      36,    22,    33,    67,    66,    47,    35,    66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (root, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, root); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, AbstractNode* root)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    AbstractNode* root;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (root);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, AbstractNode* root)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    AbstractNode* root;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, root);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, AbstractNode* root)
#else
static void
yy_reduce_print (yyvsp, yyrule, root)
    YYSTYPE *yyvsp;
    int yyrule;
    AbstractNode* root;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, root); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, AbstractNode* root)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, root)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    AbstractNode* root;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (root);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (AbstractNode* root);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (AbstractNode* root)
#else
int
yyparse (root)
    AbstractNode* root;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 57 "parser.y"
    { (yyval.nodeList) = (yyvsp[(1) - (1)].nodeList); root = (yyvsp[(1) - (1)].nodeList); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 60 "parser.y"
    { (yyvsp[(1) - (2)].nodeList)->append((yyvsp[(2) - (2)].nodeList)); (yyval.nodeList) = (yyvsp[(1) - (2)].nodeList); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 61 "parser.y"
    { (yyval.nodeList) = new NodeList; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 64 "parser.y"
    { (yyvsp[(1) - (2)].nodeList)->append((yyvsp[(2) - (2)].node)); (yyval.nodeList) = (yyvsp[(1) - (2)].nodeList); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 65 "parser.y"
    {  (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 69 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (8)].id)), (yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].nodeList), (yyvsp[(7) - (8)].node)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 71 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (8)].id)), (yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].nodeList), (yyvsp[(7) - (8)].node)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 73 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier(new Identifier("void")), (yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].nodeList), (yyvsp[(7) - (8)].node)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (7)].id)), (yyvsp[(2) - (7)].id), new NodeList, (yyvsp[(6) - (7)].node)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 77 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (7)].id)), (yyvsp[(2) - (7)].id), new NodeList, (yyvsp[(6) - (7)].node)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 79 "parser.y"
    { (yyval.node) = new FunctionDeclaringNode(makeTypeSpecifier(new Identifier("void")), (yyvsp[(2) - (7)].id), new NodeList, (yyvsp[(6) - (7)].node)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 82 "parser.y"
    { (yyvsp[(1) - (3)].nodeList)->append((yyvsp[(3) - (3)].node)); (yyval.nodeList) = (yyvsp[(1) - (3)].nodeList); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 83 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 86 "parser.y"
    { (yyval.node) = new VariableDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (2)].id)), (yyvsp[(2) - (2)].id)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 87 "parser.y"
    { (yyval.node) = new VariableDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (2)].id)), (yyvsp[(2) - (2)].id)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    { (yyval.node) = new ArrayVariableDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].id)), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].node)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 89 "parser.y"
    { (yyval.node) = new ArrayVariableDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].id)), (yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].node)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 91 "parser.y"
    { (yyval.node) = new ArrayDefiningNode((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 93 "parser.y"
    { (yyval.node) = new ArrayDefiningNode((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 94 "parser.y"
    { (yyval.node) = 0; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 97 "parser.y"
    { (yyval.node) = new EmptyNode; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    { (yyvsp[(1) - (2)].nodeList)->append((yyvsp[(2) - (2)].nodeList)); delete (yyvsp[(2) - (2)].nodeList); (yyval.node) = new BlockNode((yyvsp[(1) - (2)].nodeList)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 101 "parser.y"
    { (yyval.node) = new BlockNode((yyvsp[(1) - (1)].nodeList)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 102 "parser.y"
    { (yyval.node) = new BlockNode((yyvsp[(1) - (1)].nodeList)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 103 "parser.y"
    { (yyval.node) = new EmptyNode; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 106 "parser.y"
    { (yyvsp[(1) - (2)].nodeList)->append((yyvsp[(2) - (2)].node)); (yyval.nodeList) = (yyvsp[(1) - (2)].nodeList); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 107 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 110 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 114 "parser.y"
    { (yyval.node) = new TypedefNode(makeTypeSpecifier((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].nodeList)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = new TypedefNode(makeTypeSpecifier(new Identifier("void")), (yyvsp[(3) - (4)].nodeList)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = new TypedefNode(makeTypeSpecifier((yyvsp[(2) - (4)].id)), (yyvsp[(3) - (4)].nodeList)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 117 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = new TypedefNode(makeTypeSpecifier((yyvsp[(2) - (4)].node)), (yyvsp[(3) - (4)].nodeList)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 121 "parser.y"
    { (yyval.node) = new VariableListDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].id)), (yyvsp[(2) - (3)].nodeList)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = new VariableListDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].id)), (yyvsp[(2) - (3)].nodeList)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 123 "parser.y"
    { (yyval.node) = new VariableListDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].node)), (yyvsp[(2) - (3)].nodeList)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 124 "parser.y"
    { (yyval.node) = new VariableListDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].node)), (yyvsp[(2) - (3)].nodeList)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    { (yyval.node) = new VariableListDeclaringNode(makeTypeSpecifier((yyvsp[(1) - (3)].id)), (yyvsp[(2) - (3)].nodeList)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 128 "parser.y"
    { (yyval.id) = new Identifier("int");}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyval.id) = new Identifier("float");}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    {(yyval.id) = new Identifier("[struct:"+(yyvsp[(2) - (2)].id)->name()+"]"); delete (yyvsp[(2) - (2)].id); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    { (yyval.node) = new TypeDeclaringNode((yyvsp[(2) - (5)].id), new StructDefiningNode((yyvsp[(4) - (5)].nodeList))); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    { (yyval.node) = new StructDefiningNode((yyvsp[(3) - (4)].nodeList)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].id)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    { (yyvsp[(1) - (3)].nodeList)->append((yyvsp[(3) - (3)].id)); (yyval.nodeList) = (yyvsp[(1) - (3)].nodeList); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { (yyvsp[(3) - (4)].id) = new IdentifierWithDim((yyvsp[(3) - (4)].id), (yyvsp[(4) - (4)].node)); delete (yyvsp[(3) - (4)].id); (yyvsp[(1) - (4)].nodeList)->append((yyvsp[(3) - (4)].id)); (yyval.nodeList) = (yyvsp[(1) - (4)].nodeList); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { (yyvsp[(1) - (2)].id) = new IdentifierWithDim((yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].node)); delete (yyvsp[(2) - (2)].node); (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (2)].id)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 144 "parser.y"
    { (yyval.node) = new ArrayDefiningNode((yyvsp[(2) - (3)].node), 0); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    { (yyval.node) = new ArrayDefiningNode((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));  }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    { (yyval.node) = new PlusNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    { (yyval.node) = new MinusNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 151 "parser.y"
    { (yyval.node) = new MultiplyNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 152 "parser.y"
    { (yyval.node) = new DivideNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { (yyvsp[(1) - (3)].nodeList)->append((yyvsp[(3) - (3)].node)); (yyval.nodeList) = (yyvsp[(1) - (3)].nodeList); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].id); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    { (yyvsp[(1) - (2)].id) = new IdentifierWithDim((yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].node)); delete (yyvsp[(1) - (2)].id); (yyval.node) = (yyvsp[(1) - (2)].id);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    { (yyval.node) = new AssigningNode((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].node)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    { (yyvsp[(1) - (2)].nodeList)->append((yyvsp[(2) - (2)].node)); (yyval.nodeList) = (yyvsp[(1) - (2)].nodeList); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { (yyval.node) = new WhileLoopingNode((yyvsp[(3) - (5)].nodeList), (yyvsp[(5) - (5)].node)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    { (yyval.node) = new ForLoopingNode((yyvsp[(3) - (9)].nodeList), (yyvsp[(5) - (9)].nodeList), (yyvsp[(7) - (9)].nodeList), (yyvsp[(9) - (9)].node)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    { (yyval.node) = new IfTestingNode((yyvsp[(3) - (5)].nodeList), (yyvsp[(5) - (5)].node), new EmptyNode); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    { (yyval.node) = new IfTestingNode((yyvsp[(3) - (7)].nodeList), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { (yyval.node) = new EmptyNode; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { (yyval.node) = new ReturningNode(new EmptyNode); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 185 "parser.y"
    { (yyval.node) = new ReturningNode((yyvsp[(2) - (3)].node)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    { (yyval.nodeList) = (yyvsp[(1) - (1)].nodeList); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    { (yyval.nodeList) = new NodeList; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    { (yyvsp[(1) - (3)].nodeList)->append((yyvsp[(3) - (3)].node)); (yyval.nodeList) = (yyvsp[(1) - (3)].nodeList); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { (yyval.node) = new AssigningNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    { (yyval.node) = new ORNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 205 "parser.y"
    { (yyval.node) = new ANDNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {
  switch((yyvsp[(2) - (3)].opKind)) {
  case YYSTYPE::OP_EQ:
    (yyval.node) = new EQNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  case YYSTYPE::OP_GE:
    (yyval.node) = new GENode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  case YYSTYPE::OP_LE:
    (yyval.node) = new LENode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  case YYSTYPE::OP_NE:
    (yyval.node) = new NENode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  case YYSTYPE::OP_GT:
    (yyval.node) = new GTNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  case YYSTYPE::OP_LT:
    (yyval.node) = new LTNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    break;
  }
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 234 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 236 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 237 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    { (yyval.opKind) = (yyvsp[(1) - (1)].opKind); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { (yyval.nodeList) = (yyvsp[(1) - (1)].nodeList); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    { (yyval.nodeList) = new NodeList; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { (yyvsp[(1) - (3)].nodeList)->append((yyvsp[(3) - (3)].node)); (yyval.nodeList) = (yyvsp[(1) - (3)].nodeList); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 247 "parser.y"
    { (yyval.nodeList) = new NodeList; (yyval.nodeList)->append((yyvsp[(1) - (1)].node)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 250 "parser.y"
    { (yyval.node) = new PlusNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    { (yyval.node) = new MinusNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 252 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 254 "parser.y"
    { (yyval.node) = new MultiplyNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 255 "parser.y"
    { (yyval.node) = new DivideNode((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 259 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 260 "parser.y"
    { (yyval.node) = new NegNode((yyvsp[(3) - (4)].node)); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 261 "parser.y"
    { (yyval.node) = new NotNode((yyvsp[(3) - (4)].node)); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 264 "parser.y"
    { (yyval.node) = new NegNode((yyvsp[(2) - (2)].node)); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    { (yyval.node) = new NotNode((yyvsp[(2) - (2)].node)); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 267 "parser.y"
    { (yyval.node) = new CallingNode((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].nodeList)); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 268 "parser.y"
    { (yyval.node) = new NegNode(new CallingNode((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].nodeList))); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 269 "parser.y"
    { (yyval.node) = new NotNode(new CallingNode((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].nodeList))); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 271 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    { (yyval.node) = new NegNode((yyvsp[(2) - (2)].node)); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 273 "parser.y"
    { (yyval.node) = new NotNode((yyvsp[(2) - (2)].node)); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].id); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 276 "parser.y"
    { (yyval.node) = new ArrayReferencingNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 277 "parser.y"
    { (yyval.node) = new StructReferencingNode((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].id)); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    { (yyval.id) = (yyvsp[(2) - (2)].id); }
    break;



/* Line 1806 of yacc.c  */
#line 2511 "parser.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (root, YY_("syntax error"));
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
        yyerror (root, yymsgp);
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
		      yytoken, &yylval, root);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
		  yystos[yystate], yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
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
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, root);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 287 "parser.y"


#include "lex.yy.c"
//#include "SymbolTable.h"
//extern int main(); // when using CppTest, main should leave to CppUTest.

int main (int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    AbstractNode* astRoot = 0;
    
    yyparse(astRoot);  // pass AST root to yyparse
    
    TopDeclVisitor tdVisitor;
    //astRoot->accept(tdVisitor);
    
    printf("%s\n", "Parsing completed. No errors found.");
} /* main */


int yyerror (AbstractNode* node, char *mesg)
{
    printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
    exit(1);
}

