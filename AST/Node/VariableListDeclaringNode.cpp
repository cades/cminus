/*
 * VariableListDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "VariableListDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

VariableListDeclaringNode::VariableListDeclaringNode(Identifier* typeName, IdentifierList* idList)
: typeName_(typeName), idList_(idList) {
	// TODO Auto-generated constructor stub

}

VariableListDeclaringNode::VariableListDeclaringNode(Identifier *typeName, Identifier *id)
: typeName_(typeName) {
	idList_ = new IdentifierList;
	idList_->append(id);
}

VariableListDeclaringNode::~VariableListDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void VariableListDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Identifier *VariableListDeclaringNode::getTypeName() const
{
    return typeName_;
}


