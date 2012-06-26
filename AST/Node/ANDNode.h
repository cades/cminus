/*
 * ANDNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ANDNODE_H_
#define ANDNODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class ANDNode: public RelationalExpression {
public:
	ANDNode(Expression* lhs, Expression* rhs);
	virtual ~ANDNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* ANDNODE_H_ */
