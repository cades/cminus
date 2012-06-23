/*
 * StructDefiningNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "StructDefiningNode.h"
#include "../Visitor/NodeVisitor.h"

StructDefiningNode::StructDefiningNode(VariableDeclaringList* fieldDeclList) : fieldDeclList_(fieldDeclList) {
	// TODO Auto-generated constructor stub

}

StructDefiningNode::~StructDefiningNode() {
	// TODO Auto-generated destructor stub
}

void StructDefiningNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
