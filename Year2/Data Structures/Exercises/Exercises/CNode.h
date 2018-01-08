#pragma once
#include <cstddef>

class CData
{
public:
	CData()
	{
		m_Value = MIN_INT;
	}

	CData(int val)
	{
		m_Value = val;
	}

	int m_Value;
};

class CNode
{
public:
	CNode()
	{
		m_left = NULL;
		m_right = NULL;
	}

	CNode(CData data)
	{
		m_data = data;
		m_left = NULL;
		m_right = NULL;
	}

	~CNode()
	{
	}
	
	friend class CNTree;
private:
	CData m_data;
	CNode* m_left;
	CNode* m_right;
};
