/*
 * Expression.h
 *
 *  Created on: 2012/6/18
 *      Author: mac
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "AbstractNode.h"
class Literal;

class Expression: public AbstractNode {
public:
	Expression();
	virtual ~Expression();
	virtual Literal* evaluate() = 0;
};

#endif /* EXPRESSION_H_ */
