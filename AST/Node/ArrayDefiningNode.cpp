/*
 * ArrayDefiningNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "ArrayDefiningNode.h"
#include "../Visitor/NodeVisitor.h"
#include <stdexcept>
#include <sstream>

ArrayDefiningNode::ArrayDefiningNode(Expression* sizeExpr, AbstractNode* elementType)
: sizeExpr_(sizeExpr), elementType_(elementType) {}

ArrayDefiningNode::~ArrayDefiningNode() {}

void ArrayDefiningNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

AbstractNode *ArrayDefiningNode::getChild(int index) {
	if (index == 0) {
		return sizeExpr_;
	} else if (index == 1) {
		return elementType_;
	} else {
		std::stringstream ss;
		ss << "ArrayDefiningNode::getChild(" << index <<  ") : out of bound.";
		throw std::runtime_error(ss.str());
	}
}

AbstractNode *ArrayDefiningNode::getElementType() const
{
    return elementType_;
}

Expression *ArrayDefiningNode::getSizeExpr() const
{
    return sizeExpr_;
}

TypeDescriptor *ArrayDefiningNode::getType() const
{
    return type_;
}

void ArrayDefiningNode::setType(TypeDescriptor *type_)
{
    this->type_ = type_;
}





