/*
 * TopDeclVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "TopDeclVisitor.h"
#include "TypeVisitor.h"
#include "../../Node/StructDefiningNode.h"
#include "../../Node/TypeDeclaringNode.h"


TopDeclVisitor::TopDeclVisitor(SymbolTable* symtab, ostream& os) : symtab_(symtab), os_(os) {
	// TODO Auto-generated constructor stub

}

TopDeclVisitor::~TopDeclVisitor() {
	// TODO Auto-generated destructor stub
}

void TopDeclVisitor::visit(TypeDeclaringNode& td) {
	TypeVisitor typeVisitor(symtab_, os_);
	td.typeSpec()->accept(typeVisitor);
	// todo: Temporarily stop, not yet complete. See page.338
}

void TopDeclVisitor::visit(TypedefNode & node)
{
}

void TopDeclVisitor::visit(VariableListDeclaringNode & node)
{
}




