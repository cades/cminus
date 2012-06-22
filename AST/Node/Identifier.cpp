/*
 * Identifier.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "Identifier.h"
#include "../Visitor/NodeVisitor.h"

Identifier::Identifier(const string& s) : name_(s) {
	// TODO Auto-generated constructor stub

}

Identifier::~Identifier() {
	// TODO Auto-generated destructor stub
}

void Identifier::accept(NodeVisitor& visitor) { visitor.visit(*this); }

void Identifier::setType(TypeAttributes *typeAttr) {
	type_ = typeAttr;
}


