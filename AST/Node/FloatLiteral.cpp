/*
 * FloatLiteral.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "FloatLiteral.h"
#include "../Visitor/NodeVisitor.h"

FloatLiteral::FloatLiteral(float value) : value_(value) {
	// TODO Auto-generated constructor stub

}

FloatLiteral::~FloatLiteral() {
	// TODO Auto-generated destructor stub
}

void FloatLiteral::accept(NodeVisitor& visitor) { visitor.visit(*this); }

float FloatLiteral::getValue() const
{
    return value_;
}


