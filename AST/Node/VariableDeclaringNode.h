/*
 * VariableDeclaringNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef VARIABLEDECLARINGNODE_H_
#define VARIABLEDECLARINGNODE_H_

#include "AbstractNode.h"
class Identifier;
class NodeVisitor;

class VariableDeclaringNode: public AbstractNode {
public:
	VariableDeclaringNode(Identifier* typeName, Identifier* id);
	virtual ~VariableDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
private:
	Identifier* typeName_;
	Identifier* id_;
};

#endif /* VARIABLEDECLARINGNODE_H_ */
