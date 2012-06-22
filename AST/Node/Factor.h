/*
 * Factor.h
 *
 *  Created on: 2012/6/19
 *      Author: mac
 */

#ifndef FACTOR_H_
#define FACTOR_H_

#include "Expression.h"
#include <stdexcept>

class Factor: public Expression {
public:
	Factor(AbstractNode*);
	virtual ~Factor();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() { throw std::runtime_error("Factor DONOT support evaluate()."); }
private:
	AbstractNode* subExpr_;
};

#endif /* FACTOR_H_ */
