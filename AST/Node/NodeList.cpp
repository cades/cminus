/*
 * NodeList.cpp
 *
 *  Created on: 2012/6/12
 *      Author: mac
 */

#include "NodeList.h"
#include "../Visitor/NodeVisitor.h"
#include <stdexcept>

NodeList::NodeList() {
	// TODO Auto-generated constructor stub

}

NodeList::~NodeList() {
	// TODO Auto-generated destructor stub
}

void NodeList::append(AbstractNode* node) {
	list_.push_back(node);
}

void NodeList::accept(NodeVisitor& visitor) { visitor.visit(*this); }

AbstractNode *NodeList::getChild(int index) {
	if (index >= childrenNumber() || index < 0)
		throw std::runtime_error("NodeList::getChild : attempt to access child out of range.");

	int cnt = index;
	for (List::iterator i = list_.begin(); i != list_.end(); ++i) { // it's not efficient, take O(n), not O(1)
		if(cnt == 0) return *i;
		--cnt;
	}
	throw std::runtime_error("NodeList::getChild : strange error :<");
}

