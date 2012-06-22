/*
 * Attributes.h
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#ifndef ATTRIBUTES_H_
#define ATTRIBUTES_H_
class TypeDescriptor;

class Attributes {
protected:
	Attributes();	// plz use my subclasses.
public:
	virtual ~Attributes();
	virtual TypeDescriptor* getType() const = 0;
	virtual void setType(TypeDescriptor*) = 0;
};

#endif /* ATTRIBUTES_H_ */
