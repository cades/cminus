/*
 * IdentifierWithInitExpr.cpp
 *
 *  Created on: 2012/6/20
 *      Author: mac
 */

#include "IdentifierWithInitExpr.h"
#include "../Visitor/NodeVisitor.h"

IdentifierWithInitExpr::IdentifierWithInitExpr(Identifier* name, AbstractNode* initExpr)
: Identifier(*name), initExpr_(initExpr) {
	// TODO Auto-generated constructor stub

}

IdentifierWithInitExpr::~IdentifierWithInitExpr() {
	// TODO Auto-generated destructor stub
}

void IdentifierWithInitExpr::accept(NodeVisitor & visitor) { visitor.visit(*this); }

