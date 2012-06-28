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
#include "../../Node/ArrayVariableDeclaringNode.h"
#include "../../Node/ArrayDefiningNode.h"
#include "../../Node/FunctionDeclaringNode.h"
#include "../../Node/IdentifierWithDim.h"
#include "../../SymbolTable/SymbolTable.h"
#include "../../SymbolTable/Attributes/TypeAttributes.h"
#include "../../SymbolTable/Attributes/VariableAttributes.h"
#include "../../SymbolTable/Attributes/FunctionAttributes.h"
#include "SemanticsVisitor.h"
#include <stdexcept>
#include <ostream>
#include <typeinfo>

TopDeclVisitor::TopDeclVisitor(SymbolTable* symtab, ostream& os) : SemanticsVisitor(symtab, os), originalSymtab_(symtab) {
	// TODO Auto-generated constructor stub

}

TopDeclVisitor::~TopDeclVisitor() {
	// TODO Auto-generated destructor stub
}

void TopDeclVisitor::visit(TypeDeclaringNode& td) {
	TypeVisitor typeVisitor(&currentSymbolTable(), errorLog());
	td.typeSpec()->accept(typeVisitor);

	TypeDeclaringNode::Iterator* i = td.createIterator();
	for (i->First(); i->IsDone(); i->Next()) {
		Identifier& id = *i->CurrentItem();
		if (currentSymbolTable().declaredLocally( id.name() )) {
			id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
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
	TypeVisitor typeVisitor(&currentSymbolTable(), errorLog());
	td.getTypeName()->accept(typeVisitor);

	TypedefNode::Iterator* i = td.createIterator();
	foreach_element (i) {
		Identifier& id =  *i->CurrentItem();
		if (currentSymbolTable().declaredLocally( id.name() )) {
			id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
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
	TypeVisitor typeVisitor(&currentSymbolTable(), errorLog());
	vld.getTypeName()->accept(typeVisitor);

	// TODO deal with IdentifierWithInitExpr
	VariableListDeclaringNode::Iterator* i = vld.createIterator();
	foreach_element (i) {
		if (dynamic_cast<IdentifierWithDim*>(i->CurrentItem())) {
			IdentifierWithDim& id =  *dynamic_cast<IdentifierWithDim*>(i->CurrentItem());
			if (currentSymbolTable().declaredLocally( id.name() )) {
				errorLog() << "Variable name '" << id.name() << "' cannot be redeclared. \n";
				id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
			} else {
				VariableAttributes* attr = new VariableAttributes;
				id.getDim()->accept(typeVisitor);		 // this is the difference
				attr->setType( id.getDim()->getType() ); // this is the difference
				currentSymbolTable().enterSymbol(id.name(), attr);
				id.setAttributes(attr);
			}
		} else {
			Identifier& id =  *i->CurrentItem();
			if (currentSymbolTable().declaredLocally( id.name() )) {
				errorLog() << "Variable name '" << id.name() << "' cannot be redeclared. \n";
				id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
			} else {
				VariableAttributes* attr = new VariableAttributes;
				attr->setType( vld.getTypeName()->getType() );
				currentSymbolTable().enterSymbol(id.name(), attr);
				id.setAttributes(attr);
			}
		}
	}
	delete i;
}

void TopDeclVisitor::visit(ArrayVariableDeclaringNode& avd) {
	TypeVisitor typeVisitor(&currentSymbolTable(), errorLog());
	avd.getDim()->accept(typeVisitor);
	Identifier& id = *avd.getId();
	if (currentSymbolTable().declaredLocally( id.name() )) {
		errorLog() << "Variable name '" << id.name() << "' cannot be redeclared. \n";
		id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
	} else {
		VariableAttributes* attr = new VariableAttributes;
		attr->setType( avd.getDim()->getType() );
		currentSymbolTable().enterSymbol(id.name(), attr);
		id.setAttributes(attr);
	}
}

void TopDeclVisitor::visit(FunctionDeclaringNode& fd) {
	setCurrentFunction(&fd);

	TypeVisitor typeVisitor(&currentSymbolTable(), errorLog());
	fd.getReturnType()->accept(typeVisitor);

	FunctionAttributes* attr = new FunctionAttributes;
	attr->setReturnType(fd.getReturnType()->getType());
	if ( !currentSymbolTable().enterSymbol(fd.getFunctionName()->name(), attr) ) {
		errorLog() << "Function name '" << fd.getFunctionName()->name() << "' redeclared. \n";
		return; // this name has been used.
	}
	fd.getFunctionName()->setAttributes(attr); // why do this? (textbook)

	setCurrentSymbolTableTo(attr->getLocals());
	fd.getParamList()->accept(*this);
	attr->setSignature(generateSignature(fd.getParamList()));
	fd.getBlock()->accept(*this);
	setCurrentSymbolTableBack();

	setCurrentFunction(0);
}

void TopDeclVisitor::setCurrentSymbolTableTo(SymbolTable *newSymtab) {
	setSymbolTableTo(newSymtab);
}



void TopDeclVisitor::setCurrentSymbolTableBack() {
	setSymbolTableTo(originalSymtab_);
}

SemanticsVisitor::TypeDescriptorList TopDeclVisitor::generateSignature(NodeList* nl) {
	SemanticsVisitor::TypeDescriptorList sig;
	NodeList::Iterator* i = nl->createIterator();
	foreach_element(i) {
		if (VariableListDeclaringNode* vld = dynamic_cast<VariableListDeclaringNode*>(i->CurrentItem())) {
			sig.push_back(vld->getTypeName()->getType());
		} else if (ArrayVariableDeclaringNode* avd = dynamic_cast<ArrayVariableDeclaringNode*>(i->CurrentItem())) {
			sig.push_back(avd->getTypeName()->getType());
		} else {
			throw std::runtime_error(string("TopDeclVisitor::generateSignature  encounter strange node: ") + typeid(i->CurrentItem()).name() );
		}
	}
	delete i;
	return sig;
}


