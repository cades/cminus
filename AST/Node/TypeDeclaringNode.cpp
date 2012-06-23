/*
 * TypeDeclaringNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypeDeclaringNode.h"
#include "../Visitor/NodeVisitor.h"
#include <stdexcept>
#include "StructDefiningNode.h"

TypeDeclaringNode::TypeDeclaringNode(Identifier* typeName, StructDefiningNode* typeSpec)
: typeSpec_(typeSpec) {
	typeNameList_ = new IdentifierList;
	typeNameList_->append(typeName);
}

TypeDeclaringNode::TypeDeclaringNode(IdentifierList* typeNameList, StructDefiningNode* typeSpec)
: typeNameList_(typeNameList), typeSpec_(typeSpec) {}

TypeDeclaringNode::~TypeDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void TypeDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

StructDefiningNode *TypeDeclaringNode::typeSpec() {
	if( StructDefiningNode* sd = dynamic_cast<StructDefiningNode*>(typeSpec_) )
		return sd;
	throw std::runtime_error("TypeDeclaringNode::typeSpec(): cannot dynamic_cast typeSpec_ to StructDefiningNode*");
}




