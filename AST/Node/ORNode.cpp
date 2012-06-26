/*
 * ORNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ORNode.h"
#include "../Visitor/NodeVisitor.h"

ORNode::ORNode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

ORNode::~ORNode() {
	// TODO Auto-generated destructor stub
}

void ORNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
