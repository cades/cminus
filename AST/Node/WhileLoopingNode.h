/*
 * WhileLoopingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef WHILELOOPINGNODE_H_
#define WHILELOOPINGNODE_H_

#include "AbstractNode.h"
class ExpressionList;
class NodeVisitor;

class WhileLoopingNode: public AbstractNode {
public:
	WhileLoopingNode(ExpressionList* condition,  AbstractNode* loopBody);
	virtual ~WhileLoopingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	ExpressionList* condition_;
	AbstractNode* loopBody_;
};

#endif /* WHILELOOPINGNODE_H_ */
