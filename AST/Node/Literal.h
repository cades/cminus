/*
 * Literal.h
 *
 *  Created on: 2012/6/18
 *      Author: mac
 */

#ifndef LITERAL_H_
#define LITERAL_H_

#include "Expression.h"

class Literal: public Expression {
public:
	Literal();
	virtual ~Literal();
	virtual Literal* evaluate() = 0;
};

#endif /* LITERAL_H_ */
