/*
 * ORNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ORNODE_H_
#define ORNODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class ORNode: public RelationalExpression {
public:
	ORNode(Expression* lhs, Expression* rhs);
	virtual ~ORNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* ORNODE_H_ */
