/*
 * MinusNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "MinusNode.h"
#include <functional>

MinusNode::MinusNode(Expression* lhs, Expression* rhs) : BinaryExpression(lhs, rhs) {
	// TODO Auto-generated constructor stub

}

MinusNode::~MinusNode() {
	// TODO Auto-generated destructor stub
}

float MinusNode::floatOp(float float1, float float2) {
	return std::minus<float>()(float1, float2);
}

int MinusNode::intOp(int int1, int int2) {
	return std::minus<int>()(int1, int2);
}


