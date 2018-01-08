#ifndef CITB306G1_ADeque_H
#define CITB306G1_ADeque_H

#include <iostream>
#include "CDeque.h"

using namespace std;

template <typename TElement>
class ADeque: public CDeque<TElement> {
public:
    ADeque();
    ADeque(int cap, int max_cap);
    virtual ~ADeque();


    virtual void addTop(TElement* pInEl) throw(QueueOverflowException);
    virtual void addBottom(TElement* pInEl) throw(QueueOverflowException);


    virtual TElement* removeBottom() throw(QueueEmptyException);
    virtual TElement* removeTop() throw(QueueEmptyException);

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
ADeque<TElement>::ADeque() {
    m_qTop = -1;
    m_qBottom = -1;
    m_nCap = 2;
    m_pElements = new TElement*[m_nCap];
    m_nMaxCap = 256;
}

template <typename TElement>
ADeque<TElement>::ADeque(int cap, int max_cap) : m_nCap(cap) {
    m_qTop = -1;
    m_qBottom = -1;
    m_pElements = new TElement*[m_nCap];
    m_nMaxCap = max(cap, max_cap);
}

template <typename TElement>
ADeque<TElement>::~ADeque() {
    delete[] m_pElements;
}
template <typename TElement>
void ADeque<TElement>::resize_queue() {
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
void ADeque<TElement>::addTop(TElement* pInEl) throw(QueueOverflowException) {
    if ((m_qTop - m_qBottom) < m_nMaxCap) {
        resize_queue();
        m_qTop++;
        m_pElements[m_qTop % m_nCap] = pInEl;

        #ifdef DEBUG
            cout << "addTop " << *pInEl << " at " << m_qTop % m_nCap << endl;
            trace();
        #endif // DEBUG

    }
    else {
        throw QueueOverflowException();
    }
}

template <typename TElement>
void ADeque<TElement>::addBottom(TElement* pInEl) throw(QueueOverflowException) {
    if ((m_qTop - m_qBottom) < m_nMaxCap) {
        resize_queue();
        m_pElements[m_qBottom % m_nCap] = pInEl;
        m_qBottom--;

        #ifdef DEBUG
            cout << "addBottom " << *pInEl << " at " << (m_qBottom + 1) % m_nCap << endl;
            trace();
        #endif // DEBUG
    }
    else {
        throw QueueOverflowException();
    }
}

template <typename TElement>
TElement* ADeque<TElement>::removeBottom() throw(QueueEmptyException){
    if ((m_qTop - m_qBottom) <= 0) {
        throw QueueEmptyException();
    }

    m_qBottom++;

    #ifdef DEBUG
        cout << "removeBottom " << *(m_pElements[m_qBottom % m_nCap]) << " from " << m_qBottom % m_nCap << endl;
        trace();
    #endif // DEBUG

    return m_pElements[m_qBottom % m_nCap];
}


template <typename TElement>
TElement* ADeque<TElement>::removeTop() throw(QueueEmptyException){
    if ((m_qTop - m_qBottom) <= 0) {
        throw QueueEmptyException();
    }

    TElement* pEl = m_pElements[m_qTop % m_nCap];
    m_qTop--;

    #ifdef DEBUG
        cout << "removeTop " << *pEl << " from " << (m_qTop + 1) % m_nCap << endl;
        trace();
    #endif // DEBUG

    return pEl;
}



template <typename TElement>
void ADeque<TElement>::trace() {
    cout << "Queue: ";
   for (int i = 0; i < (m_qTop - m_qBottom); i++) {
        cout << *(m_pElements[(m_qBottom  + 1 + i) % m_nCap]) << " ";
    }
    cout << endl;

}


#endif // CITB306G1_ADeque_H



