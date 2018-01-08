#pragma once
#include "CException.h"

class CExceptionStackEmpty : public CException
{
public:
	CExceptionStackEmpty() : CException("Stack empty")
	{
	}
};
