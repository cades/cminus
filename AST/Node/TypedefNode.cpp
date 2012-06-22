/*
 * TypedefNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypedefNode.h"
#include "../Visitor/NodeVisitor.h"

TypedefNode::TypedefNode(Identifier* typeName, IdentifierList* idList) : typeName_(typeName), idList_(idList) {
	// TODO Auto-generated constructor stub

}

TypedefNode::~TypedefNode() {
	// TODO Auto-generated destructor stub
}

void TypedefNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
