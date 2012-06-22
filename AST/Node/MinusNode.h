/*
 * MinusNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef MINUSNODE_H_
#define MINUSNODE_H_

#include "BinaryExpression.h"
class NodeVisitor;

class MinusNode: public BinaryExpression {
public:
	MinusNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~MinusNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* MINUSNODE_H_ */
