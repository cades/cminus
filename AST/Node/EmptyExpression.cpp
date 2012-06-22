/*
 * EmptyExpression.cpp
 *
 *  Created on: 2012/6/19
 *      Author: mac
 */

#include "EmptyExpression.h"
#include "../Visitor/NodeVisitor.h"

EmptyExpression::EmptyExpression() {
	// TODO Auto-generated constructor stub

}

EmptyExpression::~EmptyExpression() {
	// TODO Auto-generated destructor stub
}

void EmptyExpression::accept(NodeVisitor & visitor) { visitor.visit(*this); }


