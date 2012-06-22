/*
 * VariableListDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "VariableListDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

VariableListDeclaringNode::VariableListDeclaringNode(Identifier* typeName, IdentifierList* idList)
: typeName_(typeName), idList_(idList) {
	// TODO Auto-generated constructor stub

}

VariableListDeclaringNode::~VariableListDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void VariableListDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
