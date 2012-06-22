/*
 * StructDefiningNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef STRUCTDEFININGNODE_H_
#define STRUCTDEFININGNODE_H_

#include "AbstractNode.h"
class NodeList;
class NodeVisitor;
#include "NodeList.h"

class StructDefiningNode: public AbstractNode {
public:
	StructDefiningNode(NodeList* fieldDeclList);
	virtual ~StructDefiningNode();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	typedef NodeList::Iterator Iterator;
	virtual Iterator* createIterator() { return fieldDeclList_->createIterator(); }

private:
	NodeList* fieldDeclList_;
};

#endif /* STRUCTDEFININGNODE_H_ */
