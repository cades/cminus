/*
 * FloatLiteral.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef FLOATLITERAL_H_
#define FLOATLITERAL_H_

#include "Literal.h"
class NodeVisitor;

class FloatLiteral: public Literal {
public:
	FloatLiteral(float);
	virtual ~FloatLiteral();
	virtual void accept(NodeVisitor& visitor);
    float getValue() const;
    virtual Literal* evaluate() { return new FloatLiteral(*this); }
private:
	float value_;
};

#endif /* FLOATLITERAL_H_ */
