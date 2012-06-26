/*
 * Identifier.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "Identifier.h"
#include "../Visitor/NodeVisitor.h"
#include "../SymbolTable/Attributes/Attributes.h"
#include <stdexcept>

Identifier::Identifier(const string& s) : name_(s) {
	// TODO Auto-generated constructor stub

}

Identifier::~Identifier() {
	// TODO Auto-generated destructor stub
}

void Identifier::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal *Identifier::evaluate() {
	throw std::runtime_error("Cannot apply evaluate() on Identifier."); //TODO may return init value in symtab?
}

void Identifier::setAttributes(Attributes* attr) {
	attributesRef_ = attr;
	if (attr == 0) type_ = 0;
	else type_ = attr->getType();
}



