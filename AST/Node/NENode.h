/*
 * NENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NENODE_H_
#define NENODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class NENode: public RelationalExpression {
public:
	NENode(Expression* lhs, Expression* rhs);
	virtual ~NENode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* NENODE_H_ */
