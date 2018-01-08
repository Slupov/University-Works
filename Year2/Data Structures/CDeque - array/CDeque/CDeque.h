#ifndef CITB306G1_CDeque_H
#define CITB306G1_CDeque_H

#include "CExceptions.h"

class QueueEmptyException : public CException {
    public:
        QueueEmptyException() : CException("Empty Queue!") {}
};

class QueueOverflowException : public CException {
    public:
        QueueOverflowException() : CException("Queue overflow!") {}
};

template <typename TElement>
class CDeque {
public:
    CDeque(){};
    virtual ~CDeque(){};

    virtual void addTop(TElement* pInEl) throw(QueueOverflowException) = 0;
    virtual void addBottom(TElement* pInEl) throw(QueueOverflowException) = 0;

    virtual TElement* removeBottom() throw(QueueEmptyException) = 0;
    virtual TElement* removeTop() throw(QueueEmptyException) = 0;
};

#endif // CITB306G1_CDeque_H
