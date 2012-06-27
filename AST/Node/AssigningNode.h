/*
 * AssigningNode.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef ASSIGNINGNODE_H_
#define ASSIGNINGNODE_H_

#include "Expression.h"
#include <stdexcept>
class NodeVisitor;

class AssigningNode: public Expression {
public:
	AssigningNode(Expression*, Expression*);
	virtual ~AssigningNode();
	virtual Literal* evaluate() { throw std::runtime_error("AssigningNode not yet support evaluate()"); }

    virtual void accept(NodeVisitor & visitor);
    Expression *getTargetName() const;
    Expression *getValueExpr() const;
private:
    Expression *targetName_;
    Expression *valueExpr_;
};

#endif /* ASSIGNINGNODE_H_ */
