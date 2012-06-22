/*
 * StructTypeDescriptor.h
 *
 *  Created on: 2012/6/14
 *      Author: mac
 */

#ifndef STRUCTTYPEDESCRIPTOR_H_
#define STRUCTTYPEDESCRIPTOR_H_

#include "TypeDescriptor.h"
#include "../SymbolTable.h"

class StructTypeDescriptor: public TypeDescriptor {
public:
	StructTypeDescriptor();
	virtual ~StructTypeDescriptor();

	SymbolTable& getSymbolTable() { return symtab_; }
private:
	SymbolTable symtab_;
};

#endif /* STRUCTTYPEDESCRIPTOR_H_ */
