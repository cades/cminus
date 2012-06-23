/*
 * TypeVisitor.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef TYPEVISITOR_H_
#define TYPEVISITOR_H_

#include "TopDeclVisitor.h"
#include <iosfwd>
using std::ostream;
class SymbolTable;

class TypeVisitor: public TopDeclVisitor {
public:
	TypeVisitor(SymbolTable*, ostream&);
	virtual ~TypeVisitor();

	virtual void visit(Identifier&);
	virtual void visit(ArrayDefiningNode&);
	virtual void visit(StructDefiningNode&);
};

#endif /* TYPEVISITOR_H_ */
