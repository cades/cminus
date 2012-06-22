/*
 * EmptyNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "EmptyNode.h"
#include "../Visitor/NodeVisitor.h"

EmptyNode::EmptyNode() {
	// TODO Auto-generated constructor stub

}

EmptyNode::~EmptyNode() {
	// TODO Auto-generated destructor stub
}

void EmptyNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
