/*
 * NegNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "NegNode.h"
#include "IntLiteral.h"
#include "FloatLiteral.h"
#include <stdexcept>
#include <typeinfo>

NegNode::NegNode(Expression* subExpr) : UnaryExpression(subExpr) {
	// TODO Auto-generated constructor stub

}

NegNode::~NegNode() {
	// TODO Auto-generated destructor stub
}

Literal *NegNode::evaluate() {
	// TODO if subExpr_ is a funcall_call?
	Literal* lit = subExpr_->evaluate();
	if (IntLiteral* ilit = dynamic_cast<IntLiteral*>(lit)) {
		IntLiteral* negIlit = new IntLiteral(-ilit->getValue());
		delete ilit;
		return negIlit;
	} else if (FloatLiteral* flit = dynamic_cast<FloatLiteral*>(lit)) {
		FloatLiteral* negFlit = new FloatLiteral(-flit->getValue());
		delete flit;
		return negFlit;
	}
	throw std::runtime_error(std::string("NegNode cannot evaluate constant. subExpr_ is of type ") + typeid(subExpr_).name());
}


