/*
 * AbstractNode.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "AbstractNode.h"
#include <stdexcept>

AbstractNode::AbstractNode() {}

AbstractNode::~AbstractNode() {}

int AbstractNode::childrenNumber() {
	throw std::runtime_error("Call AbstractNode::childrenNumber(). Maybe you forgot override it in some Node?");
}

AbstractNode* AbstractNode::getChild(int index) {
	throw std::runtime_error("Call AbstractNode::childrenNumbergetChild(int index). Maybe you forgot override it in some Node?");
}

IIterator* AbstractNode::createIterator() {
	throw std::runtime_error("Call AbstractNode::createIterator(). Maybe you forgot override it in some Node?");
}
