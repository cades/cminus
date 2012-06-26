/*
 * ANDNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ANDNode.h"
#include "../Visitor/NodeVisitor.h"

ANDNode::ANDNode(Expression* lhs, Expression* rhs) : RelationalExpression(lhs, rhs) {}

ANDNode::~ANDNode() {}

void ANDNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
