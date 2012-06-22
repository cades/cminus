/*
 * ForLoopingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ForLoopingNode.h"
#include "../Visitor/NodeVisitor.h"

ForLoopingNode::ForLoopingNode(NodeList* initializer, NodeList* condition, NodeList* increment,  AbstractNode* loopBody)
: initializer_(initializer), condition_(condition), increment_(increment), loopBody_(loopBody) {
	// TODO Auto-generated constructor stub

}

ForLoopingNode::~ForLoopingNode() {
	// TODO Auto-generated destructor stub
}

void ForLoopingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
