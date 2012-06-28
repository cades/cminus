/*
 * IfTestingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef IFTESTINGNODE_H_
#define IFTESTINGNODE_H_

#include "AbstractNode.h"
#include "ExpressionList.h"
#include <stdexcept>
class NodeVisitor;

class IfTestingNode: public AbstractNode {
public:
	IfTestingNode(ExpressionList* condition, AbstractNode* thenPart, AbstractNode* elsePart);
	virtual ~IfTestingNode();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(IfTestingNode& node) : node_(node), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 3; }
		virtual AbstractNode* CurrentItem() const {
			if (cnt_ == 0) return node_.condition_;
			else if (cnt_ == 1) return node_.thenPart_;
			else if (cnt_ == 2) return node_.elsePart_;
			else throw std::runtime_error("IfTestingNode::Iterator error");
		}
	private:
		IfTestingNode& node_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	ExpressionList* condition_;
	AbstractNode* thenPart_;
	AbstractNode* elsePart_;
};

#endif /* IFTESTINGNODE_H_ */
