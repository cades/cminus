/*
 * EQNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef EQNODE_H_
#define EQNODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class EQNode: public RelationalExpression {
public:
	EQNode(Expression* lhs, Expression* rhs);
	virtual ~EQNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* EQNODE_H_ */
