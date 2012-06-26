/*
 * UnaryExpression.h
 *
 *  Created on: 2012/6/26
 *      Author: mac
 */

#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

#include "Expression.h"
#include <stdexcept>

class UnaryExpression: public Expression {
public:
	UnaryExpression(Expression*);
	virtual ~UnaryExpression();
	Expression* subExpr() { return subExpr_; }
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() = 0;

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(UnaryExpression& uexpr) : uexpr_(uexpr), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 1; }
		virtual Expression* CurrentItem() const {
			if (cnt_ == 0) return uexpr_.subExpr_;
			else throw std::runtime_error("UnaryExpression::Iterator error");
		}
	private:
		UnaryExpression& uexpr_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

protected:
	Expression* subExpr_;
};

#endif /* UNARYEXPRESSION_H_ */
