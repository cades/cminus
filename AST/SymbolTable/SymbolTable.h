/*
 * SymbolTable.h
 *
 *  Created on: 2012/6/16
 *      Author: mac
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

class Attributes;
#include <string>
using std::string;
#include <map>
using std::map;
#include <vector>
using std::vector;

class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();
    void openScope();
    void closeScope();
    bool enterSymbol(const string& name, Attributes *attr);
    Attributes* retrieveSymbol(const string& name);
    bool declaredLocally(const string& name);
    void initializeForCminus();

public:
    typedef map<string, Attributes*> UnitSymtab;	// per scope symbol table
private:
	typedef vector<UnitSymtab> SymtabStack;
	SymtabStack symtabStack_;
	UnitSymtab& currentSymtab();
};

#endif /* SYMBOLTABLE_H_ */
