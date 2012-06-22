/*
 * ArrayDefiningNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef ARRAYDEFININGNODE_H_
#define ARRAYDEFININGNODE_H_

#include "AbstractNode.h"
class NodeVisitor;
#include <stdexcept>
class TypeDescriptor;
#include "Expression.h"

class ArrayDefiningNode: public AbstractNode {
public:
	ArrayDefiningNode(Expression* sizeExpr, AbstractNode* elementType);
	virtual ~ArrayDefiningNode();
	virtual void accept(NodeVisitor& visitor);

	virtual int childrenNumber() { return 2; }
	virtual AbstractNode* getChild(int index);

	// Composite method API #2
	class Iterator : public IIterator {
	public:
		Iterator(ArrayDefiningNode& adn) : adn_(adn), cnt(0) {}
		virtual void First() { cnt = 0; }
		virtual void Next()  { ++cnt; }
		virtual bool IsDone() const { return cnt == 2; }
		virtual AbstractNode* CurrentItem() const {
			switch(cnt) {
			case 0:	return adn_.sizeExpr_;
			case 1:	return adn_.elementType_;
			default:throw std::runtime_error("error : ArrayDefiningNodeIterator::CurrentItem() out of bound");
			}
		}
	private:
		ArrayDefiningNode& adn_;
		int cnt;
	};
	virtual Iterator* createIterator() { return new Iterator(*this); }

	Expression *getSizeExpr() const;
    AbstractNode *getElementType() const;
    TypeDescriptor *getType() const;
    void setType(TypeDescriptor *type_);

private:
    Expression* sizeExpr_;
	AbstractNode* elementType_;

	TypeDescriptor* type_;
};

#endif /* ARRAYDEFININGNODE_H_ */
