#ifndef CITB306G1_CLINKEDLIST
#define CITB306G1_CLINKEDLIST

#include <fstream>
#include "CNode.h"

class CLinkedList {
public:
    CLinkedList() {
        m_pHead = NULL;
    }

    ~CLinkedList() {
        free_list();
    }

    CNode* m_pHead;

public:
    void print(ostream& out) const;
    void append(CNode* pNewNode);
    void free_list();

    void delete_node(const int nPos);
    void insert_node(const int nPos, CNode* pNewNode);

    friend ostream& operator<<(ostream& out, const CLinkedList& linked_list) {
        linked_list.print(out);
        return out;
    }


    int write_file_from_linked_list(char* file_name);
    int read_from_file_to_linked_list(char* file_name);
};


#endif // CITB306G1_CLINKEDLIST
