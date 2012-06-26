/*
 * BinaryExpression.cpp
 *
 *  Created on: 2012/6/18
 *      Author: mac
 */

#include "BinaryExpression.h"
#include "../Visitor/NodeVisitor.h"
#include "../SymbolTable/TypeDescriptor/FloatTypeDescriptor.h"

BinaryExpression::BinaryExpression(Expression* lhs, Expression* rhs) : lhs_(lhs), rhs_(rhs) {
	// TODO Auto-generated constructor stub

}

BinaryExpression::~BinaryExpression() {
	// TODO Auto-generated destructor stub
}

/*
 * This is a template method, and is also non-virtual. It doesn't want to be override.
 * Hook point is
 * 	virtual float floatOp(float, float)
 * 	virtual   int intOp(int, int)
 */
Literal *BinaryExpression::evaluate() {
	// if subExpr_ is a var_ref or funcall_call, test would fail.
	Literal* lLit = 0;
	Literal* rLit = 0;
	try {
		lLit = lhs_->evaluate(); // recursive call
		rLit = rhs_->evaluate(); // recursive call
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
	throw std::runtime_error("BinaryExpression::evaluate:  unknown error");
}

TypeDescriptor* BinaryExpression::binaryResultType() {
	TypeDescriptor* const ltype = lhs_->getType();
	TypeDescriptor* const rtype = rhs_->getType();
	if (dynamic_cast<FloatTypeDescriptor*>(ltype)) return ltype;
	return rtype;
}

void BinaryExpression::accept(NodeVisitor& visitor) { visitor.visit(*this); }
