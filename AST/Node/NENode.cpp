/*
 * NENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "NENode.h"
#include "../Visitor/NodeVisitor.h"

NENode::NENode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

NENode::~NENode() {
	// TODO Auto-generated destructor stub
}

void NENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
