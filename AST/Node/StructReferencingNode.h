/*
 * StructReferencingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef STRUCTREFERENCINGNODE_H_
#define STRUCTREFERENCINGNODE_H_

#include "Expression.h"
#include "Identifier.h"
#include <stdexcept>
class NodeVisitor;

class StructReferencingNode: public Expression {
public:
	StructReferencingNode(Expression* varRef, Identifier* field);
	virtual ~StructReferencingNode();
	virtual Literal* evaluate() { throw std::runtime_error("StructReferencingNode not yet support evaluate()"); }

    virtual void accept(NodeVisitor & visitor);
    Identifier *getField() const { return field_; }
    Expression *getVarRef() const { return varRef_; }

private:
	Expression* varRef_;
	Identifier* field_;
};

#endif /* STRUCTREFERENCINGNODE_H_ */
