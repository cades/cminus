/*
 * VariableListDeclaringNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef VARIABLELISTDECLARINGNODE_H_
#define VARIABLELISTDECLARINGNODE_H_

#include "AbstractNode.h"
class Identifier;
#include "IdentifierList.h"
class NodeVisitor;

class VariableListDeclaringNode: public AbstractNode {
public:
	VariableListDeclaringNode(Identifier* typeName, IdentifierList* idList);
	virtual ~VariableListDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
	virtual IdentifierList::Iterator* createIterator() { return idList_->createIterator(); }
private:
	Identifier* typeName_;
	IdentifierList* idList_;
};

#endif /* VARIABLELISTDECLARINGNODE_H_ */
