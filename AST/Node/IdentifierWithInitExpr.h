/*
 * IdentifierWithInitExpr.h
 *
 *  Created on: 2012/6/20
 *      Author: mac
 */

#ifndef IDENTIFIERWITHINITEXPR_H_
#define IDENTIFIERWITHINITEXPR_H_

#include "Identifier.h"

class IdentifierWithInitExpr: public Identifier {
public:
	IdentifierWithInitExpr(Identifier* name, AbstractNode* initExpr);
	virtual ~IdentifierWithInitExpr();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* initExpr_;
};

#endif /* IDENTIFIERWITHINITEXPR_H_ */
