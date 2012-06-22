/*
 * PlusNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef PLUSNODE_H_
#define PLUSNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class PlusNode: public BinaryExpression {
public:
	PlusNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~PlusNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* PLUSNODE_H_ */
