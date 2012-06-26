/*
 * GTNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "GTNode.h"
#include "../Visitor/NodeVisitor.h"

GTNode::GTNode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

GTNode::~GTNode() {
	// TODO Auto-generated destructor stub
}

void GTNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
