#include <iostream>
#include "StackImplementaion.h"
#include "StackLinkedList.h"
#include "CircularQueue.h"
#include "QueueLinkedList.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
#pragma region Stack
	/*stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.isEmpty())
	{
		cout << s.pop() << endl;
	}*/
#pragma endregion
#pragma region LinearLinkedList
	LinkedList<int> list;
	if (list.isEmpty())
	{
		cout << "isEmpty = false" << endl;

	}
	list.insertFirst(3);
	list.insertFirst(2);
	list.insertFirst(1);
	list.insertEnd(4);
	list.insertEnd(5);
	list.print();
	cout << endl;
	cout << endl;
	cout << "location = " << list.search(4) << endl;
	cout << endl;
	list.reverse();
	cout << endl;
	list.print(); 
	/*
	LinkedList<string> stringList;
	if (stringList.isEmpty())
	{
		cout << "isEmpty = false" << endl;
	}
	stringList.insertFirst("S3");
	stringList.insertFirst("S2");
	stringList.insertFirst("S1");
	stringList.insertEnd("S4");
	stringList.insertEnd("S6");
	stringList.insertAtPosition(4, "S5");
	stringList.print();
	cout << endl;
	cout << endl;
	stringList.removeFirst();
	stringList.print();
	cout << endl;
	cout << endl;
	stringList.removeLast();
	stringList.print();
	cout << endl;
	cout << endl;
	stringList.reverse();
	stringList.print();*/

#pragma endregion
#pragma region StackLinkedList
	/*StackLinkedList<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	while (!s.isEmpty())
	{
		cout << s.pop() << endl;
	}*/
#pragma endregion
#pragma region CircularQueue
	/*CircularQueue<int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.EnQueue(5);
	while (!q.isEmpty())
	{
		cout << q.DeQueue() << endl;
	}*/
#pragma endregion
#pragma region QueueLinkedList
	/*QueueLinkedList<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	while (!q.isEmpty())
	{
		cout << q.dequeue() << endl;
	}*/
#pragma endregion
#pragma region DoublyLinkedList
	/*DoublyLinkedList<int> list;
	if (list.isEmpty())
	{
		cout << "isEmpty = false" << endl;

	}
	list.insertFirst(3);
	list.insertFirst(2);
	list.insertFirst(1);
	list.insertLast(4);
	list.insertLast(5);
	list.display();
	cout << endl;
	cout << endl;
	list.remove(3);
	list.display();
	cout << endl;
	cout << endl;
	DoublyLinkedList<string> stringList;
	if (stringList.isEmpty())
	{
		cout << "isEmpty = false" << endl;
	}
	stringList.insertFirst("S3");
	stringList.insertFirst("S2");
	stringList.insertFirst("S1");
	stringList.insertLast("S4");
	stringList.insertLast("S6");
	stringList.insertAt(4, "S5");
	stringList.display();
	cout << endl;
	cout << endl;
	stringList.removeFirst();
	stringList.display();
	cout << endl;
	cout << endl;
	stringList.removeLast();
	stringList.display();
	cout << endl;
	cout << endl;
	stringList.reverse_display();
	cout << endl;
	cout << endl;
	stringList.deleteNthNode(2);
	stringList.display();*/
#pragma endregion

	return 0;
}