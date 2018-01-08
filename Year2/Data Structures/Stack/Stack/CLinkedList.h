#pragma once

#include "CNode.h"

class CLinkedList
{
public:
	CLinkedList();
	~CLinkedList();

	CNode* m_pHead;

	void print(ostream& out) const;
	void append(CNode* pNewNode);
	void free_list();

	void delete_node(const int nPos);
	void insert_node(const int nPos, CNode* pNewNode);

	int read_from_file(char* file_name);
	int write_file(char* file_name) const;
};