#include "CStack.h"
#include "CLinkedList.h"
#include <iostream>
using namespace std;

CStack::CStack(int cap)
{
	m_nCap = cap;
	m_nCount = 0;
}

CStack::CStack()
{
	m_nCap = STACK_MAX_CAP;
	m_nCount = 0;
}

void CStack::push(CNode* pNewNode) throw (CExceptionStackOverflow)
{
	if (m_nCount < m_nCap)
	{
		CLinkedList::insert_node(0, pNewNode);
		m_nCount++;
	}
	else
	{
		throw CExceptionStackOverflow();
	}
}

CNode* CStack::pop() throw (CExceptionStackEmpty)
{
	if (m_nCount < 1 || m_pHead == NULL)
	{
		throw CExceptionStackEmpty();
	}

	CNode* pFirst = m_pHead;
	m_pHead = m_pHead->m_pNext;
	pFirst->m_pNext = NULL;
	m_nCount--;

	return pFirst;
}

void CStack::trace() const
{
	print(cout);
}

int CStack::read_from_file_to_stack(char* file_name)
{
	return CLinkedList::read_from_file(file_name);
}

int CStack::write_file_from_stack(char* file_name) const
{
	return CLinkedList::write_file(file_name);
};
