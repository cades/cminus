/*
 * TypeDeclaringNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPEDECLARINGNODE_H_
#define TYPEDECLARINGNODE_H_

#include "AbstractNode.h"
#include <string>

#include "Identifier.h"
#include "IdentifierList.h"
class NodeList;
class NodeVisitor;
class StructDefiningNode;
#include "Iterator/NullIterator.h"

class TypeDeclaringNode: public AbstractNode {
public:
	TypeDeclaringNode(Identifier* typeName, StructDefiningNode* typeSpec);
	TypeDeclaringNode(IdentifierList* typeNameList, StructDefiningNode* typeSpec);
	virtual ~TypeDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
	StructDefiningNode* typeSpec();

	typedef IdentifierList::Iterator Iterator;
	virtual Iterator* createIterator() { return typeNameList_->createIterator(); }
private:
	IdentifierList* typeNameList_;
	StructDefiningNode* typeSpec_;
};

#endif /* TYPEDECLARINGNODE_H_ */
