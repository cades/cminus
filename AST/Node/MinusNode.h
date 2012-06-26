/*
 * MinusNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef MINUSNODE_H_
#define MINUSNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class MinusNode: public BinaryExpression {
public:
	MinusNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~MinusNode();

protected:
	virtual float floatOp(float, float);
	virtual int intOp(int, int);
};

#endif /* MINUSNODE_H_ */
