/*
 * IdentifierWithDim.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "IdentifierWithDim.h"
#include "../Visitor/NodeVisitor.h"

IdentifierWithDim::IdentifierWithDim(Identifier* name, ArrayDefiningNode* dim) : Identifier(*name), dim_(dim) {
	// TODO Auto-generated constructor stub

}

IdentifierWithDim::~IdentifierWithDim() {
	// TODO Auto-generated destructor stub
}

void IdentifierWithDim::accept(NodeVisitor& visitor) { visitor.visit(*this); }

ArrayDefiningNode *IdentifierWithDim::getDim() const
{
    return dim_;
}


