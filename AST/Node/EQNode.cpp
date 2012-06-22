/*
 * EQNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "EQNode.h"
#include "../Visitor/NodeVisitor.h"

EQNode::EQNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

EQNode::~EQNode() {
	// TODO Auto-generated destructor stub
}

void EQNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
