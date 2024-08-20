#pragma once
#include <iostream>
using namespace std;
template <class T>
class DoublyLinkedList
{
private:
	struct Node
	{
		T element;
		Node* next,*prev;
	};
	Node* first, * last;
	int count;
public:
	DoublyLinkedList(): first(NULL),last(NULL),count(0)
	{}
	bool isEmpty() {
		return count == 0;
	}
	void insertFirst(T newElement) {
		Node* newNode = new Node;
		newNode->element = newElement;
		if (count == 0) {
			first = last = newNode;
			newNode->next = newNode->prev = NULL;
		}
		else {
			newNode->next = first;
			newNode->prev = NULL;
			first->prev = newNode;
			first = newNode;
		}
		count++;
	}
	void insertLast(T newElement) {
		Node* newNode = new Node;
		newNode->element = newElement;
		if (count == 0) {
			first = last = newNode;
			newNode->next = newNode->prev = NULL;
		}
		else {
			newNode->next = NULL;
			newNode->prev = last;
			last->next = newNode;
			last = newNode;
		}
		count++;
	}
	void insertAt(int pos, T newElement)
	{
		if (pos < 0 || pos > count)
			cout << "Out Of Range ...!" << endl;
		else
		{
			Node* newNode = new Node;
			newNode->element = newElement;
			if (pos == 0)
				insertFirst(newElement);
			else if (pos == count)
				insertLast(newElement);
			else
			{
				Node* current = first;
				// to let current points on the node which before the aimed node by one step.
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
				newNode->next = current->next;
				newNode->prev = current;
				current->next->prev = newNode;
				current->next = newNode;
				count++;
			}

		}
	}
	void removeFirst()
	{
		if (count == 0)
			cout << "Empty List" << endl;
		else if (count == 1)//first == last
		{
			delete first;
			last = first = NULL;
		}
		else
		{
			Node* current = first;
			first = first->next;
			first->prev = NULL;
			delete current;

		}
		count--;
	}
	void removeLast()
	{
		if (count == 0)
			cout << "Empty List" << endl;
		else if (count == 1)
		{
			delete first;
			last = first = NULL;
			count--;
		}
		else
		{
			Node* current = last;
			last = last->prev;
			last->next = NULL;
			delete current;
			count--;
		}
	}
	void deleteNthNode(int pos)
	{
		if (pos < 0 || pos >= count) {
			cout << "Out Of Range" << endl;
			return;
		}
		else if (pos == 0)
		{
			removeFirst();
		}
		else if (pos == count - 1)
		{
			removeLast();
		}
		else {
			Node* current = first->next;
			// to let current points to the aimed node.
			for (int i = 1; i < pos; i++)
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		count--;
	}
	void remove(T newElement)
	{
		if (isEmpty())
		{
			cout << "Empty List Can't Remove ";
			return;
		}
		Node* current = first->next;
		if (first->element == newElement)//delete the first element, special case
		{
			removeFirst();
			return;
		}
		else if (last->element == newElement)//delete the last element, special case 
		{
			removeLast();
			return;
		}
		else
		{
			int i = 1;
			for (; current->element != newElement; i++)
			{
				if (current->element == newElement)
					break;
				current = current->next;
			}
			//while (current != NULL)//current->element!=newElement
			//{
			//	if (current->element == newElement)
			//		break;
			//	current = current->next;
			//}
			if (current == NULL) {
				cout << "The newElement is not there\n";
				return;
			}
			else
			{
				deleteNthNode(i);
				//current->prev->next = current->next;
				////if (current->next != NULL)
				//current->next->prev = current->prev;
				//delete current;
				//count--;
			}
		}
	}
	void display() {
		if (isEmpty())
		{
			cout << "Empty List Can't Display...!";
		}
		else {
			Node* temp = first;
			while (temp != nullptr) {
				cout << temp->element << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
	void reverse_display() {
		if (isEmpty())
		{
			cout << "Empty List Can't Display Reverse...!";
		}
		else
		{
			Node* temp = last;
			while (temp != NULL) {
				cout << temp->element << " ";
				temp = temp->prev;
			}
		}
	}
};