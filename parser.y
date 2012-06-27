/* ===== Definition Section ===== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "ASTHeaders.h"
#include "visitorsHeaders.h"
using namespace std;
static int linenumber = 1;

struct LocalVarRepo {
    string currentTypeName;
};
    
int yylex(void);    
int yyerror (AbstractNode* node, LocalVarRepo localVarRepo, char *mesg);

    
void error(string msg) {
  cout << "Error found in line " << linenumber << endl << msg << endl;
}


Identifier* generateUniqueId() {
    static int uniqueId = 0;
    stringstream ss;
    ss << "UNIQUE_ID_NO." << uniqueId;
    return new Identifier(ss.str());
}

%}

%type <node> decl type_decl function_decl param  
%type <id>   type tag opt_tag struct_tail /* reference */
%type <node> stmt block
%type <node> dim_decl dimfn1 
%type <opKind> rel_op
%type <nodeList> program global_decl_list global_decl param_list decl_list stmt_list
%type <expr> cexpr_null cexpr mcexpr cfactor expr term factor relop_expr relop_term relop_factor var_ref assign_expr dim
/*%type <typeDeclNode> */
%type <idList> id_list init_id_list
%type <declList> struct_declaration_list
%type <exprList> relop_expr_list assign_expr_list nonempty_assign_expr_list nonempty_relop_expr_list
%type <varListDecl> var_decl struct_declaration
%type <id> init_id
%type <structDef> struct_type
%type <arrayDef> dim_fn

%token <expr> CONST
%token <id> ID
%token <node> OP_ASSIGN   OP_OR    OP_AND   OP_NOT   
%token <node> OP_PLUS  OP_MINUS  OP_TIMES  OP_DIVIDE
%token <opKind> OP_EQ    OP_NE    OP_GT    OP_LT    OP_GE    OP_LE
%token WHILE FOR IF ELSE VOID INT FLOAT STRUCT TYPEDEF MK_COMMA MK_DOT  MK_LB MK_LBRACE MK_LPAREN MK_RB MK_RBRACE MK_RPAREN MK_SEMICOLON RETURN ERROR 
 


%parse-param {AbstractNode*& root}
%parse-param {LocalVarRepo localVarRepo}

%start program

%%

/* ==== Grammar Section ==== */

/* Productions */               /* Semantic actions */
program		: global_decl_list	       	{ $$ = $1; root = $1; }
		;

global_decl_list: global_decl_list global_decl	{ $1->append($2); $$ = $1; }
                | { $$ = new NodeList; } /* empty list */
		;

global_decl	: decl_list function_decl	{ $1->append($2); $$ = $1; }
		| function_decl			{  $$ = new NodeList; $$->append($1); }
		;

function_decl	: type ID MK_LPAREN param_list MK_RPAREN MK_LBRACE block MK_RBRACE
		{ $$ = new FunctionDeclaringNode($1, $2, $4, $7); }
        | ID ID MK_LPAREN param_list MK_RPAREN MK_LBRACE block MK_RBRACE
        { $$ = new FunctionDeclaringNode($1, $2, $4, $7); }
		| type ID MK_LPAREN  MK_RPAREN MK_LBRACE block MK_RBRACE
		{ $$ = new FunctionDeclaringNode($1, $2, new NodeList, $6); }
        | ID ID MK_LPAREN  MK_RPAREN MK_LBRACE block MK_RBRACE
        { $$ = new FunctionDeclaringNode($1, $2, new NodeList, $6); }
		;

param_list	: param_list MK_COMMA  param	{ $1->append($3); $$ = $1; }
		| param				{ $$ = new NodeList; $$->append($1); }
		;

param		: type ID		{ $$ = new VariableListDeclaringNode($1, $2); }
		| type ID dim_fn    { $$ = new ArrayVariableDeclaringNode($1, $2, $3); }
		;
dim_fn		:MK_LB cexpr_null MK_RB dimfn1 { $$ = new ArrayDefiningNode($2, $4); }
		;
dimfn1		:MK_LB cexpr MK_RB dimfn1 { $$ = new ArrayDefiningNode($2, $4); }
		| { $$ = new Identifier(localVarRepo.currentTypeName); } /* In type checking phase, it'll be replaced by a TypeDescriptor. */
		;
cexpr_null	:cexpr	{ $$ = $1; }
		|	{ $$ = new EmptyExpression; }
		;

block		: decl_list stmt_list	{ $1->append($2); delete $2; $$ = new BlockNode($1); }
		| stmt_list		{ $$ = new BlockNode($1); }
		| decl_list		{ $$ = new BlockNode($1); } /* actually a block contains decl without stmt is useless. */
		|			{ $$ = new EmptyNode; }
		;
 
decl_list	: decl_list decl       	{ $1->append($2); $$ = $1; }
		| decl			{ $$ = new NodeList; $$->append($1); }
		;

decl		: type_decl	{ $$ = $1; }
		| var_decl	{ $$ = $1; }
		;

