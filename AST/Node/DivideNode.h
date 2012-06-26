/*
 * DivideNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef DIVIDENODE_H_
#define DIVIDENODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class DivideNode: public BinaryExpression {
public:
	DivideNode(Expression* lhs, Expression* rhs);
	virtual ~DivideNode();

protected:
	virtual float floatOp(float, float);
	virtual int intOp(int, int);
};

#endif /* DIVIDENODE_H_ */
