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
class NodeList;
class NodeVisitor;
class StructDefiningNode;
#include "Iterator/NullIterator.h"

class TypeDeclaringNode: public AbstractNode {
public:
	TypeDeclaringNode(Identifier* typeName, StructDefiningNode* typeSpec);
	virtual ~TypeDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
	StructDefiningNode* typeSpec();
	Identifier *getTypeName() const;
	std::string nameAsString()
	{
		return typeName_->name();
	}

	// I have no id list :)
	virtual IIterator* createIterator() { return new NullIterator; }
private:
	Identifier* typeName_;
	StructDefiningNode* typeSpec_;
};

#endif /* TYPEDECLARINGNODE_H_ */
