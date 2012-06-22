/*
 * AssigningNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "AssigningNode.h"
#include "../Visitor/NodeVisitor.h"

AssigningNode::AssigningNode(AbstractNode* targetName, AbstractNode* valueExpr)
: targetName_(targetName), valueExpr_(valueExpr) {
	// TODO Auto-generated constructor stub

}

AssigningNode::~AssigningNode() {
	// TODO Auto-generated destructor stub
}

void AssigningNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
