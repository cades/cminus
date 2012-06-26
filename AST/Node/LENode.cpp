/*
 * LENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "LENode.h"
#include "../Visitor/NodeVisitor.h"

LENode::LENode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

LENode::~LENode() {
	// TODO Auto-generated destructor stub
}

void LENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
