/*
 * LHSSemanticsVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "LHSSemanticsVisitor.h"
#include <ostream>
#include "../../Node/Identifier.h"
#include "../../Node/ArrayReferencingNode.h"
#include "../../Node/StructReferencingNode.h"

#include "../../SymbolTable/Attributes/Attributes.h"
#include "../../SymbolTable/Attributes/VariableAttributes.h"
#include "../../SymbolTable/Attributes/FieldAttributes.h"
#include "../../SymbolTable/TypeDescriptor/StructTypeDescriptor.h"

LHSSemanticsVisitor::LHSSemanticsVisitor(SymbolTable* symtab, ostream& os) : SemanticsVisitor(symtab, os) {
	// TODO Auto-generated constructor stub

}

LHSSemanticsVisitor::~LHSSemanticsVisitor() {
	// TODO Auto-generated destructor stub
}

void LHSSemanticsVisitor::visit(Identifier& id) {
	SemanticsVisitor visitor(&currentSymbolTable(), errorLog());
	id.accept(visitor);
	if (!isAssignable(id.getAttributes())) {
		errorLog() << id.name() << " is not assignable.\n";
		id.setAttributes(0); // NOTICE by design, null attribute and error type is 0.
	}
}

void LHSSemanticsVisitor::visit(ArrayReferencingNode & ar) {
	ar.getVarRef()->accept(*this);
	SemanticsVisitor visitor(&currentSymbolTable(), errorLog());
	ar.accept(visitor);
}

void LHSSemanticsVisitor::visit(StructReferencingNode & sr) {
	SemanticsVisitor visitor(&currentSymbolTable(), errorLog());
	sr.accept(visitor);
	if (sr.getType() != 0) { // NOTICE using errorType
		sr.getVarRef()->accept(*this);
		if (StructTypeDescriptor* structTypeDesc = dynamic_cast<StructTypeDescriptor*>(sr.getVarRef()->getType())) {
			Attributes* attributeRef = structTypeDesc->getSymbolTable().retrieveSymbol(sr.getField()->name());
			if (!isAssignable(attributeRef))
				errorLog() << sr.getField()->name() << " is not an assignable field.\n";
		}
	}
}

bool LHSSemanticsVisitor::isAssignable(Attributes *attr) {
	if (dynamic_cast<VariableAttributes*>(attr) ||
			dynamic_cast<FieldAttributes*>(attr) )
		return true;
	return false;
}



