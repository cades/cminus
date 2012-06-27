/*
 * SemanticsVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef SEMANTICSVISITOR_H_
#define SEMANTICSVISITOR_H_

#include "../NodeVisitor.h"
class Attributes;
class TypeDescriptor;
#include <list>
using std::list;
class ExpressionList;

class SemanticsVisitor: public NodeVisitor {
public:
	SemanticsVisitor(SymbolTable*, ostream&);
	virtual ~SemanticsVisitor();

	virtual void visit(AssigningNode& node);
	virtual void visit(Identifier&);
	virtual void visit(IntLiteral&);
	virtual void visit(FloatLiteral&);
	virtual void visit(BinaryExpression&);
	virtual void visit(UnaryExpression&);
	virtual void visit(RelationalExpression& node);
	virtual void visit(ArrayReferencingNode&);
	virtual void visit(StructReferencingNode&);
	virtual void visit(CallingNode& node);

	virtual void visit(ANDNode& node) {}
	virtual void visit(ArrayDefiningNode& node) {}
	virtual void visit(ArrayVariableDeclaringNode& node) {}
	virtual void visit(BlockNode& node) {}
	virtual void visit(DivideNode& node) {}
	virtual void visit(EQNode& node) {}
	virtual void visit(EmptyNode& node) {}
	virtual void visit(Expression&) {}
	virtual void visit(ForLoopingNode& node) {}
	virtual void visit(FunctionDeclaringNode& node) {}
	virtual void visit(GENode& node) {}
	virtual void visit(GTNode& node) {}
	virtual void visit(IdentifierList&) {}
	virtual void visit(IdentifierWithDim& node) {}
	virtual void visit(IdentifierWithInitExpr&) {}
	virtual void visit(IfTestingNode& node) {}
	virtual void visit(LENode& node) {}
	virtual void visit(LTNode& node) {}
	virtual void visit(Literal&) {}
	virtual void visit(MinusNode& node) {}
	virtual void visit(MultiplyNode& node) {}
	virtual void visit(NENode& node) {}
	virtual void visit(NodeList& node) {}
	virtual void visit(ORNode& node) {}
	virtual void visit(PlusNode& node) {}
	virtual void visit(ReturningNode& node) {}
	virtual void visit(StringLiteral&) {} // TODO should handle this?
	virtual void visit(StructDefiningNode& node) {}
	virtual void visit(TypeDeclaringNode& node) {}
	virtual void visit(TypeSpecifier& node) {}
	virtual void visit(TypeSpecifierByName& node) {}
	virtual void visit(TypeSpecifierByStruct& node) {}
	virtual void visit(TypeSpecifierWithTypeDecl& node) {}
	virtual void visit(TypedefNode& node) {}
	virtual void visit(VariableListDeclaringNode& node) {}
	virtual void visit(WhileLoopingNode& node) {}

	typedef list<TypeDescriptor*> TypeDescriptorList;
private:
	bool isDataObject(Attributes*);
	bool assignable(TypeDescriptor*, TypeDescriptor*);
	TypeDescriptorList getArgTypes(ExpressionList*);
	bool applicable(TypeDescriptorList, TypeDescriptorList);
	bool bindable(TypeDescriptor*, TypeDescriptor*);
};

#endif /* SEMANTICSVISITOR_H_ */
