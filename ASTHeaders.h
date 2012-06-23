#ifndef ASTHEADERS_H_
#define ASTHEADERS_H_

#include "AST/Node/AbstractNode.h"
#include "AST/Node/EmptyNode.h"
#include "AST/Node/NodeList.h"
#include "AST/Node/IdentifierList.h"
#include "AST/Node/VariableDeclaringList.h"

// terminals
#include "AST/Node/Identifier.h"
#include "AST/Node/IdentifierWithDim.h"
#include "AST/Node/IdentifierWithInitExpr.h"
#include "AST/Node/Literal.h"
#include "AST/Node/IntLiteral.h"
#include "AST/Node/FloatLiteral.h"
#include "AST/Node/StringLiteral.h"



// nonterminals
#include "AST/Node/PlusNode.h"
#include "AST/Node/MinusNode.h"
#include "AST/Node/MultiplyNode.h"
#include "AST/Node/DivideNode.h"

#include "AST/Node/Expression.h"
#include "AST/Node/EmptyExpression.h"
#include "AST/Node/Factor.h"
#include "AST/Node/NegNode.h"
#include "AST/Node/NotNode.h"
#include "AST/Node/ANDNode.h"
#include "AST/Node/ORNode.h"
#include "AST/Node/EQNode.h"
#include "AST/Node/GENode.h"
#include "AST/Node/LENode.h"
#include "AST/Node/NENode.h"
#include "AST/Node/GTNode.h"
#include "AST/Node/LTNode.h"


#include "AST/Node/FunctionDeclaringNode.h"
#include "AST/Node/ArrayVariableDeclaringNode.h"
#include "AST/Node/ArrayDefiningNode.h"
#include "AST/Node/BlockNode.h"
#include "AST/Node/TypedefNode.h"
#include "AST/Node/VariableListDeclaringNode.h"
#include "AST/Node/TypeDeclaringNode.h"
#include "AST/Node/StructDefiningNode.h"
#include "AST/Node/AssigningNode.h"
#include "AST/Node/WhileLoopingNode.h"
#include "AST/Node/ForLoopingNode.h"
#include "AST/Node/IfTestingNode.h"
#include "AST/Node/ReturningNode.h"
#include "AST/Node/ArrayReferencingNode.h"
#include "AST/Node/StructReferencingNode.h"
#include "AST/Node/CallingNode.h"

#include "AST/Node/TypeSpecifierByName.h"
#include "AST/Node/TypeSpecifierByStruct.h"


// symbol table
#include "AST/SymbolTable/SymbolTable.h"


union YYSTYPE {
    enum StructKind { STRUCT, UNION };
    enum OpKind { OP_EQ, OP_GE, OP_LE, OP_NE, OP_GT, OP_LT };
    StructKind structKind;
    OpKind opKind;
    AbstractNode* node;
    NodeList* nodeList;
    IdentifierList* idList;
    Identifier* id;
    Expression* expr;
    TypeDeclaringNode* typeDeclNode;
    VariableDeclaringList* declList;
    VariableListDeclaringNode* varListDecl;
    StructDefiningNode* structDef;
};

typedef union YYSTYPE YYSTYPE;


#endif
