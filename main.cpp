#include <stdio.h>
#include "ASTHeaders.h"
#include "visitorsHeaders.h"
#include <iostream>
using std::cout;
extern FILE* yyin;
extern int yyparse (AbstractNode*& root, LocalVarRepo localVarRepo);

int main (int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    AbstractNode* astRoot = 0;
    
    yyparse(astRoot, LocalVarRepo());  // pass AST root to yyparse
    
    SymbolTable symbolTable;
    TopDeclVisitor tdVisitor(&symbolTable, cout);
    astRoot->accept(tdVisitor);
    //MIPSCodeGenVisitor codegenVisitor(&symbolTable, cerr, cout);
    //astRoot->accept(codegenVisitor);
    
    printf("%s\n", "Parsing completed. No errors found.");
    fclose(yyin);
}
