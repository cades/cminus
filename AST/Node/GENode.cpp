/*
 * GENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "GENode.h"
#include "../Visitor/NodeVisitor.h"

GENode::GENode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

GENode::~GENode() {
	// TODO Auto-generated destructor stub
}

void GENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
