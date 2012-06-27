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
	ArrayReferencingNode(Expression* varRef, Expression* dimExpr);
	virtual ~ArrayReferencingNode();
	virtual Literal* evaluate() { throw std::runtime_error("ArrayReferencingNode not yet support evaluate()"); } // TODO implement it
	virtual void accept(NodeVisitor& visitor);

    Expression *getDimExpr() const{ return dimExpr_; }
    Expression *getVarRef() const { return varRef_; }

    // Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(ArrayReferencingNode& ar) : ar_(ar), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 2; }
		virtual Expression* CurrentItem() const {
			if (cnt_ == 0) return ar_.varRef_;
			else if (cnt_ == 1) return ar_.dimExpr_;
			else throw std::runtime_error("ArrayReferencingNode::Iterator error");
		}
	private:
		ArrayReferencingNode& ar_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	Expression* varRef_;
	Expression* dimExpr_;
};

#endif /* ARRAYREFERENCINGNODE_H_ */
