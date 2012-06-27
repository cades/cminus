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

	virtual void visit(ArrayVariableDeclaringNode& node);
	virtual void visit(FunctionDeclaringNode& node);
	virtual void visit(TypeDeclaringNode&);
	virtual void visit(TypedefNode& node);
	virtual void visit(VariableListDeclaringNode& node);
	virtual void visit(NodeList& node) { NodeVisitor::visitChildren(node); }

protected:
	void setCurrentSymbolTableTo(SymbolTable*);
	void setCurrentSymbolTableBack();
	SemanticsVisitor::TypeDescriptorList generateSignature(NodeList*);
private:
	SymbolTable* const originalSymtab_;
};

#endif /* TOPDECLVISITOR_H_ */
