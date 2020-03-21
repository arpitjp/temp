//my fucking stack

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int top = -1;
    int arrsz;
    unique_ptr<int[]> array;

public:
    Stack(int arrsz);
    bool isempty();
    void peek();
    void push(int val);
    void pop();
};

Stack::Stack(int arrsz)
    : array(new int[arrsz]),
      arrsz(arrsz){}
//

bool Stack::isempty()
{
    if(top == -1) return 1;
    else return 0;
}

void Stack::peek()
{
    if(top == -1) cout << "stack is empty :/" << endl;
    else cout << "top element is" << array[top] << endl; 
}

void Stack::push(int val)
{
    if(top==arrsz-1) cout << "overflow :/" << endl;
    else
    {
        array[++top] = val;
        cout << "operation successful" << " stack sz = " << top+1 << endl;
    }
}

void Stack::pop()
{
    if(top==-1) cout << "empty stack" << endl;
    else 
    {
        top--;
        cout << "successful" << endl;
    }
}

int main()
{
    Stack s(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.peek();
    s.pop();
    s.peek();
}