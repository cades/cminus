/*
 * PlusNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "PlusNode.h"
#include <functional>

PlusNode::PlusNode(AbstractNode* lhs, AbstractNode* rhs) : BinaryExpression(lhs, rhs) {
	// TODO Auto-generated constructor stub

}

PlusNode::~PlusNode() {
	// TODO Auto-generated destructor stub
}

// implement hook method
int PlusNode::intOp(int int1, int int2) {
	return std::plus<int>()(int1, int2);
}

float PlusNode::floatOp(float float1, float float2) {
	return std::plus<float>()(float1, float2);
}




