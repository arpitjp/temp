#include<bits/stdc++.h>
using namespace std;

bool check(queue<int>& q)
{
    queue<int> t;
    stack<int> s;

    while(!q.empty())
    {
        if(s.empty() || q.front()<s.top())//pehle s mai daal raha
        {
            s.push(q.front());
            q.pop();
        }
        else if(q.front()>s.top())//nhi jaa raha toh
        {
            while(q.front()>s.top())
            {
                if(t.empty() || s.top() > t.back())
                {
                    t.push(s.top());
                    s.pop();
                    if(s.empty())
                        break;
                }
                else
                    return 0;
            }
        }
        
    }
    return 1;
}
int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(6);
    q.push(3);
    q.push(4);

    check(q) ? cout << "Yes" << endl : cout << "No" << endl;
}
