/*
 * BinaryExpression.h
 *
 *  Created on: 2012/6/18
 *      Author: mac
 */

#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "Expression.h"
#include <stdexcept>
#include <typeinfo>
#include "Literal.h"
#include "IntLiteral.h"
#include "FloatLiteral.h"

class BinaryExpression: public Expression {
public:
	BinaryExpression(Expression* lhs, Expression* rhs);
	virtual ~BinaryExpression();
	Literal* evaluate();
	TypeDescriptor* binaryResultType();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(BinaryExpression& bexpr) : bexpr_(bexpr), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 2; }
		virtual Expression* CurrentItem() const {
			if (cnt_ == 0) return bexpr_.lhs_;
			else if (cnt_ == 1) return bexpr_.rhs_;
			else throw std::runtime_error("BinaryExpression::Iterator error");
		}
	private:
		BinaryExpression& bexpr_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

protected:
	virtual float floatOp(float, float) = 0; // hook point
	virtual int intOp(int, int) = 0;		 // hook point

protected:
	Expression* lhs_;
	Expression* rhs_;
};

#endif /* BINARYEXPRESSION_H_ */
