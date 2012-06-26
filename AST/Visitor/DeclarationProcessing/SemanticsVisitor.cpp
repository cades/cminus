/*
 * SemanticsVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "SemanticsVisitor.h"
#include "../../Node/IntLiteral.h"
#include "../../Node/FloatLiteral.h"
#include "../../Node/BinaryExpression.h"
#include "../../Node/UnaryExpression.h"
#include "../../Node/RelationalExpression.h"

#include "../../SymbolTable/TypeDescriptor/IntegerTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/FloatTypeDescriptor.h"


SemanticsVisitor::SemanticsVisitor() {
}

SemanticsVisitor::~SemanticsVisitor() {
}

void SemanticsVisitor::visit(Identifier& id) {

}

void SemanticsVisitor::visit(IntLiteral& intlit) {
	intlit.setType(new IntegerTypeDescriptor); // FIXME should I use TypeDescriptor in symtab? Singleton?
}

void SemanticsVisitor::visit(FloatLiteral& floatlit) {
	floatlit.setType(new FloatTypeDescriptor); // FIXME should I use TypeDescriptor in symtab?
}

void SemanticsVisitor::visit(BinaryExpression& bexpr) {
	visitChildren(bexpr);
	bexpr.setType(bexpr.binaryResultType());
}

void SemanticsVisitor::visit(UnaryExpression& uexpr) {
	visitChildren(uexpr);
	uexpr.setType(uexpr.unaryResultType());
}

void SemanticsVisitor::visit(RelationalExpression& rexpr) {
	visitChildren(rexpr);
	rexpr.setType(rexpr.relationalResultType());
}


void SemanticsVisitor::visit(ArrayReferencingNode & node) {

}

void SemanticsVisitor::visit(StructReferencingNode & node) {

}


