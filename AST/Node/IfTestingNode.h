/*
 * IfTestingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef IFTESTINGNODE_H_
#define IFTESTINGNODE_H_

#include "AbstractNode.h"
#include "ExpressionList.h"
class NodeVisitor;

class IfTestingNode: public AbstractNode {
public:
	IfTestingNode(ExpressionList* condition, AbstractNode* thenPart, AbstractNode* elsePart);
	virtual ~IfTestingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	ExpressionList* condition_;
	AbstractNode* thenPart_;
	AbstractNode* elsePart_;
};

#endif /* IFTESTINGNODE_H_ */
