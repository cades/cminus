/*
 * ORNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ORNODE_H_
#define ORNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class ORNode: public AbstractNode {
public:
	ORNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~ORNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* ORNODE_H_ */
