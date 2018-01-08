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

	Node* get_previous(Node* target)
	{
		Node* previous = new Node();
		while (this->currentNode->next != target)
		{
			previous = this->currentNode->next;
			next();
		}
		return previous;
	}

	bool not_equals(Iterator it) const
	{
		return this->currentNode == it.currentNode;
	}

	void next()
	{
		this->currentNode = this->currentNode->next;
	}

	int get() const
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
			it.currentNode->next = first;
			delete it.currentNode;
			return;
		}
		else if (it.currentNode == last)
		{
			Node* previous = it.get_previous(last);
			previous->next = NULL;
			delete it.currentNode;
			return;
		}

		Node* previous = it.get_previous(it.currentNode);
		Node* after = it.currentNode->next;
		previous->next = after;
		delete it.currentNode;
	}
};


int main()
{
	List list;
	list.push(4);
	list.push(3);
	list.push(1);

	for (Iterator it = list.begin(); it.not_equals(list.end()); it.next())
	{
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;

	Iterator begin = list.begin();
	begin.next();

	list.insert(begin, 2);

	for (Iterator it = list.begin(); it.not_equals(list.end()); it.next())
	{
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;


	begin = list.begin();
	begin.next();
	begin.next();
	list.erase(begin);

	for (Iterator it = list.begin(); it.not_equals(list.end()); it.next())
	{
		std::cout << it.get() << " ";
	}
	std::cout << std::endl;

	return 0;
}