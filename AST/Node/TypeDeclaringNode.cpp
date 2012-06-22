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

TypeDeclaringNode::TypeDeclaringNode(Identifier* typeName, AbstractNode* typeSpec)
: typeName_(typeName), typeSpec_(typeSpec) {
	// TODO Auto-generated constructor stub

}

TypeDeclaringNode::~TypeDeclaringNode() {
	// TODO Auto-generated destructor stub
}

void TypeDeclaringNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

StructDefiningNode *TypeDeclaringNode::typeSpec() {
	if( StructDefiningNode* sd = dynamic_cast<StructDefiningNode*>(typeSpec_) )
		return sd;
	throw std::runtime_error("TypeDeclaringNode::typeSpec(): cannot dynamic_cast typeSpec_ to StructDefiningNode*");
}

Identifier *TypeDeclaringNode::getTypeName() const
{
    return typeName_;
}




