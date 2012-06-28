/*
 * MIPSCodeGenVisitor.cpp
 *
 *  Created on: 2012/6/28
 *      Author: mac
 */

#include "MIPSCodeGenVisitor.h"

MIPSCodeGenVisitor::MIPSCodeGenVisitor(SymbolTable* symtab, ostream& os, ostream& codestream)
: NodeVisitor(symtab, os), codeOutputStream_(codestream) {
	// TODO Auto-generated constructor stub

}

MIPSCodeGenVisitor::~MIPSCodeGenVisitor() {
	// TODO Auto-generated destructor stub
}
