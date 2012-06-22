/*
 * Identifier.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "Identifier.h"
#include "../Visitor/NodeVisitor.h"
#include "../SymbolTable/Attributes/Attributes.h"

Identifier::Identifier(const string& s) : name_(s) {
	// TODO Auto-generated constructor stub

}

Identifier::~Identifier() {
	// TODO Auto-generated destructor stub
}

void Identifier::accept(NodeVisitor& visitor) { visitor.visit(*this); }

void Identifier::setAttributes(Attributes* attr) {
	attributesRef_ = attr;
	if (attr == 0) type_ = 0;
	type_ = attr->getType();
}



