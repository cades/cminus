/*
 * TypeSpecifierByStruct.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypeSpecifierByStruct.h"
#include "../Visitor/NodeVisitor.h"

TypeSpecifierByStruct::TypeSpecifierByStruct(StructDefiningNode* structure) : structure_(structure) {
	// TODO Auto-generated constructor stub

}

TypeSpecifierByStruct::~TypeSpecifierByStruct() {
	// TODO Auto-generated destructor stub
}

void TypeSpecifierByStruct::accept(NodeVisitor& visitor) { visitor.visit(*this); }
