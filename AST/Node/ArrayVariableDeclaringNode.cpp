/*
 * ArrayVariableDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ArrayVariableDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

ArrayVariableDeclaringNode::ArrayVariableDeclaringNode(Identifier* typeName, Identifier* id, ArrayDefiningNode* dim)
: typeName_(typeName), id_(id), dim_(dim) {
	// TODO Auto-generated constructor stub

}

ArrayVariableDeclaringNode::~ArrayVariableDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void ArrayVariableDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

ArrayDefiningNode *ArrayVariableDeclaringNode::getDim() const
{
    return dim_;
}

Identifier *ArrayVariableDeclaringNode::getId() const
{
    return id_;
}

Identifier *ArrayVariableDeclaringNode::getTypeName() const
{
    return typeName_;
}


