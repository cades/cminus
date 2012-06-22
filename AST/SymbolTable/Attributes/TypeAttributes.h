/*
 * TypeAttributes.h
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#ifndef TYPEATTRIBUTES_H_
#define TYPEATTRIBUTES_H_

#include "Attributes.h"
#include "../TypeDescriptor/TypeDescriptor.h"

class TypeAttributes: public Attributes {
public:
	TypeAttributes();
	virtual ~TypeAttributes();
	virtual TypeDescriptor *getType() const
    {
        return typeDesc_;
    }

	virtual void setType(TypeDescriptor *typeDesc_)
    {
        this->typeDesc_ = typeDesc_;
    }
private:
	TypeDescriptor* typeDesc_;
};

#endif /* TYPEATTRIBUTES_H_ */
