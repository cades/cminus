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
class NodeVisitor;
#include <stdexcept>
#include "NodeList.h"
#include "ExpressionList.h"
#include "Identifier.h"

class CallingNode: public Expression {
public:
	CallingNode(Identifier* functionName, ExpressionList* argList);
	virtual ~CallingNode();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate() { throw std::runtime_error("CallingNode DONOT support evaluate()."); }

	ExpressionList *getArgList() const { return argList_; }
	Identifier *getFunctionName() const { return functionName_; }

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(CallingNode& cn) : cn_(cn), cnt_(0) { i_ = cn_.argList_->createIterator(); }
		virtual void First() { cnt_ = 0; i_->First(); }
		virtual void Next()  {
			++cnt_;
			if (cnt_ > 0) i_->Next();
		}
		virtual bool IsDone() const { return cnt_ == 1 + cn_.argList_->length(); }
		virtual Expression* CurrentItem() const {
			if (cnt_ == 0) return cn_.functionName_;
			else return i_->CurrentItem();
		}
	private:
		CallingNode& cn_;
		int cnt_;
		ExpressionList::Iterator* i_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	Identifier* functionName_;
	ExpressionList* argList_;   // list of VariableListDeclaringNode & ArrayVariableDeclaringNode
};

#endif /* CALLINGNODE_H_ */
