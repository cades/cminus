/*
 * VariableDeclaringList.cpp
 *
 *  Created on: 2012/6/22
 *      Author: mac
 */

#include "VariableDeclaringList.h"
#include "../Visitor/NodeVisitor.h"

VariableDeclaringList::VariableDeclaringList() {
	// TODO Auto-generated constructor stub

}

VariableDeclaringList::~VariableDeclaringList() {
	// TODO Auto-generated destructor stub
}

void VariableDeclaringList::accept(NodeVisitor& visitor) { visitor.visit(*this); }
