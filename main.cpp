#include "ASTHeaders.h"
#include "visitorsHeaders.h"
#include <iostream>
#include <sstream>
using namespace std;
extern FILE* yyin;
extern int yyparse (AbstractNode*& root, LocalVarRepo localVarRepo);

int main (int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    AbstractNode* astRoot = 0;
    
    yyparse(astRoot, LocalVarRepo());  // pass AST root to yyparse
    
    SymbolTable symbolTable;
    ostringstream errorLogStream;
    TopDeclVisitor tdVisitor(&symbolTable, errorLogStream);
    astRoot->accept(tdVisitor);
    
    MIPSCodeGenVisitor codegenVisitor(&symbolTable, errorLogStream, cout);
    astRoot->accept(codegenVisitor);
    
    if (errorLogStream.str() == "") {
        cout << "Parsing completed. No errors found.\n";
    }
    fclose(yyin);
}
