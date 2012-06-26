/*
 * RelationalExpression.cpp
 *
 *  Created on: 2012/6/26
 *      Author: mac
 */

#include "RelationalExpression.h"
#include "../Visitor/NodeVisitor.h"
#include "../SymbolTable/TypeDescriptor/IntegerTypeDescriptor.h"

RelationalExpression::RelationalExpression(Expression* lhs, Expression* rhs) {}

RelationalExpression::~RelationalExpression() {}

TypeDescriptor *RelationalExpression::relationalResultType() {
	return new IntegerTypeDescriptor;
}

void RelationalExpression::accept(NodeVisitor& visitor) { visitor.visit(*this); }
