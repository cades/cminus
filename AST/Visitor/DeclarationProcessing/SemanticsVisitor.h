/*
 * SemanticsVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef SEMANTICSVISITOR_H_
#define SEMANTICSVISITOR_H_

#include "../NodeVisitor.h"

class SemanticsVisitor: public NodeVisitor {
public:
	SemanticsVisitor();
	virtual ~SemanticsVisitor();
};

#endif /* SEMANTICSVISITOR_H_ */