type_decl 	: TYPEDEF type id_list MK_SEMICOLON		{ $$ = new TypedefNode($2, $3); }
        | TYPEDEF struct_type id_list MK_SEMICOLON		{ $$ = new TypeDeclaringNode($3, $2); }
		;

var_decl	: type { localVarRepo.currentTypeName = $1->name(); } init_id_list MK_SEMICOLON	{ $$ = new VariableListDeclaringNode($1, $3); localVarRepo.currentTypeName = ""; }
		| ID { localVarRepo.currentTypeName = $1->name(); } id_list MK_SEMICOLON		{ $$ = new VariableListDeclaringNode($1, $3); localVarRepo.currentTypeName = ""; } /* the former ID is typedefed struct*/
		;

type		: INT	{ $$ = new Identifier("int");}
		| FLOAT	{ $$ = new Identifier("float");}
		| VOID { $$ = new Identifier("void"); }
		;

struct_type	: STRUCT opt_tag MK_LBRACE struct_declaration_list MK_RBRACE	{ $$ = new StructDefiningNode($4); delete $2; }
/*		| STRUCT tag {}*/
		;
struct_declaration_list
		: struct_declaration				{ $$ = new VariableDeclaringList; $$->append($1); }
		| struct_declaration_list struct_declaration	{ $1->append($2); $$ = $1; }
		;
struct_declaration:
		var_decl { $$ = $1; }
		;
opt_tag		: tag	{ $$ = $1; }
		|	{ $$ = generateUniqueId(); /*$$ = new Identifier("[struct:"+$2->name()+"]"); delete $2;*/ }
		;
tag		: ID	{ $$ = $1; }
		;

id_list		: ID				{ $$ = new IdentifierList; $$->append($1); }
		| id_list MK_COMMA ID		{ $1->append($3); $$ = $1; }
		| id_list MK_COMMA ID dim_decl	{ $3 = new IdentifierWithDim($3, $4); delete $3; $1->append($3); $$ = $1; }
		| ID dim_decl			{ $1 = new IdentifierWithDim($1, $2); delete $2; $$ = new IdentifierList; $$->append($1); }
		;
dim_decl	: MK_LB cexpr MK_RB		{ $$ = new ArrayDefiningNode($2, new Identifier(localVarRepo.currentTypeName)); }
		| MK_LB cexpr MK_RB dim_decl	{ $$ = new ArrayDefiningNode($2, $4);  } /* refactor to right-recursion */
		;
cexpr		: cexpr OP_PLUS mcexpr	{ $$ = new PlusNode($1, $3); }
		| cexpr OP_MINUS mcexpr	{ $$ = new MinusNode($1, $3); }
		| mcexpr		{ $$ = $1; }
		;  
mcexpr		: mcexpr OP_TIMES cfactor	{ $$ = new MultiplyNode($1, $3); }
		| mcexpr OP_DIVIDE cfactor	{ $$ = new DivideNode($1, $3); }
		| cfactor			{ $$ = $1; }
		;
cfactor		: CONST				{ $$ = $1; }
		| MK_LPAREN cexpr MK_RPAREN	{ $$ = $2; } /* at this point, cexpr has been computed */
		;

init_id_list	: init_id			{ $$ = new IdentifierList; $$->append($1); }
		| init_id_list MK_COMMA init_id	{ $1->append($3); $$ = $1; }
		;

init_id		: ID				{ $$ = $1; }
		| ID dim_decl			{ $1 = new IdentifierWithDim($1, $2); delete $1; $$ = $1;}
		| ID OP_ASSIGN relop_expr	{ $$ = new IdentifierWithInitExpr($1, $3); }
		;

stmt_list	: stmt_list stmt	{ $1->append($2); $$ = $1; }
		| stmt			{ $$ = new NodeList; $$->append($1); }
		;

stmt		: MK_LBRACE block MK_RBRACE	{ $$ = $2; }
		/* | While Statement */
		| WHILE MK_LPAREN relop_expr_list MK_RPAREN stmt { $$ = new WhileLoopingNode($3, $5); }
		/* | for Statement */
		| FOR MK_LPAREN assign_expr_list MK_SEMICOLON relop_expr_list MK_SEMICOLON assign_expr_list MK_RPAREN stmt
		{ $$ = new ForLoopingNode($3, $5, $7, $9); } 
		| assign_expr MK_SEMICOLON	{ $$ = $1; }
		/* | If statement */ 
		| IF MK_LPAREN relop_expr_list MK_RPAREN stmt		{ $$ = new IfTestingNode($3, $5, new EmptyNode); }
		/* | If then else */ 
		| IF MK_LPAREN relop_expr_list MK_RPAREN stmt ELSE stmt	{ $$ = new IfTestingNode($3, $5, $7); }
		| MK_SEMICOLON				{ $$ = new EmptyNode; }
		| RETURN MK_SEMICOLON			{ $$ = new ReturningNode(new EmptyNode); }
		| RETURN relop_expr MK_SEMICOLON	{ $$ = new ReturningNode($2); }
		;

assign_expr_list : nonempty_assign_expr_list  { $$ = $1; }
		| { $$ = new ExpressionList; } /* empty nodelist*/
		;

