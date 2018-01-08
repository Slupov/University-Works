#include <iostream>
#include "ADeque.h"

using namespace std;

int main() {
    ADeque<int> q(4, 10);

    #ifdef DEBUG
        cout << "This is visible in DEBUG only" << endl;
    #endif // DEBUG

    try {
        q.addTop(new int(10));
        q.addTop(new int(20));
        q.addBottom(new int(30));
        q.addTop(new int(40));

        q.removeBottom();
        q.removeTop();

        q.addTop(new int(50));
        q.addTop(new int(60));
        q.addTop(new int(70));
        q.addTop(new int(80));
        q.addTop(new int(90));
        q.addBottom(new int(-10));
        q.removeTop();
        q.removeTop();

        q.addTop(new int(110));
        q.removeTop();

        q.addTop(new int(120));

    }
    catch (QueueOverflowException e) {
        cout << e.getErr();
    }
    catch (CException r) {
        cout << r.getErr();
    }
    catch (...) {

    }

}
