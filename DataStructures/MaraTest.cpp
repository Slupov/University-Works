#include <iostream>
using namespace std;
template<class T>
struct Node {
    T item;
    Node* next;
    Node(T t = {}, Node* link = nullptr) :item{t}, next{link} { }
    ~Node() { delete next; }
};

template<class T>
class Stack {
public:
    int size() const { return n; }
    bool empty() const { return n == 0; }
    void push(const T&);
     Stack();
    void printReverse(ostream &out);
    T pop();
    T peek();
    void Print(Node<T> *head);
    Node<T>* first;
private:
    void PrintReverse(Node<T> *head,ostream &out);
    std::size_t n;
};

template<class T>
void Stack<T>::push(const T& t) {
    first = new Node<T>{t,first};
    ++n;
}

template <typename T>
void Stack<T>:: PrintReverse(Node<T> *head,ostream &out)
{
    /* base case which is important for every recursion */
    if (head == NULL) {
        /* we reach the end of the list */
        return;
    }

    /* print the element in the node */


    /* recursive call to for printing the next node in the list */
    PrintReverse(head->next, out);
    out << head->item << " ";
    return;
}

template <typename T> std::ostream& operator<<(std::ostream& out, const Stack<T>& s)
{
    Node<T>* node = s.first;

    while (node)
    {
        out << node->item<<" ";
        node = node->next;

    }

    return out;
}
template<class T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    auto t = first->item;
    first = first->next;
    --n;
    return t;
}

template<class T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    return first->item;
}
template<class T>
void Stack<T>::printReverse(ostream &out){
    PrintReverse(first,out);
}
template <typename T>
Stack<T>::Stack() {
first=NULL;
}

template <typename T>
void popAndPrint(Stack<T> stack) {
    stack.pop();
    cout << stack << endl;
}

int main(int argc, char *argv[]) {

    Stack<int> stack;

    int x;
    while(cin >> x) {
        stack.push(x);
    }

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << stack << endl;

   popAndPrint(stack);

    cout << stack << endl;


    Stack<int> copy;
    copy = stack;
    copy.push(10);

    cout << stack << endl;
    cout << copy << endl;

    stack.printReverse(cout);

    return 0;
}