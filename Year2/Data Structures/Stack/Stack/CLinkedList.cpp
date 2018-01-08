#include "CLinkedList.h"
#include <fstream>
using namespace std;

CLinkedList::CLinkedList()
{
	m_pHead = NULL;
}

CLinkedList::~CLinkedList()
{
	free_list();
}

inline void CLinkedList::print(ostream& out) const
{
	CNode* pList = m_pHead;
	while (NULL != pList)
	{
		out << pList->m_data << endl;
		pList = pList->m_pNext;
	}
	out << endl;
}

inline void CLinkedList::append(CNode* pNewNode)
{
	if (NULL == m_pHead)
	{
		m_pHead = pNewNode;
		m_pHead->m_pNext = NULL;
	}
	else
	{
		CNode* pList = m_pHead;
		while (NULL != pList->m_pNext)
		{
			pList = pList->m_pNext;
		}
		pList->m_pNext = pNewNode;
		pList->m_pNext->m_pNext = NULL;
	}
}

inline void CLinkedList::free_list()
{
	CNode* pList = m_pHead;

	while (NULL != pList)
	{
		CNode* pN = pList->m_pNext;
		delete pList;
		pList = pN;
	}

	m_pHead = NULL;
}

inline void CLinkedList::delete_node(const int nPos)
{
	if (NULL == m_pHead)
	{
		return;
	}

	if ((0 == nPos) && (NULL != m_pHead))
	{
		CNode* pN = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete pN;
	}
	else
	{
		CNode* pList = m_pHead;
		int i = 0;
		while ((NULL != pList->m_pNext) && (i < nPos - 1))
		{
			i++;
			pList = pList->m_pNext;
		}

		if ((i == nPos - 1) && (NULL != pList->m_pNext))
		{
			CNode* pN = pList->m_pNext;
			pList->m_pNext = pList->m_pNext->m_pNext;
			delete pN;
		}
	}
}

inline void CLinkedList::insert_node(int nPos, CNode* pNewNode)
{
	if (NULL == m_pHead && 0 == nPos)
	{
		append(pNewNode);
	}

	if ((0 == nPos) && (NULL != m_pHead))
	{
		CNode* pN = pNewNode;
		pN->m_pNext = m_pHead;
		m_pHead = pN;
	}
	else
	{
		CNode* pList = m_pHead;
		int i = 0;
		while ((NULL != pList->m_pNext) && (i < nPos - 1))
		{
			i++;
			pList = pList->m_pNext;
		}

		CNode* pN = pNewNode;
		pN->m_pNext = pList->m_pNext;
		pList->m_pNext = pN;
	}
}

inline int CLinkedList::read_from_file(char* file_name)
{
	ifstream in_file;
	in_file.open(file_name);
	if (in_file.fail())
	{
		return -1;
	}

	CData data;
	CNode* pNewNode = NULL;

	while (!in_file.eof())
	{
		in_file >> data;
		pNewNode = new CNode(data);
		append(pNewNode);
	}

	in_file.close();
	return 0;
}

inline int CLinkedList::write_file(char* file_name) const
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.fail())
	{
		return -1;
	}

	print(out_file);
	out_file.close();
	return 0;
}
