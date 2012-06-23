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
#include "VariableDeclaringList.h"

class StructDefiningNode: public AbstractNode {
public:
	StructDefiningNode(VariableDeclaringList* fieldDeclList);
	virtual ~StructDefiningNode();
	virtual void accept(NodeVisitor& visitor);
    TypeDescriptor *getType() const { return type_; }
    void setType(TypeDescriptor *type_) { this->type_ = type_; }

    typedef VariableDeclaringList::Iterator Iterator;
	virtual Iterator* createIterator() { return fieldDeclList_->createIterator(); }

private:
	VariableDeclaringList* fieldDeclList_;
	TypeDescriptor* type_;
};

#endif /* STRUCTDEFININGNODE_H_ */
