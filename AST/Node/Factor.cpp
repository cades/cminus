/*
 * Factor.cpp
 *
 *  Created on: 2012/6/19
 *      Author: mac
 */

#include "Factor.h"
#include "../Visitor/NodeVisitor.h"

Factor::Factor(AbstractNode* subExpr) : subExpr_(subExpr) {
	// TODO Auto-generated constructor stub

}

Factor::~Factor() {
	// TODO Auto-generated destructor stub
}

void Factor::accept(NodeVisitor & visitor) { visitor.visit(*this); }


