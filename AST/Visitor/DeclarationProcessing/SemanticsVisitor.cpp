/*
 * SemanticsVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "SemanticsVisitor.h"
#include "LHSSemanticsVisitor.h"
#include <ostream>
#include "../../Node/Identifier.h"
#include "../../Node/IntLiteral.h"
#include "../../Node/FloatLiteral.h"
#include "../../Node/BinaryExpression.h"
#include "../../Node/UnaryExpression.h"
#include "../../Node/RelationalExpression.h"
#include "../../Node/AssigningNode.h"

#include "../../SymbolTable/SymbolTable.h"
#include "../../SymbolTable/Attributes/Attributes.h"
#include "../../SymbolTable/Attributes/VariableAttributes.h"
#include "../../SymbolTable/Attributes/FieldAttributes.h"
#include "../../SymbolTable/TypeDescriptor/IntegerTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/FloatTypeDescriptor.h"


SemanticsVisitor::SemanticsVisitor(SymbolTable* symtab, ostream& os) : NodeVisitor(symtab, os) {
}

SemanticsVisitor::~SemanticsVisitor() {
}

void SemanticsVisitor::visit(AssigningNode& assign) {
	LHSSemanticsVisitor lhsVisitor(&currentSymbolTable(), errorLog());
	assign.getTargetName()->accept(lhsVisitor);
	assign.getValueExpr()->accept(*this);
	if ( assignable( assign.getTargetName()->getType(), assign.getValueExpr()->getType() ) ) {
		assign.setType( assign.getTargetName()->getType() );
	} else {
		errorLog() << "Right hand side expression not assignable to left hand side name at " << &assign << "\n";
		assign.setType(0); // NOTICE by design, null attribute and error type is 0.
	}
}

void SemanticsVisitor::visit(Identifier& id) {
	id.setType(0); // init to error type. NOTICE by design, null attribute and error type is 0.
	try {
		Attributes* attributeRef = currentSymbolTable().retrieveSymbol(id.name());
		if (isDataObject(attributeRef)) {
			id.setAttributes(attributeRef);
		} else {
			errorLog() << id.name() << " does not name a data object.\n";
		}
	} catch (std::runtime_error& e) {
		errorLog() << id.name() << " has not been declared.\n";
	}
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

bool SemanticsVisitor::isDataObject(Attributes *attr) {
	if (dynamic_cast<VariableAttributes*>(attr) ||
		dynamic_cast<FieldAttributes*>(attr) )
		return true;
	return false;
}

bool SemanticsVisitor::assignable(TypeDescriptor *dest, TypeDescriptor *src) {
	/*
	 * dest is errorType : source is not assignable. (decided by LHSSemamticVisitor)
	 * src  is errorType : target is not a data object.
	 */
	if ( dest == 0 || src == 0 ) return false;
	/*
	 * Because C-- allow int and float convert to each other, and this can be done at code gen phase,
	 * so we do nothing for 'check compatibility' at this time.
	 */
	return true;
}






