//queue : enqueue, dequeue, front, rear, isempty, isfull
#include<bits/stdc++.h>
using namespace std;

class Queue {
	int front, rear, size, capacity;
	unique_ptr<int[]> array;

	public:
	Queue(int capacity);
	bool isempty();
	bool isfull();
	int getfront();
	int getrear();
	void enqueue(int val);
	void dequeue();
};
Queue::Queue(int capacity)
	: capacity(capacity),
	  size(0),
	  front(0),
	  rear(capacity - 1),
	  array(new int[capacity]){ };
//
bool Queue::isempty()
{
	return (size == 0);
}
bool Queue::isfull()
{
	return (size == capacity);
}
int Queue::getfront()
{
	if(this->isempty())
		return INT_MIN;
	else
		return array[front];
}
int Queue::getrear()
{
	if(this->isempty())
		return INT_MIN;
	else
		return array[rear];
}
void Queue::enqueue(int val)//change size, rear
{
	if(this->isfull())
	{
		cout << "overflow :/" << endl;
		return;
	}

	rear = (rear + 1) % capacity;
	array[rear] = val;
	size++;
	cout << "enqueue successful" << endl;
}
void Queue::dequeue()
{
	if(this->isempty())
	{
		cout << "underflow :/" << endl;
		return;
	}

	front = front + 1;
	size--;
}

int main()
{
	Queue obj(5);
	cout << obj.isempty() << endl;
	cout << obj.isfull() << endl;
	obj.enqueue(10);
	obj.enqueue(20);
	obj.enqueue(30);
	cout << obj.getfront() << endl;
	cout << obj.getrear() << endl;
	obj.dequeue();
	cout << obj.getfront() << endl;
	cout << obj.getrear() << endl;
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(20);
	obj.enqueue(20);
	obj.enqueue(20);
	obj.enqueue(20);
	obj.enqueue(20);
	obj.enqueue(20);



}
