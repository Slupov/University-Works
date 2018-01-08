#include "CNode.h"

CNode::CNode()
{
	m_pNext = NULL;
};

CNode::CNode(CData in_data)
{
	m_data = in_data;
	m_pNext = NULL;
};