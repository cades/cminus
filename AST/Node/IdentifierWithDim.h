/*
 * IdentifierWithDim.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef IDENTIFIERWITHDIM_H_
#define IDENTIFIERWITHDIM_H_

#include "Identifier.h"
class NodeVisitor;

class IdentifierWithDim: public Identifier {
public:
	IdentifierWithDim(Identifier* name, AbstractNode* dim);
	virtual ~IdentifierWithDim();
	virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* dim_;
};

#endif /* IDENTIFIERWITHDIM_H_ */
