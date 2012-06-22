/*
 * TypeSpecifierByName.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypeSpecifierByName.h"
#include "../Visitor/NodeVisitor.h"

TypeSpecifierByName::TypeSpecifierByName(Identifier* typeName) : typeName_(typeName) {
	// TODO Auto-generated constructor stub

}

TypeSpecifierByName::~TypeSpecifierByName() {
	// TODO Auto-generated destructor stub
}

void TypeSpecifierByName::accept(NodeVisitor& visitor) { visitor.visit(*this); }
