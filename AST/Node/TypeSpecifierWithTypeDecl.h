/*
 * TypeSpecifierWithTypeDecl.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPESPECIFIERWITHTYPEDECL_H_
#define TYPESPECIFIERWITHTYPEDECL_H_

#include "TypeSpecifier.h"
class TypeDeclaringNode;
class NodeVisitor;

class TypeSpecifierWithTypeDecl: public TypeSpecifier {
public:
	TypeSpecifierWithTypeDecl(TypeDeclaringNode* typeDecl);
	virtual ~TypeSpecifierWithTypeDecl();
	virtual void accept(NodeVisitor& visitor);
private:
	TypeDeclaringNode* typeDecl_;
};

#endif /* TYPESPECIFIERWITHTYPEDECL_H_ */
