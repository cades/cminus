/*
 * ArrayReferencingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ARRAYREFERENCINGNODE_H_
#define ARRAYREFERENCINGNODE_H_

#include "Expression.h"
#include <stdexcept>
class NodeVisitor;

class ArrayReferencingNode: public Expression {
public:
	ArrayReferencingNode(AbstractNode* varRef, AbstractNode* dimExpr);
	virtual ~ArrayReferencingNode();
	virtual Literal* evaluate() { throw std::runtime_error("ArrayReferencingNode not yet support evaluate()"); } // TODO implement it
		virtual void accept(NodeVisitor& visitor);
private:
	AbstractNode* varRef_;
	AbstractNode* dimExpr_;
};

#endif /* ARRAYREFERENCINGNODE_H_ */
