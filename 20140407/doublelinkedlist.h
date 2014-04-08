#pragma once

#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	typedef T value_type;

	value_type value;
	Node* next;
	Node* prev;

	Node(const value_type& v, Node* p, Node* n)
		: value(v), prev(p), next(n)
	{}
	Node(Node* p, Node* n)
		: prev(p), next(n)
	{}

	friend ostream& operator << (ostream& os, const Node& obj)
	{
		cout << obj.prev << "<== ";
		cout << "[" << *obj.value << "]" << &obj << "==>" << obj.next;

		return os;
	}
};

template<typename T>
class LinkedList
{
	typedef Node<T> node;

public :
	typedef typename node::value_type value_type;

public :
	LinkedList()
	{
		init();
	}
	~LinkedList()
	{
		removeall();
	}

	void insert(const value_type& v)
	{
		node* pNode = new node(v, current, current->next);

		//current->next = pNode;
		pNode->prev->next = pNode;
		pNode->next->prev = pNode;

		_size++;
	}
	void insert_front(const value_type& v)
	{
		node* pNode = new node(v, head, head->next);

		//head->next = pNode;
		pNode->prev->next = pNode;
		pNode->next->prev = pNode;

		_size++;
	}
	void insert_back(const value_type& v)
	{
		node* pNode = new node(v, tail->prev, tail);

		pNode->prev->next = pNode;
		pNode->next->prev = pNode;

		_size++;
	}
	void remove()
	{
		if (current->next == tail) return;

		node* pNode = current->next;

		pNode->next->prev = pNode->prev;
		pNode->prev->next = pNode->next;

		delete pNode;

		_size--;
	}
	void remove_front()
	{
		if (head->next == tail) return;

		node* pNode = head->next;

		if (pNode == current)
			prev();

		node* pNode = current->next;

		pNode->next->prev = pNode->prev;
		pNode->prev->next = pNode->next;

		delete pNode;

		_size--;
	}
	void remove_back()
	{
		if (head->next == tail) return;

		node* pNode = tail->prev;

		if (pNode == current)
			prev();

		pNode->next->prev = pNode->prev;
		pNode->prev->next = pNode->next;

		delete pNode;

		_size--;
	}
	void next()
	{
		if (current->next == tail) return;
		current = current->next;
	}
	void prev()
	{
		if (current == head) return;
		current = current->prev;
	}
	const unsigned size() const
	{
		return _size;
	}
	value_type value()
	{
		return current->next->value;
	}

	friend ostream& operator << (ostream& os, const LinkedList& obj)
	{
		for (node* tmp = obj.head; tmp != NULL; tmp = tmp->next)
		{
			if (tmp == obj.head || tmp == obj.tail)
				cout << "---------" << endl;
			else if (tmp == obj.current)
				cout << '*' << *tmp << endl;
			else
				cout << ' ' << *tmp << endl;
		}

		return os;
	}

private :
	void init()
	{
		tail = new node(NULL, NULL);
		head = new node(NULL, tail);
		tail->prev = head;
		current = head;
		_size = 0;
	}
	void removeall()
	{
		while (head)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}

private :
	node* head;
	node* tail;
	node* current;
	unsigned _size;
};