/*
 * IIterator.h
 *
 *  Created on: 2012/6/21
 *      Author: mac
 */

#ifndef IITERATOR_H_
#define IITERATOR_H_
class AbstractNode;

// interface
class IIterator {
public:
	IIterator();
	virtual ~IIterator();
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual AbstractNode* CurrentItem() const = 0;
};


#endif /* IITERATOR_H_ */
