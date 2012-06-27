/*
 * ForLoopingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef FORLOOPINGNODE_H_
#define FORLOOPINGNODE_H_

#include "AbstractNode.h"
class ExpressionList;
class NodeVisitor;

class ForLoopingNode: public AbstractNode {
public:
	ForLoopingNode(ExpressionList* initializer, ExpressionList* condition, ExpressionList* increment,  AbstractNode* loopBody);
	virtual ~ForLoopingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	ExpressionList* initializer_;
	ExpressionList* condition_;
	ExpressionList* increment_;
	AbstractNode* loopBody_;
};

#endif /* FORLOOPINGNODE_H_ */
