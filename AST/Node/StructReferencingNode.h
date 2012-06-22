/*
 * StructReferencingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef STRUCTREFERENCINGNODE_H_
#define STRUCTREFERENCINGNODE_H_

#include "AbstractNode.h"
#include "Identifier.h"
class NodeVisitor;

class StructReferencingNode: public AbstractNode {
public:
	StructReferencingNode(AbstractNode* varRef, Identifier* field);
	virtual ~StructReferencingNode();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* varRef_;
	Identifier* field_;
};

#endif /* STRUCTREFERENCINGNODE_H_ */
