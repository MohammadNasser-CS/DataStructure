#pragma once
template<class T>

class StackLinkedList
{
private:
	struct Node
	{
		T item;
		Node* next;
	};
	Node* top, * current;
public:
	StackLinkedList() {
		top = NULL;
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	void push(T newItem)
	{
		Node* temp = new Node;
		if (temp == NULL)
			cout << "Stack push cannot allocate memory";
		else
		{
			temp->item = newItem;
			temp->next = top;
			top = temp;
		}
	}
	T pop() {
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			Node* temp = top;
			top = top->next;
			temp->next = NULL;
			T value = temp->item;
			delete temp;
			return value;
		}
	}
	void print()
	{
		current = top;
		cout << "\nItems in the stack : ";
		cout << "[ ";
		while (current != NULL)
		{
			cout << current->item;
			current = current->next;
		}
		cout << " ]\n";
	}
	void clearStackList()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	~StackLinkedList() {
		clearStackList();
		cout << "Cleared" << endl;
	}
};
