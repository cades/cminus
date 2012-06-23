/*
 * TopDeclVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef TOPDECLVISITOR_H_
#define TOPDECLVISITOR_H_

#include "SemanticsVisitor.h"
#include "../../Node/NodeList.h" // because I have to know that 'NodeList extends AbstractNode'
class SymbolTable;
#include <iosfwd>
using std::ostream;

class TopDeclVisitor: public SemanticsVisitor {
public:
	TopDeclVisitor(SymbolTable*, ostream&);
	virtual ~TopDeclVisitor();


//	virtual void visit(ArrayVariableDeclaringNode& node);
//	virtual void visit(FunctionDeclaringNode& node);
	virtual void visit(TypeDeclaringNode&);
	virtual void visit(TypedefNode& node);
	virtual void visit(VariableListDeclaringNode& node);
	virtual void visit(NodeList& node) { NodeVisitor::visitChildren(node); }

	virtual void visit(ANDNode& node) {}
	virtual void visit(ArrayDefiningNode& node) {}
	virtual void visit(ArrayReferencingNode& node) {}
	virtual void visit(AssigningNode& node) {}
	virtual void visit(BlockNode& node) {}
	virtual void visit(CallingNode& node) {}
	virtual void visit(DivideNode& node) {}
	virtual void visit(EQNode& node) {}
	virtual void visit(EmptyNode& node) {}
	virtual void visit(FloatLiteral& node) {}
	virtual void visit(ForLoopingNode& node) {}
	virtual void visit(GENode& node) {}
	virtual void visit(GTNode& node) {}
	virtual void visit(Identifier& node) {}
	virtual void visit(IdentifierWithDim& node) {}
	virtual void visit(IfTestingNode& node) {}
	virtual void visit(IntLiteral& node) {}
	virtual void visit(LENode& node) {}
	virtual void visit(LTNode& node) {}
	virtual void visit(MinusNode& node) {}
	virtual void visit(MultiplyNode& node) {}
	virtual void visit(NENode& node) {}
	virtual void visit(NegNode& node) {}
	virtual void visit(NotNode& node) {}
	virtual void visit(ORNode& node) {}
	virtual void visit(PlusNode& node) {}
	virtual void visit(ReturningNode& node) {}
	virtual void visit(StringLiteral& node) {}
	virtual void visit(StructDefiningNode& node) {}
	virtual void visit(StructReferencingNode& node) {}
	virtual void visit(TypeSpecifier& node) {}
	virtual void visit(TypeSpecifierByName& node) {}
	virtual void visit(TypeSpecifierByStruct& node) {}
	virtual void visit(TypeSpecifierWithTypeDecl& node) {}
	virtual void visit(WhileLoopingNode& node) {}

protected:
	SymbolTable& currentSymbolTable() { return *symtab_; }
	SymbolTable* symtab_;
	ostream& os_;
};

#endif /* TOPDECLVISITOR_H_ */
