/*
 * GTNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef GTNODE_H_
#define GTNODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class GTNode: public RelationalExpression {
public:
	GTNode(Expression* lhs, Expression* rhs);
	virtual ~GTNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* GTNODE_H_ */
