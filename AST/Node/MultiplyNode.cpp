/*
 * MultiplyNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "MultiplyNode.h"
#include <functional>

MultiplyNode::MultiplyNode(Expression* lhs, Expression* rhs) : BinaryExpression(lhs, rhs) {
	// TODO Auto-generated constructor stub

}

MultiplyNode::~MultiplyNode() {
	// TODO Auto-generated destructor stub
}

float MultiplyNode::floatOp(float float1, float float2) {
	return std::multiplies<float>()(float1, float2);
}



int MultiplyNode::intOp(int int1, int int2) {
	return std::multiplies<int>()(int1, int2);
}




