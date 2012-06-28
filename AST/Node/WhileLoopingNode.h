/*
 * WhileLoopingNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef WHILELOOPINGNODE_H_
#define WHILELOOPINGNODE_H_

#include "AbstractNode.h"
#include <stdexcept>
#include "ExpressionList.h"
class NodeVisitor;

class WhileLoopingNode: public AbstractNode {
public:
	WhileLoopingNode(ExpressionList* condition,  AbstractNode* loopBody);
	virtual ~WhileLoopingNode();
	virtual void accept(NodeVisitor& visitor);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(WhileLoopingNode& node) : node_(node), cnt_(0) {}
		virtual void First() { cnt_ = 0; }
		virtual void Next()  { ++cnt_; }
		virtual bool IsDone() const { return cnt_ == 2; }
		virtual AbstractNode* CurrentItem() const {
			if (cnt_ == 0) return node_.condition_;
			else if (cnt_ == 1) return node_.loopBody_;
			else throw std::runtime_error("WhileLoopingNode::Iterator error");
		}
	private:
		WhileLoopingNode& node_;
		int cnt_;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

private:
	ExpressionList* condition_;
	AbstractNode* loopBody_;
};

#endif /* WHILELOOPINGNODE_H_ */
