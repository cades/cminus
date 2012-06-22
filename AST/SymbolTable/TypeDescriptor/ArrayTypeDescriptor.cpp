/*
 * ArrayTypeDescriptor.cpp
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#include "ArrayTypeDescriptor.h"

ArrayTypeDescriptor::ArrayTypeDescriptor() {}

ArrayTypeDescriptor::~ArrayTypeDescriptor() {
	// TODO Auto-generated destructor stub
}

void ArrayTypeDescriptor::setBounds(int bounds_)
{
    this->bounds_ = bounds_;
}

void ArrayTypeDescriptor::setElementType(TypeDescriptor *elementType_)
{
    this->elementType_ = elementType_;
}




