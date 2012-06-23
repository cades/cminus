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
#include "../../Node/TypedefNode.h"
#include "../../Node/VariableListDeclaringNode.h"
#include "../../Node/FunctionDeclaringNode.h"
#include "../../SymbolTable/SymbolTable.h"
#include "../../SymbolTable/Attributes/TypeAttributes.h"
#include "../../SymbolTable/Attributes/VariableAttributes.h"
#include "../../SymbolTable/Attributes/FunctionAttributes.h"
#include <stdexcept>

TopDeclVisitor::TopDeclVisitor(SymbolTable* symtab, ostream& os) : symtab_(symtab), os_(os), originalSymtab_(symtab) {
	// TODO Auto-generated constructor stub

}

TopDeclVisitor::~TopDeclVisitor() {
	// TODO Auto-generated destructor stub
}

void TopDeclVisitor::visit(TypeDeclaringNode& td) {
	TypeVisitor typeVisitor(&currentSymbolTable(), os_);
	td.typeSpec()->accept(typeVisitor);

	TypeDeclaringNode::Iterator* i = td.createIterator();
	for (i->First(); i->IsDone(); i->Next()) {
		Identifier& id = *i->CurrentItem();
		if (currentSymbolTable().declaredLocally( id.name() )) {
			id.setAttributes(0);
		} else {
			TypeAttributes* attr = new TypeAttributes; // FIXME alias TypeAttributes. should not release TypeDescriptor
			attr->setType(td.typeSpec()->getType());
			currentSymbolTable().enterSymbol( id.name() , attr);
			id.setAttributes(attr);
		}
	}
	delete i;
}

void TopDeclVisitor::visit(TypedefNode& td) {
	TypeVisitor typeVisitor(&currentSymbolTable(), os_);
	td.getTypeName()->accept(typeVisitor);

	TypedefNode::Iterator* i = td.createIterator();
	foreach_element (i) {
		Identifier& id =  *i->CurrentItem();
		if (currentSymbolTable().declaredLocally( id.name() )) {
			id.setAttributes(0);
		} else {
			TypeAttributes* attr = new TypeAttributes; // FIXME alias TypeAttributes. should not release TypeDescriptor
			attr->setType( td.getTypeName()->getType() );
			currentSymbolTable().enterSymbol(id.name(), attr);
			id.setAttributes(attr);
		}
	}
	delete i;
}

void TopDeclVisitor::visit(VariableListDeclaringNode& vld) {
	TypeVisitor typeVisitor(&currentSymbolTable(), os_);
	vld.getTypeName()->accept(typeVisitor);

	// TODO deal with IdentifierWithDim
	// TODO deal with IdentifierWithInitExpr
	VariableListDeclaringNode::Iterator* i = vld.createIterator();
	foreach_element (i) {
		Identifier& id =  *i->CurrentItem();
		if (currentSymbolTable().declaredLocally( id.name() )) {
			id.setAttributes(0);
		} else {
			VariableAttributes* attr = new VariableAttributes;
			attr->setType( vld.getTypeName()->getType() );
			currentSymbolTable().enterSymbol(id.name(), attr);
			id.setAttributes(attr);
		}
	}
	delete i;
}

void TopDeclVisitor::visit(FunctionDeclaringNode& fd) {
	TypeVisitor typeVisitor(&currentSymbolTable(), os_);
	fd.getReturnType()->accept(typeVisitor);

	FunctionAttributes* attr = new FunctionAttributes;
	attr->setReturnType(fd.getReturnType()->getType());
	currentSymbolTable().enterSymbol(fd.getFunctionName()->name(), attr);
	fd.getFunctionName()->setAttributes(attr); // why do this? (textbook)

	setCurrentSymbolTableTo(attr->getLocals());
	fd.getParamList()->accept(*this);
	// TODO process signature
	fd.getBlock()->accept(*this);
	setCurrentSymbolTableBack();
}

void TopDeclVisitor::setCurrentSymbolTableTo(SymbolTable *newSymtab) {
	symtab_ = newSymtab;
}



void TopDeclVisitor::setCurrentSymbolTableBack() {
	symtab_ = originalSymtab_;
}




