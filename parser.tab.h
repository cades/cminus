/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


