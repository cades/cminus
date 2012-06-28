/*
 * ForLoopingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef FORLOOPINGNODE_H_
#define FORLOOPINGNODE_H_

#include "AbstractNode.h"
#include <stdexcept>
#include "ExpressionList.h"
class NodeVisitor;

class ForLoopingNode: public AbstractNode {
public:
	ForLoopingNode(ExpressionList* initializer, ExpressionList* condition, ExpressionList* increment,  AbstractNode* loopBody);
	virtual ~ForLoopingNode();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(ForLoopingNode& node) : node_(node), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 4; }
		virtual AbstractNode* CurrentItem() const {
			if (cnt_ == 0) return node_.initializer_;
			else if (cnt_ == 1) return node_.condition_;
			else if (cnt_ == 2) return node_.increment_;
			else if (cnt_ == 3) return node_.loopBody_;
			else throw std::runtime_error("ForLoopingNode::Iterator error");
		}
	private:
		ForLoopingNode& node_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

	ExpressionList *getCondition() const { return condition_; }
private:
	ExpressionList* initializer_;
	ExpressionList* condition_;
	ExpressionList* increment_;
	AbstractNode* loopBody_;
};

#endif /* FORLOOPINGNODE_H_ */
