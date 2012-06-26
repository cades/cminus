/*
 * MultiplyNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef MULTIPLYNODE_H_
#define MULTIPLYNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class MultiplyNode: public BinaryExpression {
public:
	MultiplyNode(Expression* lhs, Expression* rhs);
	virtual ~MultiplyNode();

protected:
	virtual float floatOp(float, float);
	virtual int intOp(int, int);
};

#endif /* MULTIPLYNODE_H_ */
