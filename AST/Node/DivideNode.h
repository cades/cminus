/*
 * DivideNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef DIVIDENODE_H_
#define DIVIDENODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class DivideNode: public BinaryExpression {
public:
	DivideNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~DivideNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* DIVIDENODE_H_ */
