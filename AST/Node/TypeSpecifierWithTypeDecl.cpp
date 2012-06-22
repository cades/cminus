/*
 * TypeSpecifierWithTypeDecl.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "TypeSpecifierWithTypeDecl.h"
#include "../Visitor/NodeVisitor.h"

TypeSpecifierWithTypeDecl::TypeSpecifierWithTypeDecl(TypeDeclaringNode* typeDecl) : typeDecl_(typeDecl) {
	// TODO Auto-generated constructor stub

}

TypeSpecifierWithTypeDecl::~TypeSpecifierWithTypeDecl() {
	// TODO Auto-generated destructor stub
}

void TypeSpecifierWithTypeDecl::accept(NodeVisitor& visitor) { visitor.visit(*this); }
