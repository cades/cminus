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
class ArrayDefiningNode;

class ArrayVariableDeclaringNode: public AbstractNode {
public:
	ArrayVariableDeclaringNode(Identifier* typeName, Identifier* id, ArrayDefiningNode* dim);
	virtual ~ArrayVariableDeclaringNode();
	virtual void accept(NodeVisitor& visitor);
	ArrayDefiningNode *getDim() const;
    Identifier *getId() const;
    Identifier *getTypeName() const;
private:
	Identifier* typeName_;
	Identifier* id_;
	ArrayDefiningNode* dim_;
};

#endif /* ARRAYVARIABLEDECLARINGNODE_H_ */
