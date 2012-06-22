/*
 * StringLiteral.h
 *
 *  Created on: 2012/6/12
 *      Author: mac
 */

#ifndef STRINGLITERAL_H_
#define STRINGLITERAL_H_

#include "AbstractNode.h"
#include <string>
using std::string;
class NodeVisitor;

class StringLiteral: public AbstractNode {
public:
	StringLiteral(const string&);
	virtual ~StringLiteral();
	virtual void accept(NodeVisitor& visitor);
private:
	string data_;
};

#endif /* STRINGLITERAL_H_ */
