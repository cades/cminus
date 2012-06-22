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
#include "DeclaringList.h"

class StructDefiningNode: public AbstractNode {
public:
	StructDefiningNode(DeclaringList* fieldDeclList);
	virtual ~StructDefiningNode();
	virtual void accept(NodeVisitor& visitor);
    TypeDescriptor *getType() const { return type_; }
    void setType(TypeDescriptor *type_) { this->type_ = type_; }

    typedef DeclaringList::Iterator Iterator;
	virtual Iterator* createIterator() { return fieldDeclList_->createIterator(); }

private:
	DeclaringList* fieldDeclList_;
	TypeDescriptor* type_;
};

#endif /* STRUCTDEFININGNODE_H_ */
