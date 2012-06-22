/*
 * WhileLoopingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "WhileLoopingNode.h"
#include "../Visitor/NodeVisitor.h"

WhileLoopingNode::WhileLoopingNode(NodeList* condition,  AbstractNode* loopBody)
: condition_(condition), loopBody_(loopBody) {
	// TODO Auto-generated constructor stub

}

WhileLoopingNode::~WhileLoopingNode() {
	// TODO Auto-generated destructor stub
}

void WhileLoopingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
