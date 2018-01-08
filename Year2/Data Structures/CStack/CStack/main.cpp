#include <iostream>
#include <fstream>
#include <string>

#include "CStack.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << endl;
        cout << argv[0] << " in_file_name out_file_name";
        return -1;
    }

    try {
        CStack myStack;

        if (0 > myStack.read_from_file_to_linked_list(argv[1])) {
            cout << "Can't read from file: " << argv[1];
            return -1;
        }

        myStack.trace();
        CNode* pTopNode = myStack.pop();
        cout << "pop: " << pTopNode->m_data << endl;
        myStack.trace();

        if (0 > myStack.write_file_from_linked_list(argv[2])) {
            cout << "Can't write to file: " << argv[2];
            return -2;
        }
    }
    catch(CExceptionEmptyStack e) {
        cout << e.getErr() << endl;
    }
    catch(CExceptionStackOverflow e) {
        cout << e.getErr() << endl;
    }
    catch(...) {
        cout << "Error!" << endl;
    }

    return 0;
}




