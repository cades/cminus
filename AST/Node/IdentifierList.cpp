/*
 * IdentifierList.cpp
 *
 *  Created on: 2012/6/20
 *      Author: mac
 */

#include "IdentifierList.h"
#include "../Visitor/NodeVisitor.h"

IdentifierList::IdentifierList() {
	// TODO Auto-generated constructor stub

}

IdentifierList::~IdentifierList() {
	// TODO Auto-generated destructor stub
}

void IdentifierList::accept(NodeVisitor & visitor) { visitor.visit(*this); }



void IdentifierList::append(Identifier *id)
{
	list_.push_back(id);
}


