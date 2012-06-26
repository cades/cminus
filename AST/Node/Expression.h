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
class TypeDescriptor;

class Expression: public AbstractNode {
public:
	Expression();
	virtual ~Expression();
	virtual Literal* evaluate() = 0;
	void setType(TypeDescriptor* td) { type_ = td; }
	TypeDescriptor* getType() { return type_; }

protected:
	TypeDescriptor* type_;
};

#endif /* EXPRESSION_H_ */
