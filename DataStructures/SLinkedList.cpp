#include<iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
public:
	Node()
	{
	}

	Node(int iData) { this->data = iData; }

	friend class Iterator;
	friend class List;
};

class Iterator
{
private:
	Node* currentNode;
	Node* last;

public:

	Node* get_previous(Node* first, Node* target)
	{
		Node* previous = first;

		while (previous->next != target)
		{
			previous = previous->next;
		}

		return previous;
	}

	bool operator==(Iterator it) const
	{
		return this->currentNode == it.currentNode;
	}

	bool operator!=(Iterator it) const
	{
		return this->currentNode != it.currentNode;
	}

	void operator++(int dummy)
	{
		this->currentNode = this->currentNode->next;
	}

	int operator*() const
	{
		return this->currentNode->data;
	}

	friend class List;
};

class List
{
private:
	Node* first;
	Node* last;
public:
	List()
	{
		this->first = NULL;
		this->last = NULL;
	}

	void push(int value)
	{
		Node* newNode = new Node(value);
		if (last == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
	}

	Iterator begin() const
	{
		Iterator it;
		it.currentNode = first;
		it.last = last;
		return it;
	}

	Iterator end() const
	{
		Iterator it;
		it.currentNode = NULL;
		it.last = last;
		return it;
	}

	void insert(Iterator it, int value)
	{
		if (it.currentNode == first)
		{
			Node* newNode = new Node(value);
			newNode->next = first;
			first = newNode;
			return;
		}
		if (it.currentNode == NULL || it.currentNode == last)
		{
			push(value);
			return;
		}
		else
		{
			Node* newNode = new Node(value);
			Node* next = it.currentNode->next;
			it.currentNode->next = newNode;
			newNode->next = next;
		}
	}

	void erase(Iterator it)
	{
		if (it.currentNode == first)
		{
			first = it.currentNode->next;
			delete it.currentNode;
			return;
		}
		else if (it.currentNode == last)
		{
			Node* previous = it.get_previous(this->first, last);
			last = previous;
			previous->next = NULL;
			delete it.currentNode;
			return;
		}

		Node* previous = it.get_previous(this->first, it.currentNode);
		Node* after = it.currentNode->next;
		previous->next = after;
		delete it.currentNode;
	}

	void print() const
	{
		for (Iterator it = begin(); it != end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};


int main()
{
	//software tests in main
	List list;
	list.push(4);
	list.push(3);
	list.push(1);

	cout << "Current List: " << endl;
	list.print();

	Iterator begin = list.begin();
	begin++;
	list.insert(begin, 2);
	cout << "Current List (inserted 2 at position 2): " << endl;
	list.print();

	begin = list.begin();
	begin++;
	begin++;
	list.erase(begin);
	cout << "Current List (deleted at position 3 - middle): " << endl;
	list.print();

	begin = list.begin();
	list.erase(begin);
	cout << "Current List (deleted at position 1 - start): " << endl;
	list.print();

	begin = list.begin();
	begin++;
	list.erase(begin);
	cout << "Current List (deleted at position 2 - end): " << endl;
	list.print();

	list.insert(list.begin(), 9);
	cout << "Current List (inserted 9 at position 1 - start): " << endl;
	list.print();

	system("pause");
	return 0;
}
