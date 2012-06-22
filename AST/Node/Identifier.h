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
class TypeAttributes;

class Identifier: public AbstractNode {
public:
	Identifier(const string&);
	virtual ~Identifier();
	virtual void accept(NodeVisitor& visitor);
	string name() { return name_; }
	void setType(TypeAttributes*);
private:
	string name_;
	TypeAttributes* type_;
};

#endif /* IDENTIFIER_H_ */
