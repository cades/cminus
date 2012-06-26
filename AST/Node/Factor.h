/*
 * Factor.h
 *
 *  Created on: 2012/6/19
 *      Author: mac
 */

#ifndef FACTOR_H_
#define FACTOR_H_

#include "UnaryExpression.h"
#include <stdexcept>

class Factor: public UnaryExpression {
public:
	Factor(Expression*);
	virtual ~Factor();
	virtual Literal* evaluate() { throw std::runtime_error("Factor DONOT support evaluate()."); }
};

#endif /* FACTOR_H_ */
