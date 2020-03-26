//min stack
#include<bits/stdc++.h>
using namespace std;

class minstack {
    stack<int> s;
    float min = INFINITY;

    public:
        void push(int val);
        void pop();
        bool empty();
        void getmin();
};

void minstack::push(int val)
{
    if(val>=min)
    {
        s.push(val);
    }
    else
    {
        s.push(2*val - min);
        min = val;
    }
    cout << val << "\tpushed successfully" << endl;
}

bool minstack::empty()
{
    return s.empty();
}

void minstack::getmin()
{
    if(empty())
    {
        cerr << "underflow :/\n";
        return;
    }
    cout << min << "\tis minimum element" << endl;
}

void minstack::pop()
{
    if(s.empty())
    {
        cerr << "underflow :/\n";
        return;
    }

    if(s.top() >= min)
    {
        cout << s.top() << "\tis popped successfully" << endl;
        s.pop();
        return;
    }
    cout << min << "\tis popped successfully" << endl;
    min = 2 * min - s.top();
    s.pop();
}
int main()
{
    minstack s;
    s.push(3);
    s.push(5);
    s.getmin();
    s.push(2);
    s.push(1);
    s.getmin();
    s.pop();
    s.getmin();
    s.pop();
}
