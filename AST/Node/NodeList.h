/*
 * NodeList.h
 *
 *  Created on: 2012/6/12
 *      Author: mac
 */

#ifndef NODELIST_H_
#define NODELIST_H_
#include "AbstractNode.h"
#include <list>
using std::list;
class NodeVisitor;
#include "Iterator/IIterator.h"

class NodeList : public AbstractNode {
public:
	typedef list<AbstractNode*> List;
	NodeList();
	virtual ~NodeList();
	void append(AbstractNode*);
	int length() { return list_.size(); }
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #1
	virtual int childrenNumber() { return list_.size(); }
	virtual AbstractNode* getChild(int index);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(NodeList& nl) : nodeList(nl) {}
		virtual void First() { i = nodeList.list_.begin(); } // this is key point: whether list_ can be touched?
		virtual void Next()  { ++i; }
		virtual bool IsDone() const { return i == nodeList.list_.end(); }
		virtual AbstractNode* CurrentItem() const { return *i; }
	private:
		NodeList& nodeList;
		List::iterator i;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	List list_;
};

#endif /* NODELIST_H_ */
