/*
 * ExpressionList.h
 *
 *  Created on: 2012/6/27
 *      Author: mac
 */

#ifndef EXPRESSIONLIST_H_
#define EXPRESSIONLIST_H_

#include "AbstractNode.h"
#include "Expression.h"
#include <list>
using std::list;
class NodeVisitor;
#include "Iterator/IIterator.h"

class ExpressionList: public AbstractNode {
public:
	typedef list<Expression*> List;
	ExpressionList();
	virtual ~ExpressionList();
	void append(Expression* expr) { list_.push_back(expr); }
	int length() { return list_.size(); }
	virtual void accept(NodeVisitor&) {}
	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(ExpressionList& el) : exprList_(el) {}
		virtual void First() { i = exprList_.list_.begin(); } // this is key point: whether list_ can be touched?
		virtual void Next()  { ++i; }
		virtual bool IsDone() const { return i == exprList_.list_.end(); }
		virtual Expression* CurrentItem() const { return *i; }
	private:
		ExpressionList& exprList_;
		List::iterator i;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	List list_;
};

#endif /* EXPRESSIONLIST_H_ */
