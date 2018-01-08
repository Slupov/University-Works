#include <iostream>
using namespace std;

//forward declarations
template <typename T>
class Queue;

template <typename T>
class Node
{
public:
	Node()
	{
	}

	Node(T x, Node<T>* _next = NULL)
	{
		data = x;
		next = _next;
	}

	~Node()
	{
	}

	friend class Queue<T>;
private:
	T data;
	Node<T>* next;
};

template <typename T>
class Queue
{
public:
	Queue()
	{
		start = NULL;
		top = NULL;
		length = 0;
	}

	~Queue()
	{
		cout << "Destructor" << endl;
		clear();
	}

	void Enqueue(T x);
	T Dequeue();

	void printReverse(ostream& out);
	void print(ostream& out, Node<T>* head);
	bool empty() const;

	Node<T>* getTopNode();
	Queue<T>& operator=(const Queue<T>& q);

private:
	Node<T>* top;
	Node<T>* start;
	size_t length;

	void clear();
	void PrintReverse(ostream& out, Node<T>* head);
	void copy(const Queue<T>& q);
};

template <typename T>
void Queue<T>::Enqueue(T x)
{
	Node<T>* newNode = new Node<T>(x, NULL);

	if (empty())
	{
		start = newNode;
		top = newNode;
	}
	else
	{
		start->next = newNode;
		start = newNode;
	}

	length++;
}

template <typename T>
T Queue<T>::Dequeue()
{
	if (empty())
	{
		std::cout << "Queue is empty, cant dequeue!";
		return NULL;
	}
	T temp = top->data;
	top = top->next;

	length--;
	return temp;
}

template <typename T>
void Queue<T>::printReverse(ostream& out)
{
	PrintReverse(out, top);
}

template <typename T>
void Queue<T>::PrintReverse(ostream& out, Node<T>* from)
{
	if (from == NULL)
	{
		return;
	}

	out << from->data << " ";
	PrintReverse(out, from->next);
}

template <typename T>
void Queue<T>::copy(const Queue<T>& q)
{
	Node<T>* temp = q.top;

	while (temp != NULL)
	{
		this->Enqueue(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void Queue<T>::print(ostream& out, Node<T>* head)
{
	/* base case which is important for every recursion */
	if (head == NULL)
	{
		return;
	}

	/* recursive call to for printing the next node in the list */
	print(out, head->next);
	out << head->data << " ";
}

template <typename T>
bool Queue<T>::empty() const
{
	return length == 0;
}

template <typename T>
Node<T>* Queue<T>::getTopNode()
{
	return top;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
	this->copy(q);
	return *this;
}

template <typename T>
void Queue<T>::clear()
{
	while (top != NULL)
	{
		Node<T>* temp = top->next;

		Node<T>* currentTop = top;
		delete currentTop;

		top = temp;
	}
}

template <typename T>
void dequeueAndPrint(Queue<T>& queue)
{
	queue.Dequeue();
	cout << queue << endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Queue<T>& q)
{
	q.print(out, q.getTopNode());
	return out;
}

int main()
{
	Queue<int> queue;

	int x;
	while (cin >> x)
	{
		queue.Enqueue(x);
	}

	cout << "Dequeue: " << queue.Dequeue() << endl;
	cout << "Dequeue: " << queue.Dequeue() << endl;

	std::cout << "--------------" << endl;

	cout << queue << endl;

	dequeueAndPrint(queue);

	cout << queue << endl;

	Queue<int> copy;
	copy = queue;

	std::cout << "Enque 10 into copy" << endl;
	copy.Enqueue(10);

	std::cout << "Original: ";
	cout << queue << endl;

	std::cout << "Copy: ";
	cout << copy << endl;

	queue.printReverse(cout);
	
	return 0;
}
