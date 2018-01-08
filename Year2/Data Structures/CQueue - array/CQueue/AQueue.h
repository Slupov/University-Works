#ifndef CITB306G1_AQUEUE_H
#define CITB306G1_AQUEUE_H

#include <iostream>
#include "CQueue.h"

using namespace std;

template <typename TElement>
class AQueue: public CQueue<TElement> {
public:
    AQueue();
    AQueue(int cap, int max_cap);
    virtual ~AQueue();


    virtual void enqueue(TElement* pInEl) throw(QueueOverflowException);
    virtual TElement* dequeue() throw(QueueEmptyException);

    virtual void trace();


private:
    int m_qTop;
    int m_qBottom;
    int m_nCap;
    TElement** m_pElements;
    int m_nMaxCap;

    void resize_queue();
};

template <typename TElement>
AQueue<TElement>::AQueue() {
    m_qTop = -1;
    m_qBottom = -1;
    m_nCap = 2;
    m_pElements = new TElement*[m_nCap];
    m_nMaxCap = 256;
}

template <typename TElement>
AQueue<TElement>::AQueue(int cap, int max_cap) : m_nCap(cap) {
    m_qTop = -1;
    m_qBottom = -1;
    m_pElements = new TElement*[m_nCap];
    m_nMaxCap = max(cap, max_cap);
}

template <typename TElement>
AQueue<TElement>::~AQueue() {
    delete[] m_pElements;
}
template <typename TElement>
void AQueue<TElement>::resize_queue() {

    if (m_qTop - m_qBottom < m_nCap) {
        return;
    }

    int newCap = min(m_nCap * 2, m_nMaxCap);

    #ifdef DEBUG
        cout << "resize from " << m_nCap << " to " << newCap << endl;
    #endif // DEBUG


    TElement** newQ = new TElement*[newCap];

    for (int i = 0; i < (m_qTop - m_qBottom); i++) {
        newQ[i] = m_pElements[(m_qBottom  + 1 + i) % m_nCap];
    }

    m_qTop = m_qTop - m_qBottom - 1;
    m_qBottom = -1;
    m_nCap = newCap;

    delete[] m_pElements;
    m_pElements = newQ;
}

template <typename TElement>
void AQueue<TElement>::enqueue(TElement* pInEl) throw(QueueOverflowException) {
    if ((m_qTop - m_qBottom) < m_nMaxCap) {
        resize_queue();
        m_qTop++;
        m_pElements[m_qTop % m_nCap] = pInEl;

        #ifdef DEBUG
            cout << "enqueue " << *pInEl << " at " << m_qTop % m_nCap << endl;
;
            trace();
        #endif // DEBUG

    }
    else {
        throw QueueOverflowException();
    }
}

template <typename TElement>
TElement* AQueue<TElement>::dequeue() throw(QueueEmptyException){
    if ((m_qTop - m_qBottom) <= 0) {
        throw QueueEmptyException();
    }

    m_qBottom++;

    #ifdef DEBUG
        trace();
        cout << "dequeue " << *(m_pElements[m_qBottom % m_nCap]) << " from " << m_qBottom % m_nCap << endl;
    #endif // DEBUG

    return m_pElements[m_qBottom % m_nCap];

}
template <typename TElement>
void AQueue<TElement>::trace() {
    cout << "Queue: ";
   for (int i = 0; i < (m_qTop - m_qBottom); i++) {
        cout << *(m_pElements[(m_qBottom  + 1 + i) % m_nCap]) << " ";
    }
    cout << endl;

}


#endif // CITB306G1_AQUEUE_H



