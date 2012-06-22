/*
 * IntLiteral.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef INTLITERAL_H_
#define INTLITERAL_H_

#include "Literal.h"
class NodeVisitor;

class IntLiteral: public Literal {
public:
	IntLiteral(int);
	virtual ~IntLiteral();
	virtual void accept(NodeVisitor& visitor);
    int getValue() const;
    virtual Literal* evaluate() { return new IntLiteral(*this); }
private:
	int value_;
};

#endif /* INTLITERAL_H_ */
