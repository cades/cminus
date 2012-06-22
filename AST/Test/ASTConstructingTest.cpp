/*
 * ASTConstructingTest.cpp
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#include "../Node/Identifier.h"
#include "../Node/IntLiteral.h"
#include "../Node/AssigningNode.h"
#include <iostream>

#include <CppUTest/TestHarness.h>

TEST_GROUP(ASTConstructing) {
};

TEST(ASTConstructing, canConstructAssignExpr) {
	/* assign_expr     : var_ref OP_ASSIGN relop_expr
		 *          +------------------------+
		 *          |      AssigningNode     |
		 *          +------------------------+
		 *          |           type         |
		 *          +------------------------+
		 *          | targetName | valueExpr |
		 *          +------------------------+
		 *              /               \
		 *          Name Subtree      Expr Subtree
		 *
		 * Here we use a simple example: Identifier Assigning IntLiteral
		 *                                   a         =          3       ;
		 */
		Identifier* id = new Identifier("a");
		IntLiteral* il = new IntLiteral(3);
		AssigningNode* an = new AssigningNode(id, il);

		delete id;
		delete il;
		delete an;
}
