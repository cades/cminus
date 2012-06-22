/*
 * NegNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NEGNODE_H_
#define NEGNODE_H_

#include "Expression.h"
class NodeVisitor;

class NegNode: public Expression {
public:
	NegNode(AbstractNode*);
	virtual ~NegNode();
	AbstractNode* subExpr() { return subExpr_; }
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* subExpr_;
};

#endif /* NEGNODE_H_ */
