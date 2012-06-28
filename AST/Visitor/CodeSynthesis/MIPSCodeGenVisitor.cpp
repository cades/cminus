/*
 * MIPSCodeGenVisitor.cpp
 *
 *  Created on: 2012/6/28
 *      Author: mac
 */

#include "MIPSCodeGenVisitor.h"
#include "../../Node/CallingNode.h"

MIPSCodeGenVisitor::MIPSCodeGenVisitor(SymbolTable* symtab, ostream& os, ostream& codestream)
: NodeVisitor(symtab, os), codeOutputStream_(codestream) {
	// TODO Auto-generated constructor stub

}

MIPSCodeGenVisitor::~MIPSCodeGenVisitor() {
	// TODO Auto-generated destructor stub
}

void MIPSCodeGenVisitor::visit(CallingNode& node) {
	gen_prologue(node.getFunctionName()->name());
	// TODO Not finish yet
}

void MIPSCodeGenVisitor::gen_prologue(string name)
{
  codeStream() << "\n# Prologue\n";

  codeStream() << "\t sw $ra, 0($sp) \n";
  codeStream() << "\t sw $fp, -4($sp) \n";
  codeStream() << "\t add $fp, $sp, -4\n";
  codeStream() << "\t add $sp, $sp, -8\n";
  codeStream() << "\t lw $2, _framesize_" << name << "\n";
  codeStream() << "\t sub $sp, $sp, $2\n";

  codeStream() << "\t sw $8, 72($sp) \n";
  codeStream() << "\t sw $9, 68($sp) \n";
  codeStream() << "\t sw $10, 64($sp) \n";
  codeStream() << "\t sw $11, 60($sp) \n";
  codeStream() << "\t sw $12, 56($sp) \n";
  codeStream() << "\t sw $13, 52($sp) \n";
  codeStream() << "\t sw $14, 48($sp) \n";
  codeStream() << "\t sw $15, 44($sp) \n";
  codeStream() << "\t sw $16, 40($sp) \n";
  codeStream() << "\t sw $17, 36($sp) \n";
  codeStream() << "\t sw $18, 32($sp) \n";
  codeStream() << "\t sw $19, 28($sp) \n";
  codeStream() << "\t sw $20, 24($sp) \n";
  codeStream() << "\t sw $21, 20($sp) \n";
  codeStream() << "\t sw $22, 16($sp) \n";
  codeStream() << "\t sw $23, 12($sp) \n";
  codeStream() << "\t sw $24, 8($sp) \n";
  codeStream() << "\t sw $25, 4($sp) \n";

  codeStream() << "_begin_" << name << ": \n";

}

void MIPSCodeGenVisitor::gen_epilogue(string name)
{

  codeStream() << "\n# Epilogue\n";

  codeStream() << "_end_" << name << ": \n";


  codeStream() << "\t lw $8, 72($sp) \n";
  codeStream() << "\t lw $9, 68($sp) \n";
  codeStream() << "\t lw $10, 64($sp) \n";
  codeStream() << "\t lw $11, 60($sp) \n";
  codeStream() << "\t lw $12, 56($sp) \n";
  codeStream() << "\t lw $13, 52($sp) \n";
  codeStream() << "\t lw $14, 48($sp) \n";
  codeStream() << "\t lw $15, 44($sp) \n";
  codeStream() << "\t lw $16, 40($sp) \n";
  codeStream() << "\t lw $17, 36($sp) \n";
  codeStream() << "\t lw $18, 32($sp) \n";
  codeStream() << "\t lw $19, 28($sp) \n";
  codeStream() << "\t lw $20, 24($sp) \n";
  codeStream() << "\t lw $21, 20($sp) \n";
  codeStream() << "\t lw $22, 16($sp) \n";
  codeStream() << "\t lw $23, 12($sp) \n";
  codeStream() << "\t lw $24, 8($sp) \n";
  codeStream() << "\t lw $25, 4($sp) \n";

  codeStream() << "\t lw $ra, 4($fp) \n";
  codeStream() << "\t add $sp, $fp, 4 \n";
  codeStream() << "\t lw $fp, 0($fp) \n";
  if( name == "main" )
    {
      codeStream() << "\t li $v0, 10\n";
      codeStream() << "\t syscall \n";
    }
  else
    codeStream() << "\t jr $ra \n";
  codeStream() << ".data \n";
  codeStream() << "_framesize_" << name << " : .word " << /*72-ARoffset-4 << */" \n"; /* -4 as we change ARoffset each time AFTER putting it in symbol                                                               table */
  // FIXME ARoffset calculation

}
