#pragma once

#include "CNode.h"
#include "CLinkedList.h"
#include "CExceptionStackOverflow.h"
#include "CExceptionStackEmpty.h"
using namespace std;

#define STACK_MAX_CAP 256

class CStack : private CLinkedList
{
public:
	CStack();
	CStack(int cap);

	void push(CNode* pNewNode) throw (CExceptionStackOverflow);
	CNode* pop() throw (CExceptionStackEmpty);
	void trace() const;

	int read_from_file_to_stack(char* file_name);
	int write_file_from_stack(char* file_name) const;

private:
	int m_nCap;
	int m_nCount;
};
