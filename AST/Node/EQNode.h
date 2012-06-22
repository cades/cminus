/*
 * EQNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef EQNODE_H_
#define EQNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class EQNode: public AbstractNode {
public:
	EQNode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~EQNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* EQNODE_H_ */
