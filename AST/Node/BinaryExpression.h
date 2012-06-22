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
	BinaryExpression();
	virtual ~BinaryExpression();
	virtual Literal* evaluate() = 0;
protected:
	template<class FloatOp, class IntOp>
	Literal* binary_evaluate(AbstractNode* lhs_, AbstractNode* rhs_, FloatOp floatOp, IntOp intOp) {
		// if subExpr_ is a var_ref or funcall_call, test would fail.
		if (dynamic_cast<Expression*>(lhs_) && dynamic_cast<Expression*>(rhs_)) {
			Expression* lExpr = dynamic_cast<Expression*>(lhs_);
			Expression* rExpr = dynamic_cast<Expression*>(rhs_);
			Literal* lLit = 0;
			Literal* rLit = 0;
			try {
				lLit = lExpr->evaluate(); // recursive call
				rLit = rExpr->evaluate(); // recursive call
			} catch (std::runtime_error& e) {
				delete lLit;	// if lLit success and rLit failed, leak occurs. Intercept here for avoid leak.
				throw;			// cleanup done, continue issue error.
			}
			if (dynamic_cast<FloatLiteral*>(lLit)) {
				FloatLiteral* l = dynamic_cast<FloatLiteral*>(lLit);
				if (FloatLiteral* r = dynamic_cast<FloatLiteral*>(rLit)) {
					FloatLiteral* res = new FloatLiteral(
							floatOp(l->getValue() , r->getValue())
					);
					delete l;
					delete r;
					return res;
				}
				if (IntLiteral* r = dynamic_cast<IntLiteral*>(rLit)) {
					FloatLiteral* res = new FloatLiteral(
							floatOp(l->getValue() , r->getValue())
					);
					delete l;
					delete r;
					return res;
				}
			} else {
				IntLiteral* l = dynamic_cast<IntLiteral*>(lLit);
				if (FloatLiteral* r = dynamic_cast<FloatLiteral*>(rLit)) {
					FloatLiteral* res = new FloatLiteral(
							floatOp(l->getValue() , r->getValue())
					);
					delete l;
					delete r;
					return res;
				}
				if (IntLiteral* r = dynamic_cast<IntLiteral*>(rLit)) {
					IntLiteral* res = new IntLiteral(
							intOp(l->getValue() , r->getValue())
					);
					delete l;
					delete r;
					return res;
				}
			}
		}
		throw std::runtime_error(std::string("Cannot evaluate constant. lhs_ is of type ") + typeid(*lhs_).name()
				+ ", rhs_ is of type " + typeid(*rhs_).name());
	}
};

#endif /* BINARYEXPRESSION_H_ */
