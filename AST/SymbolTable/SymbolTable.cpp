/*
 * SymbolTable.cpp
 *
 *  Created on: 2012/6/16
 *      Author: mac
 */

#include "SymbolTable.h"
#include "Attributes/Attributes.h"
#include <stdexcept>

SymbolTable::SymbolTable() {
	openScope();
}

SymbolTable::~SymbolTable() {
	while (!symtabStack_.empty())
		closeScope();
}

Attributes *SymbolTable::retrieveSymbol(const string & name)
{
	// search from outer-most scope to inner-most scope.
	for (SymtabStack::reverse_iterator i = symtabStack_.rbegin(); i != symtabStack_.rend(); ++i) {
		UnitSymtab& aSymtab = *i;
		UnitSymtab::iterator iter = aSymtab.find(name);
		if (iter != aSymtab.end())
			return iter->second;
	}

	// if reach here, means there're no such symbol in every scope.
	throw std::runtime_error("Symbol '" + name + "' not found: There're no such symbol in EVERY scope.");
}

bool SymbolTable::declaredLocally(const string & name)
{
	return currentSymtab().find(name) != currentSymtab().end();
}

bool SymbolTable::enterSymbol(const string & name, Attributes *attr)
{
	return currentSymtab().insert(
			UnitSymtab::value_type(name, attr) ).second;
}



/*
 * Infrastructure and utilities for convenient use, they are:
 * +openScope()     : void
 * 		push a new UnitSymtab.
 * +closeScope()    : void
 * 		cleanup current UnitSymtab and pop it.
 * 		This method release Attributes of symbols.
 * -currentSymtab() : UnitSymtab&
 * 		throw exception when symtab stack is empty, otherwise return reference of top of stack.
 */
void SymbolTable::openScope()
{
	symtabStack_.push_back(UnitSymtab());
}

void SymbolTable::closeScope()	// be responsible for release Attributes.
{
	for (UnitSymtab::iterator i = currentSymtab().begin(); i != currentSymtab().end(); ++i) {
		delete i->second;
	}
	symtabStack_.pop_back();
}

SymbolTable::UnitSymtab& SymbolTable::currentSymtab()
{
	if (symtabStack_.empty()) throw std::runtime_error("currentSymtab() called when Symbol Table is empty.");
	return symtabStack_.back();
}




