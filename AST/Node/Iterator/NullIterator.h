/*
 * NullIterator.h
 *
 *  Created on: 2012/6/20
 *      Author: mac
 */

#ifndef NULLITERATOR_H_
#define NULLITERATOR_H_
#include "IIterator.h"

class NullIterator : public IIterator {
public:
	NullIterator();
	virtual ~NullIterator();
	virtual void First() {}
	virtual void Next() {}
	virtual bool IsDone() const { return true; }
	virtual AbstractNode* CurrentItem() const { return 0; }
};

#endif /* NULLITERATOR_H_ */
