/*
 * ArrayVariableDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ArrayVariableDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

ArrayVariableDeclaringNode::ArrayVariableDeclaringNode(Identifier* typeName, Identifier* id, AbstractNode* dim)
: typeName_(typeName), id_(id), dim_(dim) {
	// TODO Auto-generated constructor stub

}

ArrayVariableDeclaringNode::~ArrayVariableDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void ArrayVariableDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
