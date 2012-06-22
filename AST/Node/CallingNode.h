/*
 * CallingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef CALLINGNODE_H_
#define CALLINGNODE_H_

#include "Expression.h"
class Identifier;
class NodeList;
class NodeVisitor;
#include <stdexcept>

class CallingNode: public Expression {
public:
	CallingNode(Identifier* functionName, NodeList* argList);
	virtual ~CallingNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() { throw std::runtime_error("CallingNode DONOT support evaluate()."); }
private:
	Identifier* functionName_;
	NodeList* argList_;
};

#endif /* CALLINGNODE_H_ */
