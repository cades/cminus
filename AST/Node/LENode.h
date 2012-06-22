/*
 * LENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef LENODE_H_
#define LENODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class LENode: public AbstractNode {
public:
	LENode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~LENode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* LENODE_H_ */
