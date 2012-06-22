/*
 * IdentifierList.h
 *
 *  Created on: 2012/6/20
 *      Author: mac
 */

#ifndef IDENTIFIERLIST_H_
#define IDENTIFIERLIST_H_

#include "AbstractNode.h"
#include "Identifier.h"
#include <list>
using std::list;
class NodeVisitor;
#include "Iterator/IIterator.h"

class IdentifierList: public AbstractNode {
public:
	typedef list<Identifier*> List;
	IdentifierList();
	virtual ~IdentifierList();
	void append(Identifier*);
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(IdentifierList& il) : idList_(il) {}
		virtual void First() { i = idList_.list_.begin(); } // this is key point: whether list_ can be touched?
		virtual void Next()  { ++i; }
		virtual bool IsDone() const { return i == idList_.list_.end(); }
		virtual Identifier* CurrentItem() const { return *i; }
	private:
		IdentifierList& idList_;
		List::iterator i;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	List list_;
};

#endif /* IDENTIFIERLIST_H_ */
