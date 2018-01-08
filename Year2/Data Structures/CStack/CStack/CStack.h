#include <iostream>
using namespace std;

//forward declarations
class CStack;

int main()
{
	
	return 0;
}

#define CSTACK_MAX_CAP 12
class CStack : private CLinkedList {
public:
	CQueue()
	{
		m_nCap = cap;
		m_nCount = 0;
	};

	CQueue(int cap)
	{
		m_nCap = min(cap,CSTACK_MAX_CAP);
		m_nCount = 0;
	};

	virtual ~CQueue() {};

	virtual void push(int* element) throw(CExceptionStackOverflow) = 0;
	virtual int* pop() throw(CExceptionEmptyStack) = 0;
    virtual void trace() const;

	virtual int write_file_from_stack(char* file_name) = 0;
	virtual int read_from_file_to_stack(char* file_name) = 0;

private:
    int m_nCap;
    int m_nCount;
};

