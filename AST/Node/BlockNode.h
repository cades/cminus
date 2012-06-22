/*
 * BlockNode.h
 *
 *  Created on: 2012/6/13
 *      Author: mac
 */

#ifndef BLOCKNODE_H_
#define BLOCKNODE_H_

#include "AbstractNode.h"
class NodeList;
class NodeVisitor;

class BlockNode: public AbstractNode {
public:
	BlockNode(NodeList* list);
	virtual ~BlockNode();
	virtual void accept(NodeVisitor& visitor);
private:
	NodeList* delc_stmt_list_;
};

#endif /* BLOCKNODE_H_ */
