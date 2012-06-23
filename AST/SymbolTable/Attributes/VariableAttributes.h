/*
 * VariableAttributes.h
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#ifndef VARIABLEATTRIBUTES_H_
#define VARIABLEATTRIBUTES_H_

#include "Attributes.h"
#include "../TypeDescriptor/TypeDescriptor.h"

class VariableAttributes: public Attributes {
public:
	VariableAttributes();
	virtual ~VariableAttributes();
	virtual TypeDescriptor* getType() const { return typeDesc_; }
	virtual void setType(TypeDescriptor* td) { typeDesc_ = td; }
private:
	TypeDescriptor* typeDesc_;
};

#endif /* VARIABLEATTRIBUTES_H_ */
