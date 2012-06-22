/*
 * DivideNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "DivideNode.h"
#include "../Visitor/NodeVisitor.h"
#include <functional>

DivideNode::DivideNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

DivideNode::~DivideNode() {
	// TODO Auto-generated destructor stub
}

void DivideNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal *DivideNode::evaluate() {
	return binary_evaluate(lhs_, rhs_, std::divides<float>(), std::divides<int>());
}


