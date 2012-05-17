/* ===== Definition Section ===== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int linenumber = 1;
int yylex(void);    
int yyerror (char *mesg);
%}

%union Record {

  struct Lexeme {
    enum Type {stringConst, intConst, floatConst} type;
    union {
      char *stringValue;
      int intValue;
      float floatValue;
    };
  } lexeme;

  struct {
    struct Lexeme lexeme;
    enum SymbolType { const_name, var_name, func_name, struct_tag, param } idType;
    int isArray;
    int dimention;
    int lengthOfDim[10];
  } var_info;

  int num;
}

%type <var_info> var_ref 
%type <num> dim
%type <num> expr

%token <lexeme> ID
%token CONST
%token VOID    
%token INT     
%token FLOAT   
%token IF      
%token ELSE    
%token WHILE   
%token FOR
%token STRUCT  
%token TYPEDEF 
%token OP_ASSIGN  
%token OP_OR   
%token OP_AND  
%token OP_NOT  
%token OP_EQ   
%token OP_NE   
%token OP_GT   
%token OP_LT   
%token OP_GE   
%token OP_LE   
%token OP_PLUS 
%token OP_MINUS        
%token OP_TIMES        
%token OP_DIVIDE       
%token MK_LB 
%token MK_RB 
%token MK_LPAREN       
%token MK_RPAREN       
%token MK_LBRACE       
%token MK_RBRACE       
%token MK_COMMA        
%token MK_SEMICOLON    
%token MK_DOT  
%token ERROR
%token RETURN

%start program

%%

/* ==== Grammar Section ==== */

/* Productions */               /* Semantic actions */
program		: global_decl_list
		;

global_decl_list: global_decl_list global_decl
                |
		;

global_decl	: decl_list function_decl
		| function_decl
		;

function_decl	: type ID MK_LPAREN param_list MK_RPAREN MK_LBRACE block MK_RBRACE 

		| struct_type ID MK_LPAREN param_list MK_RPAREN MK_LBRACE block MK_RBRACE
		| VOID ID MK_LPAREN param_list MK_RPAREN MK_LBRACE block MK_RBRACE

		| type ID MK_LPAREN  MK_RPAREN MK_LBRACE block MK_RBRACE

		| struct_type ID MK_LPAREN  MK_RPAREN MK_LBRACE block MK_RBRACE

		| VOID ID MK_LPAREN  MK_RPAREN MK_LBRACE block MK_RBRACE
		;

param_list	: param_list MK_COMMA  param
		| param	
		;

param		: type ID
		| struct_type ID
		| type ID dim_fn
		| struct_type ID dim_fn 
		;
dim_fn		:MK_LB expr_null MK_RB dimfn1
		;
dimfn1		:MK_LB expr MK_RB dimfn1
		|
		;
expr_null	:expr
		|
		;

block           : decl_list stmt_list
                | stmt_list
                | decl_list
                |
                ;
 
decl_list	: decl_list decl
		| decl
		;

decl	: type_decl
		| var_decl
		;

type_decl 	: TYPEDEF type id_list MK_SEMICOLON
		| TYPEDEF VOID id_list MK_SEMICOLON
                | TYPEDEF struct_type id_list MK_SEMICOLON
                | struct_decl MK_SEMICOLON /* It's struct_decl, NOT struct_type */
                | TYPEDEF anonymous_struct id_list MK_SEMICOLON
		;

var_decl	: type init_id_list MK_SEMICOLON
		| struct_type id_list MK_SEMICOLON
                | struct_decl id_list MK_SEMICOLON
                | anonymous_struct id_list MK_SEMICOLON
                | ID id_list MK_SEMICOLON  /* the former ID is typedefed struct*/
		;

type		: INT
		| FLOAT
		;

struct_type	: STRUCT ID		/* | something missing here, isn't it? */
		;
struct_decl     : STRUCT ID MK_LBRACE decl_list MK_RBRACE
                ;
anonymous_struct: STRUCT MK_LBRACE decl_list MK_RBRACE
                ;

id_list		: ID
		| id_list MK_COMMA ID
		| id_list MK_COMMA ID dim_decl
		| ID dim_decl
		;
dim_decl	: MK_LB cexpr MK_RB 
		| dim_decl MK_LB cexpr MK_RB
		;
cexpr		: cexpr add_op mcexpr /* This is for array declarations */
		| mcexpr
		;  
mcexpr		: mcexpr mul_op cfactor
		| cfactor 
		;
cfactor:	CONST
		| MK_LPAREN cexpr MK_RPAREN
		;

init_id_list	: init_id
		| init_id_list MK_COMMA init_id
		;

init_id		: ID
		| ID dim_decl
		| ID OP_ASSIGN relop_expr
		;

stmt_list	: stmt_list stmt
		| stmt
		;

stmt		: MK_LBRACE block MK_RBRACE
		/* | While Statement */
                | WHILE MK_LPAREN relop_expr_list MK_RPAREN stmt 
                /* | for Statement */
	        | FOR MK_LPAREN assign_expr_list MK_SEMICOLON relop_expr_list MK_SEMICOLON assign_expr_list MK_RPAREN stmt 
		| var_ref OP_ASSIGN relop_expr MK_SEMICOLON
                /* Can do something and discard it, without assign.
		   This rule enable function call, implicitly. read and write library calls is contained.
		 */
                | relop_expr MK_SEMICOLON
		/* | If statement */ 
                | IF MK_LPAREN relop_expr_list MK_RPAREN stmt
		/* | If then else */ 
                | IF MK_LPAREN relop_expr_list MK_RPAREN stmt ELSE stmt
		| MK_SEMICOLON
		| RETURN MK_SEMICOLON
		| RETURN relop_expr MK_SEMICOLON
		;

assign_expr_list : nonempty_assign_expr_list
                |
                ;

nonempty_assign_expr_list        : nonempty_assign_expr_list MK_COMMA assign_expr
                | assign_expr
                ;

assign_expr     : ID OP_ASSIGN relop_expr
                | relop_expr
                ;

relop_expr	: relop_term
		| relop_expr OP_OR relop_term
		;

relop_term	: relop_factor
		| relop_term OP_AND relop_factor
		;

relop_factor	: expr
		| expr rel_op expr
		;

rel_op		: OP_EQ
		| OP_GE
		| OP_LE
		| OP_NE
		| OP_GT
		| OP_LT
		;

relop_expr_list	: nonempty_relop_expr_list 
		| 
		;

nonempty_relop_expr_list	: nonempty_relop_expr_list MK_COMMA relop_expr
		| relop_expr
		;

expr		: expr add_op term
		| term
		;

add_op		: OP_PLUS
		| OP_MINUS
		;

term		: term mul_op factor
		| factor
		;

mul_op		: OP_TIMES
		| OP_DIVIDE
		;

factor		: MK_LPAREN relop_expr MK_RPAREN /* | -(<relop_expr>) */
                | OP_MINUS MK_LPAREN relop_expr MK_RPAREN 
		| OP_NOT MK_LPAREN relop_expr MK_RPAREN
		/* | - constant, here - is an Unary operator */ 
                | CONST
		| OP_MINUS CONST
                | OP_NOT CONST
		/* | - func ( <relop_expr_list> ) */ 
		| ID MK_LPAREN relop_expr_list MK_RPAREN
		| OP_MINUS ID MK_LPAREN relop_expr_list MK_RPAREN
		| OP_NOT ID MK_LPAREN relop_expr_list MK_RPAREN
		/* | - var-reference */ 
		| var_ref
		| OP_MINUS var_ref
		| OP_NOT var_ref
		;
var_ref		: ID { $$.lexeme = $1; }
                | var_ref dim  /* knowing I'm a array */
		{
		  $$ = $1;
		  $$.isArray = 1;
		  $$.lengthOfDim[$$.dimention] = $2;
		  $$.dimention++;
		}
                | var_ref struct_tail { $$ = $1; } /* knowing I'm a struct */
		;


dim		: MK_LB expr MK_RB { $$ = $2; }
		;

struct_tail	: MK_DOT ID
		;

%%

#include "lex.yy.c"
#define TABLE_SIZE 1024

main (int argc, char *argv[])
  {
     yyin = fopen(argv[1],"r");
     yyparse();
     printf("%s\n", "Parsing completed. No errors found.");
  } /* main */


int yyerror (char *mesg)
  {
  printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
  exit(1);
  }
