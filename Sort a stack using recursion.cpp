//reverse using recursion
#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top = -1;
    unique_ptr<int[]> array;

    public:
        Stack(int sz) : array(new int[sz]){};
        bool empty()
        {
            return (top == -1);
        }
        void push(int val)
        {
            array[++top] = val;
        }
        int pop()
        {
            return array[top--];
        }
        int peek()
        {
            return array[top];
        }
};

void sorted_insert(int val, Stack& s)
{
    if(s.empty() || val >= s.peek())
    {
        s.push(val);
        return;
    }
    int temp;
    if(val < s.peek())
    {
        int temp = s.pop();
        sorted_insert(val, s);
        s.push(temp);
    }
}
void swart(Stack& s)
{
    if(s.empty())
        return;
    int temp = s.pop();
    swart(s);
    sorted_insert(temp, s);
}
int main()
{
    Stack s(5);
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    //swart(s);
    while(!s.empty())
    {
        cout << s.pop() << " ";
    }
}
