/*
 * LTNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef LTNODE_H_
#define LTNODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class LTNode: public RelationalExpression {
public:
	LTNode(Expression* lhs, Expression* rhs);
	virtual ~LTNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* LTNODE_H_ */
