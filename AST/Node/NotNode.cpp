/*
 * NotNode.cpp
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#include "NotNode.h"
#include "../Visitor/NodeVisitor.h"
#include "IntLiteral.h"
#include "FloatLiteral.h"
#include <stdexcept>
#include <typeinfo>

NotNode::NotNode(AbstractNode* subExpr) : subExpr_(subExpr) {
	// TODO Auto-generated constructor stub

}

NotNode::~NotNode() {
	// TODO Auto-generated destructor stub
}

void NotNode::accept(NodeVisitor& visitor) { visitor.visit(*this); }

Literal* NotNode::evaluate() {
	// if subExpr_ is a var_ref or funcall_call, test would fail.
	if (Expression* expr = dynamic_cast<Expression*>(subExpr_)) {
		Literal* lit = expr->evaluate();
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
	}
	throw std::runtime_error(std::string("NotNode cannot evaluate constant. subExpr_ is of type ") + typeid(subExpr_).name());
}
