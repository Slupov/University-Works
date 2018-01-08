#include <iostream>
#include "AQueue.h"

using namespace std;

int main() {
    AQueue<int> q(4, 10);

    #ifdef DEBUG
        cout << "This is visible in DEBUG only" << endl;
    #endif // DEBUG

    try {
        q.enqueue(new int(10));
        q.enqueue(new int(20));
        q.enqueue(new int(30));
        q.enqueue(new int(40));

        q.dequeue();

        q.enqueue(new int(50));
        q.enqueue(new int(60));
        q.enqueue(new int(70));
        q.enqueue(new int(80));
        q.enqueue(new int(90));
        q.enqueue(new int(100));
        q.dequeue();
        q.dequeue();

        q.enqueue(new int(110));
        q.dequeue();

        q.enqueue(new int(120));
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
