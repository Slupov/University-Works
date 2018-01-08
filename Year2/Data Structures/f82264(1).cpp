//stoyan lupov - f82264
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

class CException
{
public:
	CException()
	{
		m_err = "Some error";
	}

	CException(string err)
	{
		m_err = err;
	}

	string getErr() { return m_err; };
private:
	string m_err;
};

class CExceptionStackOverflow : public CException
{
public:
	CExceptionStackOverflow() : CException("Stack overflow exception")
	{
	};
};

class CExceptionEmptyStack : public CException
{
public:
	CExceptionEmptyStack() : CException("Stack empty exception")
	{
	};
};

#define MSTACK_MAX_CAP 12
//#define DEBUG

class CStack
{
public:
	CStack()
	{
	};

	virtual ~CStack()
	{
	};

	virtual void push(int* element) throw (CExceptionStackOverflow) = 0;
	virtual int* pop() throw (CExceptionEmptyStack) = 0;
	virtual void trace() const = 0;

	virtual int write_file_from_stack(char* file_name) = 0;
	virtual int read_from_file_to_stack(char* file_name) = 0;
};

class MStack : public CStack
{
public:
	MStack() : m_nSize(0)
	{
		m_nCap = MSTACK_MAX_CAP;
		m_pElements = new int*[m_nCap];
	}

	MStack(int cap) : m_nSize(0)
	{
		if (cap <= 0)
		{
			cap = MSTACK_MAX_CAP;
		}

		m_nCap = min(MSTACK_MAX_CAP, cap);
		m_pElements = new int*[cap];
	}

	~MStack();
	void push(int* element) throw(CExceptionStackOverflow) override;
	int* pop() throw(CExceptionEmptyStack) override;
	void trace() const override;

	int write_file_from_stack(char* file_name) override;
	int read_from_file_to_stack(char* file_name) override;

private:
	int m_nSize; //shows the current size of the stack
	int m_nCap; //shows the max capacity of the stack
	int** m_pElements; //[bottom]...[k]....[top]
};

MStack::~MStack()
{
	for (int i = 0; i < m_nSize; i++)
	{
#ifdef DEBUG
		cout << "deleting" << *m_pElements[i] << endl; //debug
#endif
		delete m_pElements[i];
	}
}

void MStack::push(int* element) throw(CExceptionStackOverflow)
{
	if (m_nSize >= m_nCap)
	{
		throw CExceptionStackOverflow();
	}

	m_pElements[m_nSize++] = element;
}

int* MStack::pop() throw(CExceptionEmptyStack)
{
	if (m_nSize == 0)
	{
		throw CExceptionEmptyStack();
	}

	m_nSize--;

	int* toReturn = new int(*m_pElements[m_nSize]);
	delete m_pElements[m_nSize];


#ifdef DEBUG
	cout << "deleting" << *toReturn << endl; //debug
#endif

	return toReturn;
}

void MStack::trace() const
{
	cout << "Stack trace:" << endl;

	for (int i = m_nSize - 1; i >= 0; i--)
	{
		cout << *m_pElements[i] << endl;
	}
}

int MStack::write_file_from_stack(char* file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.fail())
	{
		return -1;
	}

	for (int i = m_nSize - 1; i >= 0; i--) // could have overloaded the << operator for this
	{
		out_file << *m_pElements[i] << endl;
	}

	out_file.close();
	return 0;
}

int MStack::read_from_file_to_stack(char* file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.fail())
	{
		return -1;
	}

	int data;

	while (!in_file.eof())
	{
		in_file >> data;
		push(new int(data));
	}

	in_file.close();
	return 0;
}

int main()
{
	MStack stack;
//	stack.pop();
//	return 0;

	stack.push(new int(5));
	stack.push(new int(6));
	stack.push(new int(7));
	stack.push(new int(8));

	stack.trace();

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();

	stack.trace();

//	return 0;

	int* el = stack.pop();
	cout << "popped " << *el << endl;
	stack.trace();

	system("pause");
	return 0;
}