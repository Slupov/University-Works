#include <iostream>
using namespace std;

#pragma region Node
template<typename T>
class Stack;

template<class T>
class Node {
public:
	Node(T t = {}, Node *_next = nullptr) : data(t), next(_next) {}
	Node() {}
	~Node() { delete next; }
	friend class Stack<T>;
private:
	T data;
	Node *next;
};

#pragma endregion

#pragma region Stack

template<typename T>
class Stack {
public:
	Stack() : top(nullptr), height(0) {}
	~Stack() {
	}
	void push(T n);
	T pop();

	Node<T>* getTopNode() const;

	void printReverse(ostream &out);

	void print(ostream &out, Node<T> *from);

	bool empty() const;

private:
	Node<T> *top;
	size_t height;

	void PrintReverse(Node<T> *head, ostream &out);
};

template<typename T>
void Stack<T>::push(T n) {
	top = new Node<T>(n, top);
	height++;
}

template<typename T>
T Stack<T>::pop() {
	T temp = top->data;
	Node<T>* newTop = top->next;
	top = nullptr;
	//update top
	top = newTop;

	height--;

	return temp;
}



template<typename T>
void Stack<T>::printReverse(ostream &out) {
	PrintReverse(top, out);
}

template<typename T>
void Stack<T>::print(ostream &out, Node<T>*from) {
	if (from == NULL) {
		return;
	}

	out << from->data << endl;
	print(out, from->next);
}

template<typename T>
void Stack<T>::PrintReverse(Node<T> *head, ostream &out) {
	/* base case which is important for every recursion */
	if (head == NULL) {
		return;
	}

	/* recursive call to for printing the next node in the list */
	PrintReverse(head->next, out);
	out << head->data << " ";
	return;
}

template<typename T>
bool Stack<T>::empty() const {
	return height == 0;
}

template<typename T>
Node<T>* Stack<T>::getTopNode() const {
	return top;
}
#pragma endregion

template<typename T>
std::ostream &operator<<(std::ostream &out, Stack<T> &s) {

	s.print(out, s.getTopNode());
	return out;
}

template<typename T>
void popAndPrint(Stack<T> stack) {
	stack.pop();
	cout << stack << endl;
}

int main(int argc, char *argv[]) {
	Stack<int> stack;

	int x;
	while (cin >> x) {
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
