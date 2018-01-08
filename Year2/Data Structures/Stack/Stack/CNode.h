#pragma once
#include "CData.h"

class CNode
{
public:
	CNode();
	CNode(CData in_data);

	CData m_data;
	CNode* m_pNext;
};
