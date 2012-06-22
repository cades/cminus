/*
 * MinusNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "MinusNode.h"
#include "../Visitor/NodeVisitor.h"
#include <functional>

MinusNode::MinusNode(AbstractNode* lhs, AbstractNode* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

MinusNode::~MinusNode() {
	// TODO Auto-generated destructor stub
}

void MinusNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal *MinusNode::evaluate() {
	return binary_evaluate(lhs_, rhs_, std::minus<float>(), std::minus<int>());
}
