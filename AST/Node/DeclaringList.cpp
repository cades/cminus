/*
 * DeclaringList.cpp
 *
 *  Created on: 2012/6/22
 *      Author: mac
 */

#include "DeclaringList.h"
#include "../Visitor/NodeVisitor.h"

DeclaringList::DeclaringList() {
	// TODO Auto-generated constructor stub

}

DeclaringList::~DeclaringList() {
	// TODO Auto-generated destructor stub
}

void DeclaringList::accept(NodeVisitor& visitor) { visitor.visit(*this); }
