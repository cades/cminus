/*
 * FunctionDeclaringNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef FUNCTIONDECLARINGNODE_H_
#define FUNCTIONDECLARINGNODE_H_

#include "AbstractNode.h"
class Identifier;
class NodeList;
class NodeVisitor;

class FunctionDeclaringNode: public AbstractNode {
public:
	FunctionDeclaringNode(Identifier* returnType, Identifier* functionName, NodeList* paramList, AbstractNode* block);
	virtual ~FunctionDeclaringNode();
	virtual void accept(NodeVisitor& visitor);

    Identifier *getReturnType() const { return returnType_; }
    Identifier *getFunctionName() const { return functionName_; }
    NodeList *getParamList() const { return paramList_; }
    AbstractNode *getBlock() const { return block_; }

private:
	Identifier* returnType_;
	Identifier* functionName_;
	NodeList* paramList_;
	AbstractNode* block_;
};

#endif /* FUNCTIONDECLARINGNODE_H_ */
