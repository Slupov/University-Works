#ifndef CITB306G1_CQUEUE_H
#define CITB306G1_CQUEUE_H

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
class CQueue {
public:
    CQueue(){};
    virtual ~CQueue(){};

    virtual void enqueue(TElement* pInEl) throw(QueueOverflowException) = 0;
    virtual TElement* dequeue() throw(QueueEmptyException) = 0;
};

#endif // CITB306G1_CQUEUE_H
