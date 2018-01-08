//#include <iostream>
//#include <cassert>
//using namespace std;
//
//class Node
//{
//public:
//	int data;
//	Node* next;
//
//	Node()
//	{
//		this->data = 0;
//		this->next = NULL;
//	}
//
//	Node(int value)
//	{
//		this->data = value;
//		this->next = NULL;
//	}
//};
//
//class Iterator
//{
//private:
//	Node* current;
//	Node* last;
//	friend class List;
//
//public:
//
//	Node* get_previous(Node* target)
//	{
//		Node* previous = new Node();
//
//		while (this->current->next != target)
//		{
//			previous = this->current->next;
//			this->current = this->current->next;
//		}
//		return previous;
//	}
//
//	void operator++(int dummy)
//	{
//		this->current = this->current->next;
//	}
//
//	int operator*() const
//	{
//		return this->current->data;
//	}
//
//	bool operator==(Iterator other) const
//	{
//		return this->current == other.current;
//	}
//
//	bool operator!=(Iterator other) const
//	{
//		return this->current != other.current;
//	}
//};
//
//class List
//{
//private:
//	Node* first;
//	Node* last;
//
//public:
//	List();
//
//	//adds in the front or back
//	void add(int value)
//	{
//		Node* newNode = new Node(value);
//		if (last == NULL)
//		{
//			first = newNode;
//			last = newNode;
//		}
//		else
//		{
//			last->next = newNode;
//			last = newNode;
//		}
//	}
//
//	void remove(Iterator it)
//	{
//		if (it.current == first)
//		{
//			it.current->next = first;
//			delete it.current;
//			return;
//		}
//		else if (it.current == last)
//		{
//			Node* previous = it.get_previous(last);
//			previous->next = NULL;
//			delete it.current;
//			return;
//		}
//
//		Node* previous = it.get_previous(it.current);
//		Node* after = it.current->next;
//		previous->next = after;
//		delete it.current;
//	}
//
//	//adds in the front or back or middle
//	void removeAt(Iterator it, int value)
//	{
//		if (it.current == NULL || it.current == last)
//		{
//			add(value);
//			return;
//		}
//		else //add in middle
//		{
//			Node* newNode = new Node(value);
//			Node* next = it.current->next;
//			it.current->next = newNode;
//			newNode->next = next;
//		}
//	}
//
//	Iterator begin() const
//	{
//		Iterator it;
//		it.current = first;
//		it.last = last;
//		return it;
//	}
//
//	Iterator end() const
//	{
//		Iterator it;
//		it.current = NULL;
//		it.last = last;
//		return it;
//	}
//};
//
//int main()
//{
//	List list;
//	list.add(4);
//	list.add(3);
//	list.add(1);
//
//	for (Iterator it = list.begin(); it != (list.end()); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//}
