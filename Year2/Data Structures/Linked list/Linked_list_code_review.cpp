#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CData {
public:
    CData() {};
    CData(int prio, int val, string data) {
        m_nPrio = prio;
        m_nValue = val;
        m_sData = data;
    };

    friend ostream& operator<<(ostream& out, const CData data) {
        out << data.m_nPrio << „ „ << data.m_nValue << „ „ << data.m_sData;
        return out;
    }

    friend istream& operator>>(istream& in, CData& data) {
        in >> data.m_nPrio >> data.m_nValue >> data.m_sData;
        return in;
    }

private:
    int m_nPrio;
    int m_nValue;
    string m_sData;
};

class CNode {
public:
    CNode();
    CNode(CData in_data);

    CData  m_data;
    CNode* m_pNext;
};

CNode::CNode()
{
    m_pNext = NULL;
}

CNode::CNode(CData in_data) {
    m_data = in_data;
    m_pNext = NULL;
}


class CLinkedList {
public:
    CLinkedList() {
        m_pHead = NULL;
    }

    ~CLinkedList() {
        free_list();
    }

    CNode* m_pHead;


    void print(ostream& out);
    void append(CNode* pNewNode);
    void free_list();

    void delete_node(const int nPos);
    void insert_node(const int nPos, CNode* pNewNode);
};


void CLinkedList::print(ostream& out) {
    CNode* pList = m_pHead;
    while (NULL != pList) {
        out << pList->m_data << endl;
        pList = pList->m_pNext;
    }
    out << endl;
}




void CLinkedList::append(CNode* pNewNode) {

    if (NULL == m_pHead) {
        m_pHead = pNewNode;
        m_pHead->m_pNext = NULL;
    }
    else {
        CNode* pList = m_pHead;
        while (NULL != pList->m_pNext) {
            pList = pList->m_pNext;
        }
        pList->m_pNext = pNewNode;
        pList->m_pNext->m_pNext = NULL;
    }
}

void CLinkedList::free_list() {
    CNode* pList = m_pHead;

    while (NULL != pList) {
        CNode* pN = pList->m_pNext;
        delete pList;
        pList = pN;
    }
}


void CLinkedList::delete_node(const int nPos){
    if (NULL == m_pHead) {
        return;
    }

    if ((0 == nPos) && (NULL != m_pHead)) {
        CNode* pN = m_pHead;
        m_pHead = m_pHead->m_pNext;
    }
    else {
        CNode* pList = m_pHead;
        int i = 0;
        while ((NULL != pList->m_pNext) && (i < nPos-1)) {
            i++;
            pList = pList->m_pNext;
        }

        if ((i == nPos-1) && (NULL != pList->m_pNext))
	   pList->m_pNext = pList->m_pNext->m_pNext;
    }
}



void CLinkedList::insert_node(int nPos, CNode* pNewNode){
    if (NULL == m_pHead && 0 == nPos) {
        append(pNewNode);
    }

    if ((nPos = 0) && (NULL != m_pHead)) {
        CNode* pN = pNewNode;
        pN->m_pNext = m_pHead;
        m_pHead = pN;
    }


    else {
        CNode* pList = m_pHead;
        int i = 0;
        while ((NULL != pList->m_pNext) && (i < nPos)) {
            i++;
            pList = pList->m_pNext;
        }

        CNode* pN = pNewNode;
        pN->m_pNext = pList->m_pNext;
        pList->m_pNext = pN;
    }
}








int read_from_file_to_linked_list(char* file_name, CLinkedList& LList) {
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
        LList.append(pNewNode);
    }

    in_file.close();
    return 0;
}

int wrtie_file_from_linked_list(char* file_name, CLinkedList& LList) {
    ofstream out_file;
    out_file.open(file_name);
    if (out_file.fail()) {
        return -1;
    }

    LList.print(out_file);
    out_file.close();
    return 0;
}

int main(int argc, char** argv) {
if (argc < 3) {
cout << „Usage: „ << endl;
cout << argv[0] << „ in_file_name out_file_name“;
return -1;
}

    CLinkedList myList;
    myList.print(cout);


if (0 > read_from_file_to_linked_list(argv[1], myList))
cout << „Can’t read from file: „ << argv[1];


return -1;

if (0 > wrtie_file_from_linked_list(argv[2], myList)) {
cout << „Can’t write to file: „ << argv[2];
return -2
}

return 0;
}
