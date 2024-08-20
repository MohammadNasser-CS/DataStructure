#pragma once
#include <iostream>
using namespace std;
template<class T>
class LinkedList
{
private:
	struct Node
	{
		T value;
		Node* next;
	};
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList()
	{
		head = tail = NULL;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	void insertFirst(T newValue) {
		Node* newNode = new Node;
		newNode->value = newValue;
		if (isEmpty()) {
			head = tail = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void insertEnd(T newValue) {
		Node* newNode = new Node;
		newNode->value = newValue;
		if (isEmpty()) {
			head = tail = newNode;
			newNode->next = NULL;
		}
		else {
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		length++;
	}
	void insertAtPosition(int pos, T newValue) {
		if (pos<0 || pos>length) {
			cout << "Out Of Range\n";
			return;
		}
		else {
			Node* newNode = new Node;
			newNode->value = newValue;
			if (pos == 0) insertFirst(newValue);
			else if (pos == length)insertEnd(newValue);
			else {
				Node* current = new Node;
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
				newNode->next = current->next;
				current->next = newNode;
				length++;
			}
		}
	}
	void removeFirst() {
		if (length == 0) {
			cout << "Empty" << endl;
			return;
		}
		else if (length == 1) {
			delete head;
			head = tail = NULL;
			length--;
		}
		else {
			Node* current = new Node;
			current = head;
			head = head->next;
			delete current;
			length--;
			;
		}
	}
	void removeLast() {
		if (length == 0) {
			cout << "Empty" << endl;
			return;
		}
		else if (length == 1) {
			delete head;
			head = tail = NULL;
			length--;
		}
		else {
			Node* current = new Node;
			current = head;
			while (current->next != tail)
			{
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = NULL;
			length--;
		}
	}
	void removeByValue(T key) {
		if (isEmpty()) {
			cout << "Empty!";
			return;
		}
		else if (head->value == key) {
			removeFirst();
		}
		else if (tail->value == key) {
			removeLast();
		}
		else {
			Node* current = new Node;
			Node* previous = new Node;
			current = head->next;
			previous = current;
			while (current != NULL && current->value != key)
			{
				previous = current;
				current = current->next;
			}
			if (current == NULL) cout << "Not Found" << endl;
			else {
				previous = current->next;
				delete current;
				length--;
			}
		}
	}
	void reverse() {
		Node* prev = new Node;
		Node* next = new Node;
		Node* curr = new Node;
		prev = NULL;
		curr = head;
		while (next != NULL)//curr!=NULL
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	int search(T element) {
		Node* current = new Node;
		current = head;
		int loc = 0;
		while (current != NULL)
		{
			if (current->value == element)
				return loc;
			current = current->next;
			loc++;
		}
		return -1;
	}
	void print()
	{
		Node* current = new Node;
		current = head;
		while (current != NULL)
		{
			cout << current->value << endl;
			current = current->next;
		}
	}
	void clearList()
	{
		Node* current = new Node;
		while (head != NULL)
		{
			current = head;
			head = head->next;
			delete current;
		}
		tail = NULL;
		length = 0;
	}
	~LinkedList() {
		clearList();
		cout << "Cleared" << endl;
	}
};