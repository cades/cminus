/*
 * MIPSCodeGenVisitor.h
 *
 *  Created on: 2012/6/28
 *      Author: mac
 */

#ifndef MIPSCODEGENVISITOR_H_
#define MIPSCODEGENVISITOR_H_

#include "../NodeVisitor.h"
#include <ostream>
using std::ostream;

class MIPSCodeGenVisitor: public NodeVisitor {
public:
	MIPSCodeGenVisitor(SymbolTable*, ostream&, ostream&);
	virtual ~MIPSCodeGenVisitor();

	virtual void visit(ANDNode& node) = 0;
	virtual void visit(ArrayDefiningNode& node) = 0;
	virtual void visit(ArrayReferencingNode& node) = 0;
	virtual void visit(ArrayVariableDeclaringNode& node) = 0;
	virtual void visit(AssigningNode& node) = 0;
	virtual void visit(BinaryExpression&) = 0;
	virtual void visit(BlockNode& node) = 0;
	virtual void visit(CallingNode& node) = 0;
	virtual void visit(DivideNode& node) = 0;
	virtual void visit(EQNode& node) = 0;
	virtual void visit(EmptyNode& node) = 0;
	virtual void visit(Expression&) = 0;
	virtual void visit(FloatLiteral& node) = 0;
	virtual void visit(ForLoopingNode& node) = 0;
	virtual void visit(FunctionDeclaringNode& node) = 0;
	virtual void visit(GENode& node) = 0;
	virtual void visit(GTNode& node) = 0;
	virtual void visit(Identifier& node) = 0;
	virtual void visit(IdentifierList&) = 0;
	virtual void visit(IdentifierWithDim& node) = 0;
	virtual void visit(IdentifierWithInitExpr&) = 0;
	virtual void visit(IfTestingNode& node) = 0;
	virtual void visit(IntLiteral& node) = 0;
	virtual void visit(LENode& node) = 0;
	virtual void visit(LTNode& node) = 0;
	virtual void visit(Literal&) = 0;
	virtual void visit(MinusNode& node) = 0;
	virtual void visit(MultiplyNode& node) = 0;
	virtual void visit(NENode& node) = 0;
	virtual void visit(NodeList& node) = 0;
	virtual void visit(ORNode& node) = 0;
	virtual void visit(PlusNode& node) = 0;
	virtual void visit(RelationalExpression& node) = 0;
	virtual void visit(ReturningNode& node) = 0;
	virtual void visit(StringLiteral& node) = 0;
	virtual void visit(StructDefiningNode& node) = 0;
	virtual void visit(StructReferencingNode& node) = 0;
	virtual void visit(TypeDeclaringNode& node) = 0;
	virtual void visit(TypeSpecifier& node) = 0;
	virtual void visit(TypeSpecifierByName& node) = 0;
	virtual void visit(TypeSpecifierByStruct& node) = 0;
	virtual void visit(TypeSpecifierWithTypeDecl& node) = 0;
	virtual void visit(UnaryExpression&) = 0;
	virtual void visit(TypedefNode& node) = 0;
	virtual void visit(VariableListDeclaringNode& node) = 0;
	virtual void visit(WhileLoopingNode& node) = 0;

private:
	ostream& codeStream() { return codeOutputStream_; }
	ostream& codeOutputStream_;
};

#endif /* MIPSCODEGENVISITOR_H_ */
