/*
 * LENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "LENode.h"
#include "../Visitor/NodeVisitor.h"

LENode::LENode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

LENode::~LENode() {
	// TODO Auto-generated destructor stub
}

void LENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
