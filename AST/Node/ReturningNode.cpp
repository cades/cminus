/*
 * ReturningNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ReturningNode.h"
#include "../Visitor/NodeVisitor.h"

ReturningNode::ReturningNode(Expression* subExpr) : subExpr_(subExpr) {
	// TODO Auto-generated constructor stub

}

ReturningNode::~ReturningNode() {
	// TODO Auto-generated destructor stub
}

void ReturningNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
