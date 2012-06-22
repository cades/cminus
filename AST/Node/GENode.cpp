/*
 * GENode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "GENode.h"
#include "../Visitor/NodeVisitor.h"

GENode::GENode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

GENode::~GENode() {
	// TODO Auto-generated destructor stub
}

void GENode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
