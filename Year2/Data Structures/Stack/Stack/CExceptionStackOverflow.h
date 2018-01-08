#pragma once
#include "CException.h"

class CExceptionStackOverflow : public CException {
public:
	CExceptionStackOverflow() : CException("Stack overflow") { }
};
