/*
 * FunctionDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "FunctionDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"

FunctionDeclaringNode::FunctionDeclaringNode(Identifier* returnType, Identifier* functionName, NodeList* paramList, AbstractNode* block)
: returnType_(returnType), functionName_(functionName), paramList_(paramList), block_(block) {
	// TODO Auto-generated constructor stub

}

FunctionDeclaringNode::~FunctionDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void FunctionDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }
