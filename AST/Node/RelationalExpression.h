/*
 * RelationalExpression.h
 *
 *  Created on: 2012/6/26
 *      Author: mac
 */

#ifndef RELATIONALEXPRESSION_H_
#define RELATIONALEXPRESSION_H_

#include "Expression.h"
#include <stdexcept>

class RelationalExpression: public Expression {
public:
	RelationalExpression(Expression* lhs, Expression* rhs);
	virtual ~RelationalExpression();
	virtual Literal* evaluate() { throw std::runtime_error("RelationalExpression not yet support evaluate()"); } // TODO implement it
	TypeDescriptor* relationalResultType();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(RelationalExpression& rexpr) : rexpr_(rexpr), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 2; }
		virtual Expression* CurrentItem() const {
			if (cnt_ == 0) return rexpr_.lhs_;
			else if (cnt_ == 1) return rexpr_.rhs_;
			else throw std::runtime_error("RelationalExpression::Iterator error");
		}
	private:
		RelationalExpression& rexpr_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

protected:
	Expression* lhs_;
	Expression* rhs_;
};

#endif /* RELATIONALEXPRESSION_H_ */
