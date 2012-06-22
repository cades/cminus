/*
 * EmptyExpression.h
 *
 *  Created on: 2012/6/19
 *      Author: mac
 */

#ifndef EMPTYEXPRESSION_H_
#define EMPTYEXPRESSION_H_
class NodeVisitor;
class Literal;
#include <stdexcept>

#include "Expression.h"

class EmptyExpression: public Expression {
public:
	EmptyExpression();
	virtual ~EmptyExpression();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() { throw std::runtime_error("EmptyExpression DONOT support evaluate()."); }
};

#endif /* EMPTYEXPRESSION_H_ */
