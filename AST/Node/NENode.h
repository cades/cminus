/*
 * NENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef NENODE_H_
#define NENODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class NENode: public AbstractNode {
public:
	NENode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~NENode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* NENODE_H_ */
