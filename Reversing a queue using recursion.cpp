// C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void printQueue(queue<long long int> Queue)
{
	while (!Queue.empty())
	{
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

// Recursive function to reverse the queue
void reverseQueue(queue<long long int> &q)
{
	if(q.empty())
		return;
	int temp = q.front();
	q.pop();
	reverseQueue(q);
	q.push(temp);
}

// Driver code
int main()
{
	queue<long long int> Queue;
	Queue.push(56);
	Queue.push(27);
	Queue.push(30);
	Queue.push(45);
	Queue.push(85);
	Queue.push(92);
	Queue.push(58);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);
	//reverseQueue(Queue);
	printQueue(Queue);
}