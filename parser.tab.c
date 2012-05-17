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
static int linenumber = 1;


/* Line 268 of yacc.c  */
#line 79 "parser.tab.c"

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
     VOID = 260,
     INT = 261,
     FLOAT = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     STRUCT = 267,
     TYPEDEF = 268,
     OP_ASSIGN = 269,
     OP_OR = 270,
     OP_AND = 271,
     OP_NOT = 272,
     OP_EQ = 273,
     OP_NE = 274,
     OP_GT = 275,
     OP_LT = 276,
     OP_GE = 277,
     OP_LE = 278,
     OP_PLUS = 279,
     OP_MINUS = 280,
     OP_TIMES = 281,
     OP_DIVIDE = 282,
     MK_LB = 283,
     MK_RB = 284,
     MK_LPAREN = 285,
     MK_RPAREN = 286,
     MK_LBRACE = 287,
     MK_RBRACE = 288,
     MK_COMMA = 289,
     MK_SEMICOLON = 290,
     MK_DOT = 291,
     ERROR = 292,
     RETURN = 293,
     FNCALL_READ = 294,
     FNCALL_FREAD = 295,
     FNCALL_WRITE = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 162 "parser.tab.c"

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
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
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
     188,   191,   195,   200,   204,   206,   210,   212,   214,   218,
     220,   224,   226,   229,   233,   236,   238,   242,   248,   258,
     263,   266,   272,   280,   282,   285,   289,   291,   292,   296,
     298,   302,   304,   306,   310,   312,   316,   318,   322,   324,
     326,   328,   330,   332,   334,   336,   337,   341,   343,   347,
     349,   351,   353,   357,   359,   361,   363,   367,   372,   377,
     379,   382,   385,   390,   396,   402,   404,   407,   410,   412,
     415,   418,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    45,    -1,    -1,    53,
      46,    -1,    46,    -1,    57,     3,    30,    47,    31,    32,
      52,    33,    -1,    58,     3,    30,    47,    31,    32,    52,
      33,    -1,     5,     3,    30,    47,    31,    32,    52,    33,
      -1,    57,     3,    30,    31,    32,    52,    33,    -1,    58,
       3,    30,    31,    32,    52,    33,    -1,     5,     3,    30,
      31,    32,    52,    33,    -1,    47,    34,    48,    -1,    48,
      -1,    57,     3,    -1,    58,     3,    -1,    57,     3,    49,
      -1,    58,     3,    49,    -1,    28,    51,    29,    50,    -1,
      28,    79,    29,    50,    -1,    -1,    79,    -1,    -1,    53,
      68,    -1,    68,    -1,    53,    -1,    -1,    53,    54,    -1,
      54,    -1,    55,    -1,    56,    -1,    13,    57,    61,    35,
      -1,    13,     5,    61,    35,    -1,    13,    58,    61,    35,
      -1,    59,    35,    -1,    13,    60,    61,    35,    -1,    57,
      66,    35,    -1,    58,    61,    35,    -1,    59,    61,    35,
      -1,    60,    61,    35,    -1,     3,    61,    35,    -1,     6,
      -1,     7,    -1,    12,     3,    -1,    12,     3,    32,    53,
      33,    -1,    12,    32,    53,    33,    -1,     3,    -1,    61,
      34,     3,    -1,    61,    34,     3,    62,    -1,     3,    62,
      -1,    28,    63,    29,    -1,    62,    28,    63,    29,    -1,
      63,    80,    64,    -1,    64,    -1,    64,    82,    65,    -1,
      65,    -1,     4,    -1,    30,    63,    31,    -1,    67,    -1,
      66,    34,    67,    -1,     3,    -1,     3,    62,    -1,     3,
      14,    73,    -1,    68,    69,    -1,    69,    -1,    32,    52,
      33,    -1,    10,    30,    77,    31,    69,    -1,    11,    30,
      70,    35,    77,    35,    70,    31,    69,    -1,    84,    14,
      73,    35,    -1,    73,    35,    -1,     8,    30,    77,    31,
      69,    -1,     8,    30,    77,    31,    69,     9,    69,    -1,
      35,    -1,    38,    35,    -1,    38,    73,    35,    -1,    71,
      -1,    -1,    71,    34,    72,    -1,    72,    -1,     3,    14,
      73,    -1,    73,    -1,    74,    -1,    73,    15,    74,    -1,
      75,    -1,    74,    16,    75,    -1,    79,    -1,    79,    76,
      79,    -1,    18,    -1,    22,    -1,    23,    -1,    19,    -1,
      20,    -1,    21,    -1,    78,    -1,    -1,    78,    34,    73,
      -1,    73,    -1,    79,    80,    81,    -1,    81,    -1,    24,
      -1,    25,    -1,    81,    82,    83,    -1,    83,    -1,    26,
      -1,    27,    -1,    30,    73,    31,    -1,    25,    30,    73,
      31,    -1,    17,    30,    73,    31,    -1,     4,    -1,    25,
       4,    -1,    17,     4,    -1,     3,    30,    77,    31,    -1,
      25,     3,    30,    77,    31,    -1,    17,     3,    30,    77,
      31,    -1,    84,    -1,    25,    84,    -1,    17,    84,    -1,
       3,    -1,    84,    85,    -1,    84,    86,    -1,    28,    79,
      29,    -1,    36,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    62,    63,    66,    67,    70,    72,    73,
      75,    77,    79,    82,    83,    86,    87,    88,    89,    91,
      93,    94,    96,    97,   100,   101,   102,   103,   106,   107,
     110,   111,   114,   115,   116,   117,   118,   121,   122,   123,
     124,   125,   128,   129,   132,   134,   136,   139,   140,   141,
     142,   144,   145,   147,   148,   150,   151,   153,   154,   157,
     158,   161,   162,   163,   166,   167,   170,   172,   174,   175,
     179,   181,   183,   184,   185,   186,   189,   190,   193,   194,
     197,   198,   201,   202,   205,   206,   209,   210,   213,   214,
     215,   216,   217,   218,   221,   222,   225,   226,   229,   230,
     233,   234,   237,   238,   241,   242,   245,   246,   247,   249,
     250,   251,   253,   254,   255,   257,   258,   259,   261,   262,
     263,   267,   270
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST", "VOID", "INT", "FLOAT",
  "IF", "ELSE", "WHILE", "FOR", "STRUCT", "TYPEDEF", "OP_ASSIGN", "OP_OR",
  "OP_AND", "OP_NOT", "OP_EQ", "OP_NE", "OP_GT", "OP_LT", "OP_GE", "OP_LE",
  "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIVIDE", "MK_LB", "MK_RB",
  "MK_LPAREN", "MK_RPAREN", "MK_LBRACE", "MK_RBRACE", "MK_COMMA",
  "MK_SEMICOLON", "MK_DOT", "ERROR", "RETURN", "FNCALL_READ",
  "FNCALL_FREAD", "FNCALL_WRITE", "$accept", "program", "global_decl_list",
  "global_decl", "function_decl", "param_list", "param", "dim_fn",
  "dimfn1", "expr_null", "block", "decl_list", "decl", "type_decl",
  "var_decl", "type", "struct_type", "struct_decl", "anonymous_struct",
  "id_list", "dim_decl", "cexpr", "mcexpr", "cfactor", "init_id_list",
  "init_id", "stmt_list", "stmt", "assign_expr_list",
  "nonempty_assign_expr_list", "assign_expr", "relop_expr", "relop_term",
  "relop_factor", "rel_op", "relop_expr_list", "nonempty_relop_expr_list",
  "expr", "add_op", "term", "mul_op", "factor", "var_ref", "dim",
  "struct_tail", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    57,    57,    58,    59,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     8,     8,     8,
       7,     7,     7,     3,     1,     2,     2,     3,     3,     4,
       4,     0,     1,     0,     2,     1,     1,     0,     2,     1,
       1,     1,     4,     4,     4,     2,     4,     3,     3,     3,
       3,     3,     1,     1,     2,     5,     4,     1,     3,     4,
       2,     3,     4,     3,     1,     3,     1,     1,     3,     1,
       3,     1,     2,     3,     2,     1,     3,     5,     9,     4,
       2,     5,     7,     1,     2,     3,     1,     0,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     4,     4,     1,
       2,     2,     4,     5,     5,     1,     2,     2,     1,     2,
       2,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,    42,    43,     0,     0,
       3,     6,     0,    29,    30,    31,     0,     0,     0,     0,
      47,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       5,    28,    61,     0,    59,    47,     0,    35,     0,     0,
       0,    50,     0,    41,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    62,     0,    37,     0,
      38,    39,    40,    57,     0,     0,    54,    56,     0,    48,
       0,     0,     0,    14,     0,     0,     0,    46,    61,    33,
      32,    34,    36,   118,   109,     0,     0,     0,    63,    82,
      84,    86,    99,   103,   115,     0,     0,    60,     0,     0,
       0,   100,   101,    51,     0,   104,   105,     0,     0,    49,
      27,     0,     0,    15,    16,    45,    95,   118,   111,     0,
     117,   118,   110,     0,   116,     0,     0,     0,    88,    91,
      92,    93,    89,    90,     0,     0,     0,     0,     0,   119,
     120,    27,     0,    27,     0,    58,    53,    55,    52,   118,
       0,     0,     0,    27,    73,     0,     0,    26,    25,    65,
       0,   115,    27,    13,    23,    17,    18,    97,     0,    94,
      95,     0,    95,     0,   106,    83,    85,    87,    98,   102,
       0,   122,     0,    27,     0,    27,    95,    95,    77,     0,
      74,     0,    12,    24,    64,    70,     0,     0,     0,    22,
     112,     0,     0,   108,     0,   107,   121,    10,     0,    11,
       0,     0,     0,   118,     0,    76,    79,    81,    66,    75,
       0,     9,    21,    96,   114,   113,     7,     8,     0,     0,
       0,    95,     0,    69,     0,    19,    71,    67,    80,     0,
      78,     0,     0,    77,    21,    72,     0,    20,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    11,    72,    73,   165,   235,   198,
     156,   157,    13,    14,    15,    47,    48,    18,    19,    21,
      41,    65,    66,    67,    33,    34,   158,   159,   214,   215,
     216,   160,    89,    90,   134,   168,   169,    91,   135,    92,
     107,    93,    94,   139,   140
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const yytype_int16 yypact[] =
{
    -152,    21,   236,  -152,    51,    80,  -152,  -152,    13,   167,
    -152,  -152,   236,  -152,  -152,  -152,   123,   132,     9,    51,
     156,   136,   160,   172,   247,    51,    15,    51,    51,    51,
    -152,  -152,    66,   210,  -152,   153,   223,  -152,   244,   249,
       7,   164,   206,  -152,   204,   247,    86,   211,    51,   252,
    -152,   254,   256,   258,   111,   216,   164,   211,  -152,   224,
    -152,  -152,  -152,  -152,     7,   227,   175,  -152,     7,   156,
     214,   187,    54,  -152,   221,   231,   118,  -152,    22,  -152,
    -152,  -152,  -152,   197,  -152,    11,    27,   111,   222,   213,
    -152,   243,   175,  -152,    81,   208,   106,  -152,   239,   135,
     119,  -152,  -152,  -152,     7,  -152,  -152,     7,   245,   164,
     150,   253,   226,   218,   218,  -152,   111,   264,  -152,   111,
      81,   265,  -152,   111,    81,    92,   111,   111,  -152,  -152,
    -152,  -152,  -152,  -152,   111,   111,   111,   111,   293,  -152,
    -152,   150,   266,   150,   267,  -152,   175,  -152,  -152,    29,
     270,   271,   272,   150,  -152,    78,   273,   150,   183,  -152,
      36,    76,   150,  -152,   111,  -152,  -152,   222,   274,   263,
     111,    96,   111,   107,  -152,   213,  -152,   257,   175,  -152,
     248,  -152,   275,   150,   276,   150,   111,   111,   195,   277,
    -152,    38,  -152,   183,  -152,  -152,   111,   278,   283,   257,
    -152,   111,   282,  -152,   284,  -152,  -152,  -152,   281,  -152,
     285,   286,   288,   125,   268,   287,  -152,   222,  -152,  -152,
      71,  -152,   279,   222,  -152,  -152,  -152,  -152,   183,   183,
     111,   111,   195,  -152,   111,  -152,   295,  -152,   222,   289,
    -152,   251,   183,   195,   279,  -152,   291,  -152,   183,  -152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,  -152,   304,    93,   215,   209,    82,  -152,
    -119,     4,    -8,  -152,  -152,     8,    17,  -152,   311,   178,
     -23,   100,   225,   228,  -152,   280,   168,  -151,    85,  -152,
      98,   -54,   205,   207,  -152,  -147,  -152,  -129,   -52,   198,
     -91,   196,   -83,  -152,  -152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      88,   136,   120,   124,    31,   177,    12,   194,   180,    56,
      16,    63,    20,   104,   117,   118,    23,    27,    50,    17,
      16,     3,   182,   202,   184,   204,    28,   161,    46,    17,
     121,   122,    20,   125,   189,   199,    54,    64,    31,   211,
     212,   119,   194,   197,    37,    24,   109,    24,   104,    76,
      40,   126,    74,   126,    20,    56,   104,   123,   161,   116,
     161,    75,   167,    74,   208,   171,   210,    74,    31,   173,
     161,   195,    75,   219,   161,   161,    75,   236,   237,   161,
      54,    83,    84,    22,   239,   111,   126,   136,   112,     4,
     196,   245,     6,     7,    40,    85,    55,   249,     8,     9,
     161,   191,   161,    86,   137,   241,   233,   126,    87,   137,
     161,   126,   138,   190,    83,    84,   167,   138,   167,    77,
      74,     4,   126,   174,     6,     7,    32,   203,    85,    75,
       8,     9,   167,   167,   217,    35,    86,   142,   205,   230,
     112,    87,   220,   101,   102,   161,   161,   223,    96,    31,
     145,   115,    99,   149,    84,   116,     6,     7,   150,   161,
     151,   152,     8,     9,   100,   161,   144,    85,   108,   112,
      42,    43,    25,     6,     7,    86,   238,   167,   217,    26,
      87,    40,   153,    59,    40,   154,    83,    84,   155,   217,
      44,   150,    68,   151,   152,    36,    38,    39,   213,    84,
      85,   105,   106,    49,    45,    51,    52,    53,    86,    69,
       6,     7,    85,    87,    78,   153,    70,    50,   154,   110,
      86,   155,     6,     7,   113,    87,    36,   116,    70,   127,
       6,     7,     6,     7,   114,    71,    70,   126,    70,     4,
     141,     5,     6,     7,    57,    58,   164,    95,     8,     9,
       4,   101,   102,     6,     7,    98,   103,    42,    60,     8,
       9,   128,   129,   130,   131,   132,   133,   101,   102,   101,
     102,   143,   101,   102,   148,   101,   102,   206,    42,    61,
     244,   101,   102,    42,    62,   162,    42,    79,    42,    80,
      42,    81,    42,    82,   170,   172,   181,   201,   183,   185,
     186,   187,   188,   231,   242,   200,   192,   234,   207,   209,
     218,   221,   222,   224,   226,   225,    30,   228,   227,   229,
      29,   232,   248,   166,   243,   193,   247,   163,   246,   146,
     240,   175,   179,   178,   176,   147,     0,    97
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-152))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      54,    92,    85,    86,    12,   134,     2,   158,   137,    32,
       2,     4,     3,    65,     3,     4,     3,     9,     3,     2,
      12,     0,   141,   170,   143,   172,     9,   110,    24,    12,
       3,     4,     3,    87,   153,   164,    14,    30,    46,   186,
     187,    30,   193,   162,    35,    32,    69,    32,   100,    45,
      28,    15,    44,    15,     3,    78,   108,    30,   141,    30,
     143,    44,   116,    55,   183,   119,   185,    59,    76,   123,
     153,    35,    55,    35,   157,   158,    59,   228,   229,   162,
      14,     3,     4,     3,   231,    31,    15,   178,    34,     3,
      14,   242,     6,     7,    28,    17,    30,   248,    12,    13,
     183,   155,   185,    25,    28,   234,    35,    15,    30,    28,
     193,    15,    36,    35,     3,     4,   170,    36,   172,    33,
     112,     3,    15,    31,     6,     7,     3,    31,    17,   112,
      12,    13,   186,   187,   188,     3,    25,    31,    31,    14,
      34,    30,   196,    24,    25,   228,   229,   201,    55,   157,
      31,    33,    59,     3,     4,    30,     6,     7,     8,   242,
      10,    11,    12,    13,    64,   248,    31,    17,    68,    34,
      34,    35,     5,     6,     7,    25,   230,   231,   232,    12,
      30,    28,    32,    30,    28,    35,     3,     4,    38,   243,
      30,     8,    28,    10,    11,    17,    18,    19,     3,     4,
      17,    26,    27,    25,    32,    27,    28,    29,    25,     3,
       6,     7,    17,    30,     3,    32,    12,     3,    35,    32,
      25,    38,     6,     7,     3,    30,    48,    30,    12,    16,
       6,     7,     6,     7,     3,    31,    12,    15,    12,     3,
      32,     5,     6,     7,    34,    35,    28,    31,    12,    13,
       3,    24,    25,     6,     7,    31,    29,    34,    35,    12,
      13,    18,    19,    20,    21,    22,    23,    24,    25,    24,
      25,    32,    24,    25,    29,    24,    25,    29,    34,    35,
      29,    24,    25,    34,    35,    32,    34,    35,    34,    35,
      34,    35,    34,    35,    30,    30,     3,    34,    32,    32,
      30,    30,    30,    35,     9,    31,    33,    28,    33,    33,
      33,    33,    29,    31,    33,    31,    12,    31,    33,    31,
       9,    34,    31,   114,    35,   157,   244,   112,   243,   104,
     232,   126,   136,   135,   127,   107,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,     3,     5,     6,     7,    12,    13,
      45,    46,    53,    54,    55,    56,    57,    58,    59,    60,
       3,    61,     3,     3,    32,     5,    12,    57,    58,    60,
      46,    54,     3,    66,    67,     3,    61,    35,    61,    61,
      28,    62,    34,    35,    30,    32,    53,    57,    58,    61,
       3,    61,    61,    61,    14,    30,    62,    34,    35,    30,
      35,    35,    35,     4,    30,    63,    64,    65,    28,     3,
      12,    31,    47,    48,    57,    58,    53,    33,     3,    35,
      35,    35,    35,     3,     4,    17,    25,    30,    73,    74,
      75,    79,    81,    83,    84,    31,    47,    67,    31,    47,
      63,    24,    25,    29,    80,    26,    27,    82,    63,    62,
      32,    31,    34,     3,     3,    33,    30,     3,     4,    30,
      84,     3,     4,    30,    84,    73,    15,    16,    18,    19,
      20,    21,    22,    23,    76,    80,    82,    28,    36,    85,
      86,    32,    31,    32,    31,    31,    64,    65,    29,     3,
       8,    10,    11,    32,    35,    38,    52,    53,    68,    69,
      73,    84,    32,    48,    28,    49,    49,    73,    77,    78,
      30,    73,    30,    73,    31,    74,    75,    79,    81,    83,
      79,     3,    52,    32,    52,    32,    30,    30,    30,    52,
      35,    73,    33,    68,    69,    35,    14,    52,    51,    79,
      31,    34,    77,    31,    77,    31,    29,    33,    52,    33,
      52,    77,    77,     3,    70,    71,    72,    73,    33,    35,
      73,    33,    29,    73,    31,    31,    33,    33,    31,    31,
      14,    35,    34,    35,    28,    50,    69,    69,    73,    77,
      72,    79,     9,    35,    29,    69,    70,    50,    31,    69
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
      yyerror (YY_("syntax error: cannot back up")); \
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
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
yyparse (void)
#else
int
yyparse ()

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
      

/* Line 1806 of yacc.c  */
#line 1629 "parser.tab.c"
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
		  yystos[yystate], yyvsp);
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 273 "parser.y"


#include "lex.yy.c"
main (argc, argv)
int argc;
char *argv[];
  {
     yyin = fopen(argv[1],"r");
     yyparse();
     printf("%s\n", "Parsing completed. No errors found.");
  } /* main */


int yyerror (mesg)
char *mesg;
  {
  printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
  exit(1);
  }

