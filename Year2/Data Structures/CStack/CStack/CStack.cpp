#include "CStack.h"
#include "CExceptions.h"

using namespace std;

void CStack::push(CNode* pNewNode) throw (CExceptionStackOverflow){
    if (m_nCount < m_nCap) {
        insert_node(0, pNewNode);
        m_nCount++;
    }
    else {
        throw CExceptionStackOverflow();
    }
}


CNode* CStack::pop() throw (CExceptionEmptyStack) {
    if (m_nCount < 1) {
        throw CExceptionEmptyStack();
    }

    if (NULL == m_pHead) {
        throw CExceptionEmptyStack();
    }

    CNode* pTopNode = m_pHead;
    m_pHead = m_pHead->m_pNext;
    pTopNode->m_pNext = NULL;
    return pTopNode;
}


void CStack::trace() const {
    print(cout);
}


int CStack::write_file_from_linked_list(char* file_name){
    int res = CLinkedList::write_file_from_linked_list(file_name);
    return res;
}


 int CStack::read_from_file_to_linked_list(char* file_name) {
    ifstream in_file;
    in_file.open(file_name);
    if (in_file.fail()) {
        return -1;
    }

    CData data;
    CNode* pNewNode = NULL;

    while(!in_file.eof()) {
        in_file >> data;
        pNewNode = new CNode(data);
        push(pNewNode);
    }

    in_file.close();
    return 0;
}


