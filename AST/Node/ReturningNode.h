/*
 * ReturningNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef RETURNINGNODE_H_
#define RETURNINGNODE_H_

#include "AbstractNode.h"
#include "Expression.h"
class NodeVisitor;

class ReturningNode: public AbstractNode {
public:
	ReturningNode(Expression* subExpr);
	virtual ~ReturningNode();
	virtual void accept(NodeVisitor& visitor);
    Expression *getReturnVal() const { return returnVal_; }

private:
	Expression* returnVal_;
};

#endif /* RETURNINGNODE_H_ */
