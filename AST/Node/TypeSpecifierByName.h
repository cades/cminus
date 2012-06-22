/*
 * TypeSpecifierByName.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPESPECIFIERBYNAME_H_
#define TYPESPECIFIERBYNAME_H_

#include "TypeSpecifier.h"
class Identifier;
class NodeVisitor;

class TypeSpecifierByName: public TypeSpecifier {
public:
	TypeSpecifierByName(Identifier* typeName);
	virtual ~TypeSpecifierByName();
	virtual void accept(NodeVisitor& visitor);
private:
	Identifier* typeName_;
};

#endif /* TYPESPECIFIERBYNAME_H_ */
