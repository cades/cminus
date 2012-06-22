/*
 * GTNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef GTNODE_H_
#define GTNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class GTNode: public AbstractNode {
public:
	GTNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~GTNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* GTNODE_H_ */
