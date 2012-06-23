/*
 * VoidTypeDescriptor.h
 *
 *  Created on: 2012/6/23
 *      Author: mac
 */

#ifndef VOIDTYPEDESCRIPTOR_H_
#define VOIDTYPEDESCRIPTOR_H_

#include "TypeDescriptor.h"

class VoidTypeDescriptor: public TypeDescriptor {
public:
	VoidTypeDescriptor();
	virtual ~VoidTypeDescriptor();
};

#endif /* VOIDTYPEDESCRIPTOR_H_ */
