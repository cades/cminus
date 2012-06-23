/*
 * VariableDeclaringList.h
 *
 *  Created on: 2012/6/22
 *      Author: mac
 */

#ifndef VARIABLEDECLARINGLIST_H_
#define VARIABLEDECLARINGLIST_H_

#include "AbstractNode.h"
#include "VariableListDeclaringNode.h"

class VariableDeclaringList: public AbstractNode {
public:
	typedef list<VariableListDeclaringNode*> List;
	VariableDeclaringList();
	virtual ~VariableDeclaringList();

	void append(VariableListDeclaringNode* node) { list_.push_back(node); }
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(VariableDeclaringList& nl) : declList_(nl) {}
		virtual void First() { i = declList_.list_.begin(); } // this is key point: whether list_ can be touched?
		virtual void Next()  { ++i; }
		virtual bool IsDone() const { return i == declList_.list_.end(); }
		virtual VariableListDeclaringNode* CurrentItem() const { return *i; }
	private:
		VariableDeclaringList& declList_;
		List::iterator i;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

	private:
	List list_;
};

#endif /* DECLARINGLIST_H_ */
