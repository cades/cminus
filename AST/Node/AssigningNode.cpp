/*
 * AssigningNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "AssigningNode.h"
#include "../Visitor/NodeVisitor.h"

AssigningNode::AssigningNode(Expression* targetName, Expression* valueExpr)
: targetName_(targetName), valueExpr_(valueExpr) {
	// TODO Auto-generated constructor stub

}

AssigningNode::~AssigningNode() {
	// TODO Auto-generated destructor stub
}

void AssigningNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Expression *AssigningNode::getTargetName() const
{
    return targetName_;
}

Expression *AssigningNode::getValueExpr() const
{
    return valueExpr_;
}


