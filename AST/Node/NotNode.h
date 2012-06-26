/*
 * NotNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NOTNODE_H_
#define NOTNODE_H_

#include "UnaryExpression.h"
class NodeVisitor;

class NotNode: public UnaryExpression {
public:
	NotNode(Expression*);
	virtual ~NotNode();
	virtual Literal* evaluate();
};

#endif /* NOTNODE_H_ */
