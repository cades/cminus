/*
 * VariableDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "VariableDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

VariableDeclaringNode::VariableDeclaringNode(Identifier* typeName, Identifier* id) : typeName_(typeName), id_(id) {
	// TODO Auto-generated constructor stub

}

VariableDeclaringNode::~VariableDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void VariableDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
