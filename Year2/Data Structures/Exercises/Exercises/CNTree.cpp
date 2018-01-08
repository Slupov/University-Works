#include "CNTree.h"
#include <iostream>

CNTree::~CNTree()
{
	delete_branch(root);
}

inline void CNTree::preorder()
{
	preorder_branch(root);
}

void CNTree::preorder_branch(CNode* pBr)
{
	if (NULL == pBr)
	{
		return;
	}
	std::cout << pBr->m_data.m_Value;
	preorder_branch(pBr->m_left);
	preorder_branch(pBr->m_right);
	std::cout << std::endl;
}

inline void CNTree::inorder()
{
	CNTree::inorder_branch(root);
}

void CNTree::inorder_branch(CNode* pBr)
{
	if (NULL == pBr)
	{
		return;
	}

	inorder_branch(pBr->m_left);
	std::cout << pBr->m_data.m_Value;
	inorder_branch(pBr->m_right);
	std::cout << std::endl;
}

inline void CNTree::postorder()
{
	postorder_branch(root);
}

void CNTree::postorder_branch(CNode* pBr)
{
	if (NULL == pBr)
	{
		return;
	}

	postorder_branch(pBr->m_left);
	postorder_branch(pBr->m_right);
	std::cout << pBr->m_data.m_Value;

	std::cout << std::endl;
}

inline void CNTree::save_to_file(char* filename)
{
//	data
//	data
//	data
//	data
//
//
//
//	data
//	data
//	data
//
//	data

//	or

//	1.data
//	2.data
//	3.data
//	4.data
//	8.data
//	9.data
//	10.data
//	12.data
}

inline void CNTree::load_from_file(char* filename)
{
}

void CNTree::delete_branch(CNode*& pBr)
{
	if (NULL != pBr->m_left)
	{
		delete_branch(pBr->m_left);
	}

	if (NULL != pBr->m_right)
	{
		delete_branch(pBr->m_right);
	}

	delete pBr;
	pBr = NULL;
}
