/*
 * Identifier.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include "Expression.h"
#include <string>
using std::string;
class NodeVisitor;
class Attributes;
class TypeDescriptor;

class Identifier: public Expression {
public:
	Identifier(const string&);
	virtual ~Identifier();
	virtual void accept(NodeVisitor& visitor);
	virtual Literal* evaluate();

	string name() const { return name_; }
	Attributes* getAttributes() const { return attributesRef_; }
	void setAttributes(Attributes* attr);
private:
	string name_;
	Attributes* attributesRef_;
};

#endif /* IDENTIFIER_H_ */
