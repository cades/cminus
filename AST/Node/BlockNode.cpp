/*
 * BlockNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "BlockNode.h"
#include "../Visitor/NodeVisitor.h"

BlockNode::BlockNode(NodeList* list) : delc_stmt_list_(list) {
	// TODO Auto-generated constructor stub

}

BlockNode::~BlockNode() {
	// TODO Auto-generated destructor stub
}

void BlockNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
