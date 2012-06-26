/*
 * GENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef GENODE_H_
#define GENODE_H_

#include "RelationalExpression.h"
class NodeVisitor;

class GENode: public RelationalExpression {
public:
	GENode(Expression* lhs, Expression* rhs);
	virtual ~GENode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* GENODE_H_ */
