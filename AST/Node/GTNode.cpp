/*
 * GTNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "GTNode.h"
#include "../Visitor/NodeVisitor.h"

GTNode::GTNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

GTNode::~GTNode() {
	// TODO Auto-generated destructor stub
}

void GTNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
