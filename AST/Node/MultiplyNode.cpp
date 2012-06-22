/*
 * MultiplyNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "MultiplyNode.h"
#include "../Visitor/NodeVisitor.h"
#include <functional>

MultiplyNode::MultiplyNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

MultiplyNode::~MultiplyNode() {
	// TODO Auto-generated destructor stub
}

void MultiplyNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal *MultiplyNode::evaluate() {
	return binary_evaluate(lhs_, rhs_, std::multiplies<float>(), std::multiplies<int>());
}


