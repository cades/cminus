/*
 * GENode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef GENODE_H_
#define GENODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class GENode: public AbstractNode {
public:
	GENode(AbstractNode* lhs, AbstractNode* rhs);
	virtual ~GENode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* lhs_;
	AbstractNode* rhs_;
};

#endif /* GENODE_H_ */
