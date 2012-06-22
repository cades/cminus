/*
 * AbstractNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef ABSTRACTNODE_H_
#define ABSTRACTNODE_H_

class NodeVisitor;
#include "Iterator/IIterator.h"

class AbstractNode {
public:
	AbstractNode();
	virtual ~AbstractNode();
	virtual void accept(NodeVisitor&) = 0;

	// Composite method API #1 : size+getter. Default behavior throws exception.
	virtual int childrenNumber();
	virtual AbstractNode* getChild(int index);

	// Composite method API #2 : iterator. Default behavior throws exception.
	virtual IIterator* createIterator();
};

#endif /* ABSTRACTNODE_H_ */
