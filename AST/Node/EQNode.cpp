/*
 * EQNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "EQNode.h"
#include "../Visitor/NodeVisitor.h"

EQNode::EQNode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

EQNode::~EQNode() {
	// TODO Auto-generated destructor stub
}

void EQNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
