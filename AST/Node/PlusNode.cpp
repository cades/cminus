/*
 * PlusNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "PlusNode.h"
#include "../Visitor/NodeVisitor.h"
#include <functional>

PlusNode::PlusNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

PlusNode::~PlusNode() {
	// TODO Auto-generated destructor stub
}

void PlusNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal *PlusNode::evaluate() {
	return binary_evaluate(lhs_, rhs_, std::plus<float>(), std::plus<int>());
}


