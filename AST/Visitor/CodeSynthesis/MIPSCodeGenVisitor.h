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
#include <string>
using std::string;

class MIPSCodeGenVisitor: public NodeVisitor {
public:
	MIPSCodeGenVisitor(SymbolTable*, ostream&, ostream&);
	virtual ~MIPSCodeGenVisitor();

	virtual void visit(ANDNode& node) {}
	virtual void visit(ArrayDefiningNode& node) {}
	virtual void visit(ArrayReferencingNode& node) {}
	virtual void visit(ArrayVariableDeclaringNode& node) {}
	virtual void visit(AssigningNode& node) {}
	virtual void visit(BinaryExpression&) {}
	virtual void visit(BlockNode& node) {}
	virtual void visit(CallingNode& node);
	virtual void visit(DivideNode& node) {}
	virtual void visit(EQNode& node) {}
	virtual void visit(EmptyNode& node) {}
	virtual void visit(Expression& node) {}
	virtual void visit(FloatLiteral& node) {}
	virtual void visit(ForLoopingNode& node) {}
	virtual void visit(FunctionDeclaringNode& node) {}
	virtual void visit(GENode& node) {}
	virtual void visit(GTNode& node) {}
	virtual void visit(Identifier& node) {}
	virtual void visit(IdentifierList&) {}
	virtual void visit(IdentifierWithDim& node) {}
	virtual void visit(IdentifierWithInitExpr&) {}
	virtual void visit(IfTestingNode& node) {}
	virtual void visit(IntLiteral& node) {}
	virtual void visit(LENode& node) {}
	virtual void visit(LTNode& node) {}
	virtual void visit(Literal&) {}
	virtual void visit(MinusNode& node) {}
	virtual void visit(MultiplyNode& node) {}
	virtual void visit(NENode& node) {}
	virtual void visit(NodeList& node) {}
	virtual void visit(ORNode& node) {}
	virtual void visit(PlusNode& node) {}
	virtual void visit(RelationalExpression& node) {}
	virtual void visit(ReturningNode& node) {}
	virtual void visit(StringLiteral& node) {}
	virtual void visit(StructDefiningNode& node) {}
	virtual void visit(StructReferencingNode& node) {}
	virtual void visit(TypeDeclaringNode& node) {}
	virtual void visit(TypeSpecifier& node) {}
	virtual void visit(TypeSpecifierByName& node) {}
	virtual void visit(TypeSpecifierByStruct& node) {}
	virtual void visit(TypeSpecifierWithTypeDecl& node) {}
	virtual void visit(UnaryExpression&) {}
	virtual void visit(TypedefNode& node) {}
	virtual void visit(VariableListDeclaringNode& node) {}
	virtual void visit(WhileLoopingNode& node) {}

private:
	ostream& codeStream() { return codeOutputStream_; }
	ostream& codeOutputStream_;

	void gen_prologue(string name);
	void gen_epilogue(string name);
};

#endif /* MIPSCODEGENVISITOR_H_ */
