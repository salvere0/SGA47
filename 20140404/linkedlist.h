#pragma once

#include <iostream>
using namespace std;

struct Node
{
	typedef int value_type;

	value_type value;
	Node* next;

	Node(const value_type& v, Node* n)
		: value(v), next(n)
	{}
	Node(Node* n)
		: next(n), value(0)
	{}

	friend ostream& operator << (ostream& os, const Node& obj)
	{
		cout << "[" << obj.value << "]" << &obj << "==>" << obj.next;

		return os;
	}
};

class LinkedList
{
public :
	typedef Node::value_type value_type;

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
		Node* pNode = new Node(v, current->next);

		current->next = pNode;

		_size++;
	}
	void insert_front(const value_type& v)
	{
		Node* pNode = new Node(v, head->next);

		head->next = pNode;

		_size++;
	}
	void insert_back(const value_type& v)
	{
		Node* pNode = new Node(v, tail);

		if (current->next == tail)
			current = pNode;

		Node* pPrevNode = head;
		while (pPrevNode->next != tail)
			pPrevNode = pPrevNode->next;

		pPrevNode->next = pNode;

		_size++;
	}
	void remove()
	{
		if (current->next == tail) return;

		Node* pNode = current->next;

		current->next = pNode->next;

		delete pNode;

		_size--;
	}
	void remove_front()
	{
		if (head->next == tail) return;

		Node* pNode = head->next;

		if (pNode == current)
			prev();

		head->next = pNode->next;

		delete pNode;

		_size--;
	}
	void remove_back()
	{
		if (head->next == tail) return;

		Node* pNode = head;
		while (pNode->next->next != tail)
			pNode = pNode->next;

		if (pNode->next == current)
			prev();

		delete pNode->next;

		pNode->next = tail;

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

		Node* tmp = current;

		current = head;

		while (current->next != tmp)
		{
			current = current->next;
		}
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
		for (Node* tmp = obj.head; tmp != NULL; tmp = tmp->next)
		{
			if (tmp == obj.current)
				cout << '*' << *tmp << endl;
			else
				cout << ' ' << *tmp << endl;
		}

		return os;
	}

private :
	void init()
	{
		tail = new Node(0);
		head = new Node(tail);
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
	Node* head;
	Node* tail;
	Node* current;
	unsigned _size;
};