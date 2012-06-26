/*
 * BinaryExpressionTest.cpp
 *
 *  Created on: 2012/6/18
 *      Author: mac
 */

#include "../Node/PlusNode.h"
#include "../Node/IntLiteral.h"
#include "../Node/FloatLiteral.h"
#include "../Node/Identifier.h"
#include "../Node/Factor.h"
#include <stdexcept>

#include <CppUTest/TestHarness.h>

TEST_GROUP(BinaryExpressionShouldBeAbleTo) {
	Literal *int3, *int5, *float3, *float7;
	Expression* intExpr, *floatExpr, *mixedExpr;

	void setup() {
		int3 = new IntLiteral(3);
		int5 = new IntLiteral(5);
		intExpr = new PlusNode(int3, int5);

		float3 = new FloatLiteral(3.0);
		float7 = new FloatLiteral(7.1);
		floatExpr = new PlusNode(float3, float7);
		mixedExpr = new PlusNode(float3, int5);
	}

	void teardown() {
		delete intExpr;
		delete floatExpr;
		delete mixedExpr;
		delete int3;
		delete int5;
		delete float3;
		delete float7;
	}
};

TEST(BinaryExpressionShouldBeAbleTo, handleEasyCase_1) {
	Literal* l = new IntLiteral(3);
	IntLiteral* iLit = dynamic_cast<IntLiteral*>( l->evaluate() );
	LONGS_EQUAL(3, iLit->getValue());
	delete iLit;
	delete l;
}

TEST(BinaryExpressionShouldBeAbleTo, handleEasyCase_2) {
	Literal* l = new FloatLiteral(3.0);
	FloatLiteral* fLit = dynamic_cast<FloatLiteral*>( l->evaluate() );
	DOUBLES_EQUAL(3.0, fLit->getValue(), 100);
	delete fLit;
	delete l;
}

TEST(BinaryExpressionShouldBeAbleTo, handleBinaryOperationWith2Ints) {
	IntLiteral* lit = dynamic_cast<IntLiteral*>( intExpr->evaluate() );
	LONGS_EQUAL(8, lit->getValue());
	delete lit;
}

TEST(BinaryExpressionShouldBeAbleTo, handleBinaryOperationWith2Floats) {
	FloatLiteral* lit = dynamic_cast<FloatLiteral*>( floatExpr->evaluate() );
	DOUBLES_EQUAL(10.1, lit->getValue(), 100);
	delete lit;
}

TEST(BinaryExpressionShouldBeAbleTo, handleBinaryOperationWith_IntFloatMixed) {
	FloatLiteral* lit = dynamic_cast<FloatLiteral*>( mixedExpr->evaluate() );
	DOUBLES_EQUAL(8.0, lit->getValue(), 100);
	delete lit;
}

TEST(BinaryExpressionShouldBeAbleTo, handleBinaryOperationWith_IntFloatMixed_2) {
	Literal* l = new FloatLiteral(3.2);
	Expression* expr = new PlusNode(mixedExpr, l);
	FloatLiteral* lit = dynamic_cast<FloatLiteral*>( expr->evaluate() );
	DOUBLES_EQUAL(11.2, lit->getValue(), 10);
	delete l;
	delete expr;
	delete lit;
}
/*
TEST(BinaryExpressionShouldBeAbleTo, handleIlligalCase) {
	Identifier* id = new Identifier("variable");
	Factor* factor = new Factor(id);
	Expression* expr = new PlusNode(factor, int3);
	try {
		IntLiteral* lit = dynamic_cast<IntLiteral*>( expr->evaluate() );
	} catch (std::exception& e) {
		STRCMP_EQUAL("Cannot evaluate constant.", string(e.what()).substr(0, 25).c_str());
	}
	delete id;
	delete expr;
}

TEST(BinaryExpressionShouldBeAbleTo, handleIlligalCase_2) {
	Identifier* id = new Identifier("variable");
	Factor* factor = new Factor(id);
	Expression* expr = new PlusNode(intExpr, factor);
	try {
		IntLiteral* lit = dynamic_cast<IntLiteral*>( expr->evaluate() );
	} catch (std::exception& e) {
		STRCMP_EQUAL("Cannot evaluate constant.", string(e.what()).substr(0, 25).c_str());
	}
	delete id;
	delete expr;
}
*/
