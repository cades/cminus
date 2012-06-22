/*
 * FieldAttributes.h
 *
 *  Created on: 2012/6/21
 *      Author: mac
 */

#ifndef FIELDATTRIBUTES_H_
#define FIELDATTRIBUTES_H_

#include "Attributes.h"
#include "../TypeDescriptor/TypeDescriptor.h"

class FieldAttributes: public Attributes {
public:
	FieldAttributes();
	virtual ~FieldAttributes();
	virtual TypeDescriptor *getType() const { return typeDesc_; }
	virtual void setType(TypeDescriptor *typeDesc_) { this->typeDesc_ = typeDesc_; }

private:
	TypeDescriptor* typeDesc_;
};

#endif /* FIELDATTRIBUTES_H_ */
