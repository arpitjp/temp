//queue using stacks, method 2 dequeue costly;
#include<bits/stdc++.h>
using namespace std;

class Queue {
	stack<int> s1;

	public:
		void enqueue(int val);
		void dequeue();
};
void Queue::enqueue(int val)
{
	s1.push(val);
	cout << val << " added successfully" << endl;
}
void Queue::dequeue()
{
	int res;
	if(s1.empty())
	{
		cout << "underflow :/" << endl;
		return;
	}

	if(s1.size()==1)
	{
		cout << s1.top() << " dequeued" << endl;
		s1.pop();
		return;
	}
	res = s1.top();
	s1.pop();
	this->dequeue();
	s1.push(res);
	return;
}

int main()
{
	Queue obj;
	obj.enqueue(10);
	obj.enqueue(20);
	obj.enqueue(30);
	obj.enqueue(40);
	obj.enqueue(50);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
}
