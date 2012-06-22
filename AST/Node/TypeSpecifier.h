/*
 * TypeSpecifier.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef TYPESPECIFIER_H_
#define TYPESPECIFIER_H_

#include "AbstractNode.h"
class NodeVisitor;

class TypeSpecifier : public AbstractNode {
public:
	TypeSpecifier();
	virtual ~TypeSpecifier();
	virtual void accept(NodeVisitor& visitor);
};

#endif /* TYPESPECIFIER_H_ */
