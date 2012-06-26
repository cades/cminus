/*
 * UnaryExpression.cpp
 *
 *  Created on: 2012/6/26
 *      Author: mac
 */

#include "UnaryExpression.h"
#include "../Visitor/NodeVisitor.h"

UnaryExpression::UnaryExpression(Expression* subExpr) : subExpr_(subExpr) {
	// TODO Auto-generated constructor stub

}

UnaryExpression::~UnaryExpression() {
	// TODO Auto-generated destructor stub
}

TypeDescriptor *UnaryExpression::unaryResultType() {
	return subExpr_->getType();
}

void UnaryExpression::accept(NodeVisitor& visitor) { visitor.visit(*this); }

