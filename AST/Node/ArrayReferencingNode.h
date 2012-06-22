/*
 * ArrayReferencingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ARRAYREFERENCINGNODE_H_
#define ARRAYREFERENCINGNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class ArrayReferencingNode: public AbstractNode {
public:
	ArrayReferencingNode(AbstractNode* varRef, AbstractNode* dimExpr);
	virtual ~ArrayReferencingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* varRef_;
	AbstractNode* dimExpr_;
};

#endif /* ARRAYREFERENCINGNODE_H_ */
