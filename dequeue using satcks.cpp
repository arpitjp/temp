//queue using stacks, method 2 dequeue costly;
#include<bits/stdc++.h>
using namespace std;

class Queue {
	stack<int> s1, s2;
	
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
	if(s1.empty() && s2.empty())
	{
		cout << "underflow :/" << endl;
		return;
	}
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	cout << s2.top() << " dequeued" << endl;
	s2.pop();
	return;
}

int main()
{
	Queue obj;
	obj.enqueue(20);
	obj.enqueue(40);
	obj.enqueue(50);
	obj.enqueue(60);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
}
