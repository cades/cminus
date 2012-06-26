/*
 * UnaryExpression.h
 *
 *  Created on: 2012/6/26
 *      Author: mac
 */

#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

#include "Expression.h"

class UnaryExpression: public Expression {
public:
	UnaryExpression(Expression*);
	virtual ~UnaryExpression();
	Expression* subExpr() { return subExpr_; }
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() = 0;
protected:
	Expression* subExpr_;
};

#endif /* UNARYEXPRESSION_H_ */
