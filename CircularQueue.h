#pragma once
using namespace std;
const int Queue_MAX_SIZE = 50;
template <class T>
class CircularQueue {
private:
	int rear, front, length;
	T* array;
public:
	CircularQueue() :front(0), rear(Queue_MAX_SIZE - 1), length(0), array(new int[Queue_MAX_SIZE])
	{
	}
	bool isEmpty()
	{
		return length == 0;
	}
	bool isFull()
	{
		return length == Queue_MAX_SIZE;
	}
	void EnQueue(T element) {
		if (isFull())
		{
			cout << "Queue Full Can't Enqueue ...!" << endl;
		}
		else
		{
			rear = (rear + 1) % Queue_MAX_SIZE;
			array[rear] = element;
			length++;
		}
	}
	T DeQueue() {
		T value = array[front];
		front = (front + 1) % Queue_MAX_SIZE;
		--length;
		return value;
	}
};

