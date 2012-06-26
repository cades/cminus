/*
 * NodeVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef NODEVISITOR_H_
#define NODEVISITOR_H_

class SymbolTable;
#include <iosfwd>
using std::ostream;

class AbstractNode;
class ANDNode;
class AbstractNode;
class ArrayDefiningNode;
class ArrayReferencingNode;
class ArrayVariableDeclaringNode;
class AssigningNode;
class BinaryExpression;
class BlockNode;
class CallingNode;
class DivideNode;
class EQNode;
class EmptyNode;
class Expression;
class Factor;
class FloatLiteral;
class ForLoopingNode;
class FunctionDeclaringNode;
class GENode;
class GTNode;
class Identifier;
class IdentifierList;
class IdentifierWithDim;
class IdentifierWithInitExpr;
class IfTestingNode;
class IntLiteral;
class LENode;
class LTNode;
class Literal;
class MinusNode;
class MultiplyNode;
class NENode;
class NegNode;
class NodeList;
class NotNode;
class ORNode;
class PlusNode;
class RelationalExpression;
class ReturningNode;
class StringLiteral;
class StructDefiningNode;
class StructReferencingNode;
class TypeDeclaringNode;
class TypeSpecifier;
class TypeSpecifierByName;
class TypeSpecifierByStruct;
class TypeSpecifierWithTypeDecl;
class UnaryExpression;
class TypedefNode;
class VariableListDeclaringNode;
class WhileLoopingNode;

class NodeVisitor {
public:
	NodeVisitor(SymbolTable*, ostream&);
	virtual ~NodeVisitor();
	void visitChildren(AbstractNode& node);
	virtual void visit(ANDNode& node) = 0;
	virtual void visit(AbstractNode& node); // catch all with implementation: throw exception
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
	void visitChildren_via_getChild(AbstractNode&);
	void visitChildren_via_iter(AbstractNode&);

protected:
	SymbolTable& currentSymbolTable() { return *symtab_; }
	ostream& errorLog() { return os_; }
	void setSymbolTableTo(SymbolTable *newSymtab) { symtab_ = newSymtab; } // this door is open for TopDeclVisitor::setCurrentSymbolTableTo

private:
	SymbolTable* symtab_;
	ostream& os_;
};

#endif /* NODEVISITOR_H_ */
