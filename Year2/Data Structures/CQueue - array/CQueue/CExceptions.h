#ifndef CITB306G1_CEXCEPTION
#define CITB306G1_CEXCEPTION

#include <string>
using namespace std;

class CException{
public:
    CException() {
        m_err = "Some error";
    }

    CException(string err) {
        m_err = err;
    }
    string getErr() {return m_err;};
private:
    string m_err;
};

class CExceptionStackOverflow : public CException {
public:
   CExceptionStackOverflow() : CException("Stack overflow exception") {};
};


class CExceptionEmptyStack : public CException {
public:
   CExceptionEmptyStack() : CException("Stack empty exception") {};
};

#endif // CITB306G1_CEXCEPTION
