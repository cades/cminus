/*
 * DivideNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "DivideNode.h"
#include <functional>

DivideNode::DivideNode(Expression* lhs, Expression* rhs) : BinaryExpression(lhs, rhs) {
	// TODO Auto-generated constructor stub

}

DivideNode::~DivideNode() {
	// TODO Auto-generated destructor stub
}

float DivideNode::floatOp(float float1, float float2) {
	return std::divides<float>()(float1, float2);
}

int DivideNode::intOp(int int1, int int2) {
	return std::divides<int>()(int1, int2);
}




