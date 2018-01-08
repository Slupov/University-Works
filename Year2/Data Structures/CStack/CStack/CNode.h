#ifndef CITB306G1_CNODE
#define CITB306G1_CNODE

#include "CData.h"

class CNode {
public:
    CNode() {
        m_pNext = NULL;
    }
    CNode(CData& in_data) {
        m_data = in_data;
        m_pNext = NULL;
    }

    CData  m_data;
    CNode* m_pNext;
};

#endif // CITB306G1_CNODE
