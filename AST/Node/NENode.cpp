/*
 * NENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "NENode.h"
#include "../Visitor/NodeVisitor.h"

NENode::NENode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

NENode::~NENode() {
	// TODO Auto-generated destructor stub
}

void NENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
