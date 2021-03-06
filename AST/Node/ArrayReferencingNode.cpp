/*
 * ArrayReferencingNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ArrayReferencingNode.h"
#include "../Visitor/NodeVisitor.h"

ArrayReferencingNode::ArrayReferencingNode(Expression* varRef, Expression* dimExpr)
: varRef_(varRef), dimExpr_(dimExpr) {}

ArrayReferencingNode::~ArrayReferencingNode() {}

void ArrayReferencingNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
