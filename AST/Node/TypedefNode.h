/*
 * TypedefNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPEDEFNODE_H_
#define TYPEDEFNODE_H_

#include "AbstractNode.h"
class Identifier;
#include "IdentifierList.h"
class NodeVisitor;

class TypedefNode: public AbstractNode {
public:
	TypedefNode(Identifier* typeName, IdentifierList* idList);
	virtual ~TypedefNode();
	virtual void accept(NodeVisitor& visitor);
	virtual IdentifierList::Iterator* createIterator() { return idList_->createIterator(); }
private:
	Identifier* typeName_;
	IdentifierList* idList_;
};

#endif /* TYPEDEFNODE_H_ */
