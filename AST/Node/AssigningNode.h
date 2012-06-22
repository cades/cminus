/*
 * AssigningNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef ASSIGNINGNODE_H_
#define ASSIGNINGNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class AssigningNode: public AbstractNode {
public:
	AssigningNode(AbstractNode*, AbstractNode*);
	virtual ~AssigningNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* targetName_;  // TODO: determine pointer type. Can it be more precise?
	AbstractNode* valueExpr_;   // TODO: determine pointer type. Can it be more precise?
};

#endif /* ASSIGNINGNODE_H_ */
