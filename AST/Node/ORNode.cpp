/*
 * ORNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ORNode.h"
#include "../Visitor/NodeVisitor.h"

ORNode::ORNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

ORNode::~ORNode() {
	// TODO Auto-generated destructor stub
}

void ORNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
