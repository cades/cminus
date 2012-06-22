/*
 * StringLiteral.cpp
 *
 *  Created on: 2012/6/12
 *      Author: mac
 */

#include "StringLiteral.h"
#include "../Visitor/NodeVisitor.h"

StringLiteral::StringLiteral(const string& s) : data_(s) {
	// TODO Auto-generated constructor stub

}

StringLiteral::~StringLiteral() {
	// TODO Auto-generated destructor stub
}

void StringLiteral::accept(NodeVisitor& visitor) { visitor.visit(*this); }
