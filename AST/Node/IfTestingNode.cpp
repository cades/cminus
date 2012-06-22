/*
 * IfTestingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "IfTestingNode.h"
#include "../Visitor/NodeVisitor.h"

IfTestingNode::IfTestingNode(NodeList* condition, AbstractNode* thenPart, AbstractNode* elsePart)
: condition_(condition), thenPart_(thenPart), elsePart_(elsePart) {
	// TODO Auto-generated constructor stub

}

IfTestingNode::~IfTestingNode() {
	// TODO Auto-generated destructor stub
}

void IfTestingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
