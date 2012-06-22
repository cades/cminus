/*
 * TypeSpecifier.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypeSpecifier.h"
#include "../Visitor/NodeVisitor.h"

TypeSpecifier::TypeSpecifier() {
	// TODO Auto-generated constructor stub

}

TypeSpecifier::~TypeSpecifier() {
	// TODO Auto-generated destructor stub
}

void TypeSpecifier::accept(NodeVisitor& visitor) { visitor.visit(*this); }
