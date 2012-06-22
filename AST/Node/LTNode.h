/*
 * LTNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef LTNODE_H_
#define LTNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class LTNode: public AbstractNode {
public:
	LTNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~LTNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* LTNODE_H_ */
