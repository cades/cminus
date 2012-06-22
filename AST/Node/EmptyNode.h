/*
 * EmptyNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef EMPTYNODE_H_
#define EMPTYNODE_H_

#include "AbstractNode.h"
class NodeVisitor;

class EmptyNode: public AbstractNode {
public:
	EmptyNode();
	virtual ~EmptyNode();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* EMPTYNODE_H_ */
