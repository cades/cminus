/*
 * ArrayVariableDeclaringNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ARRAYVARIABLEDECLARINGNODE_H_
#define ARRAYVARIABLEDECLARINGNODE_H_

#include "AbstractNode.h"
class Identifier;
class NodeVisitor;

class ArrayVariableDeclaringNode: public AbstractNode {
public:
	ArrayVariableDeclaringNode(Identifier* typeName, Identifier* id, AbstractNode* dim);
	virtual ~ArrayVariableDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
private:
	Identifier* typeName_;
	Identifier* id_;
	AbstractNode* dim_;
};

#endif /* ARRAYVARIABLEDECLARINGNODE_H_ */
