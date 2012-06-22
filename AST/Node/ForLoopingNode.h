/*
 * ForLoopingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef FORLOOPINGNODE_H_
#define FORLOOPINGNODE_H_

#include "AbstractNode.h"
class NodeList;
class NodeVisitor;

class ForLoopingNode: public AbstractNode {
public:
	ForLoopingNode(NodeList* initializer, NodeList* condition, NodeList* increment,  AbstractNode* loopBody);
	virtual ~ForLoopingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	NodeList* initializer_;
	NodeList* condition_;
	NodeList* increment_;
	AbstractNode* loopBody_;
};

#endif /* FORLOOPINGNODE_H_ */
