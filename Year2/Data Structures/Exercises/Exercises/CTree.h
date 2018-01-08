#pragma once

class CTree
{
public:
	CTree() {  }
	virtual ~CTree() = default;
	virtual void preorder() = 0;
	virtual void inorder() = 0;
	virtual void postorder() = 0;

	virtual void save_to_file(char* filename) = 0;
	virtual void load_from_file(char* filename) = 0;
};
