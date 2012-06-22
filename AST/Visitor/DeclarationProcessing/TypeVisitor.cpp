/*
 * TypeVisitor.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "TypeVisitor.h"
#include <ostream>
#include <cassert>
#include <stdexcept>
#include <typeinfo>
#include "../../SymbolTable/Attributes/Attributes.h"
#include "../../SymbolTable/Attributes/TypeAttributes.h"
#include "../../SymbolTable/Attributes/FieldAttributes.h"
#include "../../SymbolTable/TypeDescriptor/ArrayTypeDescriptor.h"
#include "../../SymbolTable/TypeDescriptor/StructTypeDescriptor.h"
#include "../../SymbolTable/SymbolTable.h"

#include "../../Node/Identifier.h"			// because I have to know the inheritance relationship.
#include "../../Node/ArrayDefiningNode.h"	// because I have to know the inheritance relationship.
#include "../../Node/StructDefiningNode.h"

#include "../../Node/Expression.h"
#include "../../Node/IntLiteral.h"
#include "../../Node/IdentifierList.h"

TypeVisitor::TypeVisitor(SymbolTable* symtab, ostream& os) : TopDeclVisitor(symtab, os) , originalSymtab_(symtab) {
	// TODO Auto-generated constructor stub

}

TypeVisitor::~TypeVisitor() {
	// TODO Auto-generated destructor stub
}

void TypeVisitor::visit(Identifier & id) {
	try {
		Attributes* attr = currentSymbolTable().retrieveSymbol(id.name());
		if (TypeAttributes* typeAttr = dynamic_cast<TypeAttributes*>(attr)) {
			id.setType(typeAttr);
		} else {	// symbol found, but not a type name
			os_ << "This identifier '" + id.name() + "' is not a type name. \n";
			id.setType(0);	// NOTICE by design, null attribute and error type is 0.
		}
	} catch (std::runtime_error& e) { // symbol not found
		assert (e.what() == "Symbol '" + id.name() + "' not found: There're no such symbol in EVERY scope.");
		os_ << "Type name '" + id.name() + "' not found. \n";
		id.setType(0);		// NOTICE by design, null attribute and error type is 0.
	}
}

void TypeVisitor::visit(ArrayDefiningNode& arrayDef) {
	/*
	 * Things todo:
	 * 1. evaluate size expression and type expression.
	 * 2. check whether size expression's value is of type IntLiteral. If not, issue error.
	 * 3. Allocate TypeDescriptor for arrayDef, and setup its type and bounds.
	 *
	 * pseudo code @ page.343
	 * call visitChildren(arraydef)
	 * arraydef.type <- new TypeDescriptor(arrayType)
	 * arraydef.type.elementType <- arraydef.elementType.type
	 * arraydef.type.bounds <- arraydef.size.value
	 *
	 */
	visitChildren(arrayDef);
	try {
		if ( IntLiteral* lit = dynamic_cast<IntLiteral*>( arrayDef.getSizeExpr()->evaluate() ) ) {
			ArrayTypeDescriptor* atd = new ArrayTypeDescriptor;
			if (Identifier* id = dynamic_cast<Identifier*>(arrayDef.getElementType())) { // named type. lookup in symtab now!
				try {
					Attributes* attr = currentSymbolTable().retrieveSymbol(id->name());
					if (TypeAttributes* typeAttr = dynamic_cast<TypeAttributes*>(attr)) { // success case 1
						atd->setElementType(typeAttr->type());
						atd->setBounds(lit->getValue());
						arrayDef.setType(atd);
					} else {
						os_ << "'" << id->name() << "' is NOT type name.\n";
						arrayDef.setType(0);	// NOTICE by design, null attribute and error type is 0.
					}
				} catch (std::runtime_error& e) {
					os_ << e.what() << "\n";
					arrayDef.setType(0);		// NOTICE by design, null attribute and error type is 0.
				}
			} else {	// array of array. success case 2
				ArrayTypeDescriptor* atd = new ArrayTypeDescriptor;
				assert(dynamic_cast<ArrayDefiningNode*>(arrayDef.getElementType())); // FIXME This cast MUST pass!!
				ArrayDefiningNode* node = static_cast<ArrayDefiningNode*>(arrayDef.getElementType());
				atd->setElementType(node->getType());
				atd->setBounds(lit->getValue());
				arrayDef.setType(atd);
			}
			delete lit;
			return;
		} else { // size is float
			os_ << "Array index cannot be float type. Plz fix to int.\n";
		}
	} catch (std::runtime_error& e) { // catch exception thrown from evaluate()
		// size cannot be computed.
		os_ << "Array index cannot be computed : " << e.what() << "\n";
	}
}

void TypeVisitor::visit(StructDefiningNode & structDef) {
	/*
	 * pseudo code @ page.345
	 * typeRef <- new TypeDescriptor(structType)
	 * typeRef.fields <- new SymbolTable()
	 * foreach decl (- structDef.fieldList do
	 * 		call decl.fieldType.accept(this)
	 * 		foreach id (- decl.idList do
	 * 			if typeRef.fields.declaredLocally(id.name)
	 * 			then
	 * 				call ERROR("Name cannot be redeclared :", id.name)
	 * 				id.type <- errorType
	 * 				id.attributesRef <- null
	 * 			else
	 * 				attr.kind <- fieldAttributes
	 * 				attr.fieldType <- decl.fieldType.type
	 * 				call typeRef.fields.enterSymbol(id.name, attr)
	 * 				id.type <- decl.fieldType.type
	 * 				id.attributesRef <- attr
	 * 	structdef.type <- typeRef
	 *
	 */
	StructTypeDescriptor* typeRef = new StructTypeDescriptor;

	StructDefiningNode::Iterator* declIter = structDef.createIterator();
	for (declIter->First(); !declIter->IsDone(); declIter->Next()) {	// iterate through each field declaration
		// declIter->CurrentItem() is VariableListDeclaringNode
		//declIter->CurrentItem()->XXXXXX->accept(*this);

		/* FIXME This is bad. It may fail at run-time. But I don't want to add try catch block.
		 * So far I just can use assert(dynamic_cast) + static_cast to make it compile. Have to overcome it at compile time.
		 * I need to use Identifier.name(), which is not in AbstractNode's public interface.
		 */
		assert(dynamic_cast<IdentifierList::Iterator*>(declIter->CurrentItem()->createIterator()));
		IdentifierList::Iterator* idIter = static_cast<IdentifierList::Iterator*>(
				declIter->CurrentItem()->createIterator());
		for (idIter->First(); idIter->IsDone(); idIter->Next()) { // iterate through every id
			if (typeRef->getSymbolTable().declaredLocally(idIter->CurrentItem()->name())) {
				os_ << "Name cannot be redeclared :" << idIter->CurrentItem()->name() << "\n";
				idIter->CurrentItem()->setType(0); // NOTICE by design, null attribute and error type is 0.
			} else {
				FieldAttributes* attr = new FieldAttributes;
				//attr->setType()
			}
		}
	}
}

void TypeVisitor::setSymbolTableTo(SymbolTable& newSymtab)
{
	symtab_ = &newSymtab;
}



void TypeVisitor::setSymbolTableBack()
{
	symtab_ = originalSymtab_;
}



