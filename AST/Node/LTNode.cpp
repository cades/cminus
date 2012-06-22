/*
 * LTNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "LTNode.h"
#include "../Visitor/NodeVisitor.h"

LTNode::LTNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

LTNode::~LTNode() {
	// TODO Auto-generated destructor stub
}

void LTNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
