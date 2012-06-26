/*
 * LENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef LENODE_H_
#define LENODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class LENode: public RelationalExpression {
public:
	LENode(Expression* lhs, Expression* rhs);
	virtual ~LENode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* LENODE_H_ */
