/*
 * SemanticsVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "SemanticsVisitor.h"
#include "LHSSemanticsVisitor.h"
#include <ostream>
#include <stdexcept>
#include "../../Node/Identifier.h"
#include "../../Node/IntLiteral.h"
#include "../../Node/FloatLiteral.h"
#include "../../Node/BinaryExpression.h"
#include "../../Node/UnaryExpression.h"
#include "../../Node/RelationalExpression.h"
#include "../../Node/AssigningNode.h"
#include "../../Node/ArrayReferencingNode.h"
#include "../../Node/StructReferencingNode.h"
#include "../../Node/ReturningNode.h"
#include "../../Node/FunctionDeclaringNode.h"

#include "../../Node/IfTestingNode.h"
#include "../../Node/ForLoopingNode.h"
#include "../../Node/WhileLoopingNode.h"
#include "../../Node/CallingNode.h"

#include "../../SymbolTable/SymbolTable.h"
#include "../../SymbolTable/Attributes/Attributes.h"
#include "../../SymbolTable/Attributes/VariableAttributes.h"
#include "../../SymbolTable/Attributes/FieldAttributes.h"
#include "../../SymbolTable/Attributes/FunctionAttributes.h"
#include "../../SymbolTable/TypeDescriptor/IntegerTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/FloatTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/ArrayTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/StructTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/VoidTypeDescriptor.h"


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


void SemanticsVisitor::visit(ArrayReferencingNode& ar) {
	visitChildren(ar);
	if (ar.getVarRef()->getType() == 0) { // NOTICE use errorType
		ar.setType(0); // NOTICE by design, null attribute and error type is 0.
	} else {
		if (dynamic_cast<ArrayTypeDescriptor*>(ar.getVarRef()->getType()) ) {
			ar.setType(ar.getVarRef()->getType());
		} else {
			errorLog() << &ar << " is not an array.\n";
			ar.setType(0); // NOTICE by design, null attribute and error type is 0.
		}
	}
	if (ar.getDimExpr()->getType() == 0) // NOTICE use errorType
		errorLog() << "Index expression error.\n";
	if ( !dynamic_cast<IntegerTypeDescriptor*>(ar.getDimExpr()->getType()) )
		errorLog() << "Index expression is not an integer.\n";
}

void SemanticsVisitor::visit(StructReferencingNode& sr) {
	sr.getVarRef()->accept(*this);
	if (sr.getVarRef()->getType() == 0) { // NOTICE use errorType
		sr.setType(0); // NOTICE by design, null attribute and error type is 0.
	} else {
		if (StructTypeDescriptor* structTypeDesc = dynamic_cast<StructTypeDescriptor*>(sr.getVarRef()->getType())) {
			try {
				Attributes* attributeRef =
						structTypeDesc->getSymbolTable().retrieveSymbol(
								sr.getField()->name());
				sr.setType(attributeRef->getType());
			} catch (std::runtime_error& e) {
				errorLog() << sr.getField()->name() << " is not a field of " << typeid(sr.getVarRef()).name() << "\n";
				sr.setType(0); // NOTICE by design, null attribute and error type is 0.
			}
		} else {
			errorLog() << sr.getVarRef() << " does not name a struct.\n";
			sr.setType(0); // NOTICE by design, null attribute and error type is 0.
		}
	}
}

void SemanticsVisitor::visit(CallingNode& cn) {
	cn.getFunctionName()->accept(*this);
	try {
		if (FunctionAttributes* attr =
				dynamic_cast<FunctionAttributes*>(
						currentSymbolTable().retrieveSymbol(cn.getFunctionName()->name()))) {
			if (applicable(
					attr->getSignature(),
					getArgTypes(cn.getArgList()))) {

			} else {
				errorLog() << "Provided parameter not applicable. Expected: " << cn.getFunctionName()->name() << "\n"; // TODO expected...print signature
				cn.setType(0); // NOTICE by design, null attribute and error type is 0.
			}
		} else {
			errorLog() << cn.getFunctionName()->name() << " is not a function name.\n";
			cn.setType(0); // NOTICE by design, null attribute and error type is 0.
		}
	} catch (std::runtime_error& e) {
		errorLog() << "Function " << cn.getFunctionName()->name() << " undeclared.\n";
		cn.setType(0); // NOTICE by design, null attribute and error type is 0.
	}
}


/* semantic analysis phase
 * here we care 4 kind of nodes: if, for, while, return
 */

void SemanticsVisitor::visit(IfTestingNode& ifn) {
	visitChildren(ifn);
	checkBoolean(ifn.getCondition());
}

void SemanticsVisitor::visit(ForLoopingNode& fn) {
	currentSymbolTable().openScope();
	visitChildren(fn);  // FIXME should I use TopDeclVisitor here ???
	checkBoolean(fn.getCondition());
	currentSymbolTable().closeScope();
}

void SemanticsVisitor::visit(WhileLoopingNode& wn) {
	visitChildren(wn);
	checkBoolean(wn.getCondition());
}

void SemanticsVisitor::visit(ReturningNode& rn) {
	if (rn.getReturnVal() != 0) { // NOTICE use errorType
		rn.getReturnVal()->accept(*this); // the same as visitChildren
		if (getCurrentFunction() == 0)
			errorLog() << "Return statement can only appear in a function.\n";
		else {
			if(!assignable(getCurrentFunction()->getReturnType()->getType(),
					rn.getReturnVal()->getType())) {
				errorLog() << "Illigal return type.\n";
			}
		}
	} else if (getCurrentFunction() != 0 &&
			!dynamic_cast<VoidTypeDescriptor*>(getCurrentFunction()->getReturnType()->getType()) // return type =/= void
			) {
		errorLog() << "A value must be returned.\n";
	}
}



// utility methods

bool SemanticsVisitor::isDataObject(Attributes *attr) {
	if (dynamic_cast<VariableAttributes*>(attr) ||
			dynamic_cast<FieldAttributes*>(attr) ||
			dynamic_cast<FunctionAttributes*>(attr) )
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

SemanticsVisitor::TypeDescriptorList SemanticsVisitor::getArgTypes(ExpressionList* argList) {
	// collect TypeDescriptors.
	TypeDescriptorList res;
	ExpressionList::Iterator* i = argList->createIterator();
	foreach_element(i) {
		res.push_back(i->CurrentItem()->getType());
	}
	delete i;
	return res;
}

bool SemanticsVisitor::applicable(TypeDescriptorList formalParams, TypeDescriptorList actualParams) {
	if (formalParams.size() == 0 && actualParams.size() == 0) return true;
	else if (formalParams.size() == 0 || actualParams.size() == 0) return false;
	else {
		if (bindable(formalParams.front(), actualParams.front()))
			return applicable(
					TypeDescriptorList(++formalParams.begin(), formalParams.end()),
					TypeDescriptorList(++actualParams.begin(), actualParams.end())
			);
		return false;
	}
}

bool SemanticsVisitor::bindable(TypeDescriptor *dest, TypeDescriptor *src) {
	return assignable(dest, src); // TODO check array type
}

void SemanticsVisitor::checkBoolean(ExpressionList *exprList) {
	if (exprList->length() == 0) // infinite loop.
		return;

	// get head of list.
	ExpressionList::Iterator* i = exprList->createIterator();
	i->First();
	Expression& c = *i->CurrentItem();
	delete i;

	if (c.getType() != 0 &&
			(dynamic_cast<IntegerTypeDescriptor*>(c.getType()) ||
			dynamic_cast<FloatTypeDescriptor*>(c.getType()) )
			) {
		errorLog() << "Require boolean type at " << &c << "\n";
	}
}








