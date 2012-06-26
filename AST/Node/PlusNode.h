/*
 * PlusNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef PLUSNODE_H_
#define PLUSNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class PlusNode: public BinaryExpression {
public:
	PlusNode(Expression* lhs, Expression* rhs);
	virtual ~PlusNode();

protected:
	virtual float floatOp(float, float);
	virtual int intOp(int, int);
};

#endif /* PLUSNODE_H_ */
