/*
 * LTNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "LTNode.h"
#include "../Visitor/NodeVisitor.h"

LTNode::LTNode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

LTNode::~LTNode() {
	// TODO Auto-generated destructor stub
}

void LTNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
