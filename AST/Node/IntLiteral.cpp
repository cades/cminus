/*
 * IntLiteral.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "IntLiteral.h"
#include "../Visitor/NodeVisitor.h"

IntLiteral::IntLiteral(int value) : value_(value) {
	// TODO Auto-generated constructor stub

}

IntLiteral::~IntLiteral() {
	// TODO Auto-generated destructor stub
}

void IntLiteral::accept(NodeVisitor& visitor) { visitor.visit(*this); }

int IntLiteral::getValue() const
{
    return value_;
}


