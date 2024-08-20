#pragma once
#include <iostream>
using namespace std;
template<class T>
class QueueLinkedList
{
private:
	struct Node
	{
		T item;
		Node* next;
	};
	int length;
	Node* front, * rear;

public:
	QueueLinkedList() :front(NULL), rear(NULL), length(0)
	{}
	bool isEmpty()
	{
		return (length == 0);
	}
	T dequeue()
	{
		if (isEmpty())
			cout << "Empty Queue" << endl;
		else if (length == 1)
		{
			T item = front->item;
			delete front;
			rear = NULL;
			length = 0;
			return item;
		}
		else
		{
			T item = front->item;
			Node* current = front;
			front = front->next;
			delete current;//free(current)
			length--;
			return item;
		}
	}
	void enqueue(T item)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (length == 0)
			rear = front = newNode;
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		length++;
	}
	T frontRetrive()
	{
		return front->item;
	}
	T rearRetrive()
	{
		return rear->item;
	}
	void clearQueue()
	{
		Node* current;
		while (front != NULL)
		{
			current = front;
			front = front->next;
			delete current;
		}
		rear = NULL;
		length = 0;
	}
	void display()
	{
		Node* cur = front;
		cout << "Item in the queue :[ ";
		while (cur != NULL)
		{
			cout << cur->item << " ";
			cur = cur->next;
		}cout << "]" << endl;
	}
	void search(T item)
	{
		Node* cur = front;
		bool flag = true;
		while (cur != NULL)
		{
			if (cur->item == item)
			{
				cout << "the item :" << item << " found" << endl;
				flag = false;
				break;
			}
			cur = cur->next;
		}
		if (flag)
			cout << "the item : " << item << " not found" << endl;

	}

};



