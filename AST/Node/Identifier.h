/*
 * Identifier.h
 *
 *  Created on: 2012/6/11
 *      Author: mac
 */

#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include "AbstractNode.h"
#include <string>
using std::string;
class NodeVisitor;
class Attributes;
class TypeDescriptor;

class Identifier: public AbstractNode {
public:
	Identifier(const string&);
	virtual ~Identifier();
	virtual void accept(NodeVisitor& visitor);

	string name() { return name_; }
	Attributes* getAttributes() const { return attributesRef_; }
	void setAttributes(Attributes* attr);
	TypeDescriptor *getType() const { return type_; }
	void setType(TypeDescriptor *type_) { this->type_ = type_; }
private:
	string name_;
	Attributes* attributesRef_;
	TypeDescriptor* type_;
};

#endif /* IDENTIFIER_H_ */
