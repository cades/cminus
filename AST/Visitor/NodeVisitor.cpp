/*
 * NodeVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "NodeVisitor.h"
#include "../Node/AbstractNode.h"
#include <stdexcept>
#include <typeinfo>
#include <string>
#include "../Node/Iterator/IIterator.h"

NodeVisitor::NodeVisitor(SymbolTable* symtab, ostream& os) : symtab_(symtab), os_(os) {
	// TODO Auto-generated constructor stub

}

NodeVisitor::~NodeVisitor() {
	// TODO Auto-generated destructor stub
}

void NodeVisitor::visitChildren(AbstractNode& node) {
	visitChildren_via_iter(node);
}

void NodeVisitor::visitChildren_via_getChild(AbstractNode& node)
{
	for (int i = 0; i != node.childrenNumber(); ++i) {
		node.getChild(i)->accept(*this);
	}
}

void NodeVisitor::visitChildren_via_iter(AbstractNode& node)
{
	IIterator* i = node.createIterator();
	for (i->First(); !i->IsDone(); i->Next()) {
		i->CurrentItem()->accept(*this);
	}
	delete i;
}

void NodeVisitor::visit(AbstractNode & node)
{
	throw std::runtime_error(std::string("catch-all visit method catched a new subclass: ") + typeid(&node).name());
}




