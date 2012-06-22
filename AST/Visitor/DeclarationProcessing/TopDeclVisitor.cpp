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
#include "../../SymbolTable/SymbolTable.h"
#include "../../SymbolTable/Attributes/TypeAttributes.h"

TopDeclVisitor::TopDeclVisitor(SymbolTable* symtab, ostream& os) : symtab_(symtab), os_(os) {
	// TODO Auto-generated constructor stub

}

TopDeclVisitor::~TopDeclVisitor() {
	// TODO Auto-generated destructor stub
}

void TopDeclVisitor::visit(TypeDeclaringNode& td) {
	TypeVisitor typeVisitor(&currentSymbolTable(), os_);
	td.typeSpec()->accept(typeVisitor);
	if (currentSymbolTable().declaredLocally(td.nameAsString())) {
		td.getTypeName()->setAttributes(0);
	} else {
		TypeAttributes* attr = new TypeAttributes;
		attr->setType(td.typeSpec()->getType());
		currentSymbolTable().enterSymbol(td.nameAsString(), attr);
		td.getTypeName()->setAttributes(attr);
	}
}

void TopDeclVisitor::visit(TypedefNode & node) {
}

void TopDeclVisitor::visit(VariableListDeclaringNode & node)
{
}




