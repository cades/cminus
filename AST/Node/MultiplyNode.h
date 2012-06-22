/*
 * MultiplyNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef MULTIPLYNODE_H_
#define MULTIPLYNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class MultiplyNode: public BinaryExpression {
public:
	MultiplyNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~MultiplyNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* MULTIPLYNODE_H_ */
