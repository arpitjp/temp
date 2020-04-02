#include<bits/stdc++.h>
using namespace std;

void show(queue<int> q)
{
	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
int findmin(queue<int>& q, int n)
{
	int temp, index;
	temp = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if(temp>q.front())
		{
			temp = q.front();
			index = i;
		}
		q.push(q.front());
		q.pop();
	}

	for (int i = 0; i < q.size() - n; i++)
	{
		q.push(q.front());
		q.pop();
	}
	return index;
}
void sortqueue(queue<int>& q)
{
	int index, temp;
	int sz = q.size();
	for (int i = 0; i < sz - 1; i++)
	{
		index = findmin(q, sz - i);
		for (int j = 0; j < sz; j++)
		{
			if(j==index)
			{
				temp = q.front();
				q.pop();
			}else
			{
				q.push(q.front());
				q.pop();
			}
		}
		q.push(temp);
	}
	q.push(q.front());
	q.pop();
}
int main()
{
	queue<int> q;
	q.push(30);
	q.push(11);
	q.push(15);
	q.push(4);
	q.push(0);
	q.push(10);
	q.push(100);

	sortqueue(q);
	show(q);
}
