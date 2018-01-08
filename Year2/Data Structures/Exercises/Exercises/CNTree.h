#pragma once
#include "CTree.h"
#include "CNode.h"

class CNTree : public CTree
{
public:
	CNTree()
	{
		root = NULL;
	}

	CNTree(CNode* root)
		: root(root)
	{
	}

	virtual ~CNTree();

	//KLD
	void preorder() override;
	void preorder_branch(CNode* pBr);
	//DLK
	void inorder() override;
	void inorder_branch(CNode* pBr);
	//LDK
	void postorder() override;
	void postorder_branch(CNode* pBr);

	void save_to_file(char* filename) override;
	void load_from_file(char* filename) override;
private :
	CNode* root;
	void delete_branch(CNode*& pBr);
};
