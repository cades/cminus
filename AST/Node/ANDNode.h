/*
 * ANDNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ANDNODE_H_
#define ANDNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class ANDNode: public AbstractNode {
public:
	ANDNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~ANDNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* ANDNODE_H_ */
