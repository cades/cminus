/*
 * StructReferencingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "StructReferencingNode.h"
#include "../Visitor/NodeVisitor.h"

StructReferencingNode::StructReferencingNode(AbstractNode* varRef, Identifier* field)
: varRef_(varRef), field_(field) {
	// TODO Auto-generated constructor stub

}

StructReferencingNode::~StructReferencingNode() {
	// TODO Auto-generated destructor stub
}

void StructReferencingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
