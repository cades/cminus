/*
 * LHSSemanticsVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef LHSSEMANTICSVISITOR_H_
#define LHSSEMANTICSVISITOR_H_

#include "SemanticsVisitor.h"
class Attributes;

class LHSSemanticsVisitor: public SemanticsVisitor {
public:
	LHSSemanticsVisitor(SymbolTable*, ostream&);
	virtual ~LHSSemanticsVisitor();

	virtual void visit(Identifier&);
	virtual void visit(ArrayReferencingNode&);
	virtual void visit(StructReferencingNode&);
	bool isAssignable(Attributes*);
};

#endif /* LHSSEMANTICSVISITOR_H_ */
