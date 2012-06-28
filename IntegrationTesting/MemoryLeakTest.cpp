#include <iostream>
#include "../ASTHeaders.h"
#include "../visitorsHeaders.h"
#include <CppUTest/TestHarness.h>

extern int yyerror (AbstractNode* node, char *mesg);
extern int yyparse (AbstractNode* root);

TEST_GROUP(YYParseShould) {
};

TEST(YYParseShould, notLeak) {
    //yyin = fopen("./simpleInput/emptyMain.c","r");
    AbstractNode* astRoot = 0;
    
    yyparse(astRoot);  // pass AST root to yyparse
    //fclose(yyin);
}