nonempty_assign_expr_list        : nonempty_assign_expr_list MK_COMMA assign_expr { $1->append($3); $$ = $1; }
		| assign_expr { $$ = new ExpressionList; $$->append($1); }
		;

assign_expr     : var_ref OP_ASSIGN relop_expr { $$ = new AssigningNode($1, $3); }
		| relop_expr { $$ = $1; }
		;

relop_expr	: relop_term { $$ = $1; }
		| relop_expr OP_OR relop_term { $$ = new ORNode($1, $3); }
		;

relop_term	: relop_factor { $$ = $1; }
		| relop_term OP_AND relop_factor { $$ = new ANDNode($1, $3); }
		;

relop_factor	: expr { $$ = $1; }
		| expr rel_op expr
{
  switch($2) {
  case YYSTYPE::OP_EQ:
    $$ = new EQNode($1, $3);
    break;
  case YYSTYPE::OP_GE:
    $$ = new GENode($1, $3);
    break;
  case YYSTYPE::OP_LE:
    $$ = new LENode($1, $3);
    break;
  case YYSTYPE::OP_NE:
    $$ = new NENode($1, $3);
    break;
  case YYSTYPE::OP_GT:
    $$ = new GTNode($1, $3);
    break;
  case YYSTYPE::OP_LT:
    $$ = new LTNode($1, $3);
    break;
  }
}
		;

rel_op		: OP_EQ	{ $$ = $1; }
		| OP_GE	{ $$ = $1; }
		| OP_LE	{ $$ = $1; }
		| OP_NE	{ $$ = $1; }
		| OP_GT	{ $$ = $1; }
		| OP_LT	{ $$ = $1; }
		;

relop_expr_list	: nonempty_relop_expr_list { $$ = $1; }
		| { $$ = new ExpressionList; } /* empty nodelist */
		;

nonempty_relop_expr_list	: nonempty_relop_expr_list MK_COMMA relop_expr { $1->append($3); $$ = $1; }
		| relop_expr		{ $$ = new ExpressionList; $$->append($1); }
		;

expr		: expr OP_PLUS term	{ $$ = new PlusNode($1, $3); }
		| expr OP_MINUS term	{ $$ = new MinusNode($1, $3); }
		| term			{ $$ = $1; }

term		: term OP_TIMES factor	{ $$ = new MultiplyNode($1, $3); }
		| term OP_DIVIDE factor	{ $$ = new DivideNode($1, $3); }
		| factor		{ $$ = $1; }
		;

factor		: MK_LPAREN relop_expr MK_RPAREN		{ $$ = new Factor($2); } /* | -(<relop_expr>) */
		| OP_MINUS MK_LPAREN relop_expr MK_RPAREN	{ $$ = new NegNode($3); }
		| OP_NOT MK_LPAREN relop_expr MK_RPAREN		{ $$ = new NotNode($3); }
		/* | - constant, here - is an Unary operator */ 
		| CONST			{ $$ = $1; }
		| OP_MINUS CONST	{ $$ = new NegNode($2); }
		| OP_NOT CONST		{ $$ = new NotNode($2); }
		/* | - func ( <relop_expr_list> ) */ 
		| ID MK_LPAREN relop_expr_list MK_RPAREN		{ $$ = new CallingNode($1, $3); }
		| OP_MINUS ID MK_LPAREN relop_expr_list MK_RPAREN	{ $$ = new NegNode(new CallingNode($2, $4)); }
		| OP_NOT ID MK_LPAREN relop_expr_list MK_RPAREN		{ $$ = new NotNode(new CallingNode($2, $4)); }
		/* | - var-reference */ 
		| var_ref		{ $$ = new Factor($1); }    // Factor is an 'adaptor', convert AbstractNode* to Expression*
		| OP_MINUS var_ref	{ $$ = new NegNode($2); }
		| OP_NOT var_ref	{ $$ = new NotNode($2); }
		;
var_ref		: ID		{ $$ = $1; }/*{ if (!symtab.retrieveSymbol($1)) error(); }*/
		| var_ref dim	{ $$ = new ArrayReferencingNode($1, $2); } /* knowing I'm a array. see Dragon book p.383-385. */
		| var_ref struct_tail { $$ = new StructReferencingNode($1, $2); } /* knowing I'm a struct */
		;


dim		: MK_LB expr MK_RB { $$ = $2; }
		;

struct_tail	: MK_DOT ID { $$ = $2; }
		;

%%

#include "lex.yy.c"
//extern int main(); // when using CppTest, main should leave to CppUTest.

int main (int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    AbstractNode* astRoot = 0;
    
    yyparse(astRoot, LocalVarRepo());  // pass AST root to yyparse
    
    SymbolTable symbolTable;
    TopDeclVisitor tdVisitor(&symbolTable, cout);
    astRoot->accept(tdVisitor);
    
    printf("%s\n", "Parsing completed. No errors found.");
} /* main */


int yyerror (AbstractNode* node, LocalVarRepo localVarRepo, char *mesg)
{
    printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
    exit(1);
}
