/*
 * NotNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "NotNode.h"
#include "IntLiteral.h"
#include "FloatLiteral.h"
#include <stdexcept>
#include <typeinfo>

NotNode::NotNode(Expression* subExpr) : UnaryExpression(subExpr) {
	// TODO Auto-generated constructor stub

}

NotNode::~NotNode() {
	// TODO Auto-generated destructor stub
}

Literal* NotNode::evaluate() {
	// TODO if subExpr_ is a funcall_call?
	Literal* lit = subExpr_->evaluate();
	if (IntLiteral* ilit = dynamic_cast<IntLiteral*>(lit)) {
		if (ilit->getValue() == 0) {
			delete ilit;
			return new IntLiteral(1);
		}
		delete ilit;
		return new IntLiteral(0);
	} else if (FloatLiteral* flit = dynamic_cast<FloatLiteral*>(lit)) {
		if (flit->getValue() == 0) {
			delete flit;
			return new IntLiteral(1);
		}
		delete flit;
		return new IntLiteral(0);
	}
	throw std::runtime_error(std::string("NotNode cannot evaluate constant. subExpr_ is of type ") + typeid(subExpr_).name());
}
