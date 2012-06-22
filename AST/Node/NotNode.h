/*
 * NotNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NOTNODE_H_
#define NOTNODE_H_

#include "Expression.h"
class NodeVisitor;

class NotNode: public Expression {
public:
	NotNode(AbstractNode*);
	virtual ~NotNode();
	AbstractNode* subExpr() { return subExpr_; }
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();
private:
	AbstractNode* subExpr_;
};

#endif /* NOTNODE_H_ */
