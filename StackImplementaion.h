#pragma once
const int MAX_SIZE = 50;
using namespace std;
template <class T>
class stack
{
private:
	int top;
	T* array;
public:
	stack() :top(-1), array(new int[MAX_SIZE])
	{
	}
	void push(T element) {
		if (top < MAX_SIZE) {
			top++;
			this->array[top] = element;
		}
		else {
			cout << "Stack is already full" << endl;
		}
	}
	bool isEmpty() {
		return top == -1;
	}
	T pop() {
	
		return array[top--];
	}

};

