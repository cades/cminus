/*
 * ArrayTypeDescriptor.h
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#ifndef ARRAYTYPEDESCRIPTOR_H_
#define ARRAYTYPEDESCRIPTOR_H_

#include "TypeDescriptor.h"
class AbstractNode;

class ArrayTypeDescriptor: public TypeDescriptor {
public:
	ArrayTypeDescriptor();
	virtual ~ArrayTypeDescriptor();
    void setBounds(int bounds_);
    void setElementType(TypeDescriptor *elementType_);

private:
	int bounds_;
	TypeDescriptor* elementType_;
};

#endif /* ARRAYTYPEDESCRIPTOR_H_ */
