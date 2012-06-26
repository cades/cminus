/*
 * NegNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NEGNODE_H_
#define NEGNODE_H_

#include "UnaryExpression.h"
class NodeVisitor;

class NegNode: public UnaryExpression {
public:
	NegNode(Expression*);
	virtual ~NegNode();
	virtual Literal* evaluate();
};

#endif /* NEGNODE_H_ */
