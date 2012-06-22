/*
 * CallingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "CallingNode.h"
#include "../Visitor/NodeVisitor.h"

CallingNode::CallingNode(Identifier* functionName, NodeList* argList)
: functionName_(functionName), argList_(argList) {
	// TODO Auto-generated constructor stub

}

CallingNode::~CallingNode() {
	// TODO Auto-generated destructor stub
}

void CallingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
