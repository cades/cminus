/*
 * TypeSpecifierByStruct.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPESPECIFIERBYSTRUCT_H_
#define TYPESPECIFIERBYSTRUCT_H_

#include "TypeSpecifier.h"
class StructDefiningNode;
class NodeVisitor;

class TypeSpecifierByStruct: public TypeSpecifier {
public:
	TypeSpecifierByStruct(StructDefiningNode* structure);
	virtual ~TypeSpecifierByStruct();
	virtual void accept(NodeVisitor& visitor);
private:
	StructDefiningNode* structure_;
};

#endif /* TYPESPECIFIERBYSTRUCT_H_ */
