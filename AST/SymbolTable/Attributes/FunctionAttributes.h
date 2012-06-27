/*
 * FunctionAttributes.h
 *
 *  Created on: 2012/6/23
 *      Author: mac
 */

#ifndef FUNCTIONATTRIBUTES_H_
#define FUNCTIONATTRIBUTES_H_

#include "Attributes.h"
#include "../TypeDescriptor/TypeDescriptor.h"
#include "../SymbolTable.h"
#include "../../Visitor/DeclarationProcessing/SemanticsVisitor.h"

class FunctionAttributes: public Attributes {
public:
	FunctionAttributes();
	virtual ~FunctionAttributes();

	virtual TypeDescriptor* getType() const { return getReturnType(); }
	virtual void setType(TypeDescriptor* td) { setReturnType(td); }

	TypeDescriptor* getReturnType() const { return returnType_; }
    void setReturnType(TypeDescriptor *returnType_) { this->returnType_ = returnType_; }
    SymbolTable* getLocals() { return &locals_; }
    SemanticsVisitor::TypeDescriptorList getSignature() const { return signature_; }
    void setSignature(SemanticsVisitor::TypeDescriptorList signature_) { this->signature_ = signature_; }

private:
	TypeDescriptor* returnType_;
	SymbolTable locals_;
	SemanticsVisitor::TypeDescriptorList signature_;
};

#endif /* FUNCTIONATTRIBUTES_H_ */
