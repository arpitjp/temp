//iterative tree of hanoi
#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top = -1;
    int size;
    unique_ptr<int[]> array;

    public:
        Stack(int sz) : array(new int[sz]), size(sz){};
        bool empty()
        {
            return (top == -1);
        }
        void push(int val)
        {
            top++;
            array[top] = val;
        }
        void pop()
        {
            top--;
        }
        int peek()
        {
            return ((this->empty()) ? (size+1) : (array[top]));
        }
};

void iterate(int n)
{
    Stack stacks(n);
    Stack stacka(n);
    Stack stackd(n);
    char s = 'S', a = 'A', d = 'D', t;

    int moves = pow(2, n) - 1;
    for (int i = n; i >0; i--)
        stacks.push(i);
    if(n%2==0)
    {
        t = a;
        a = d;
        d = t;
    }

    for (int i = 1; i <= moves; i++)
    {
        if(i%3==1)//s and d
        {
            if(stacks.peek() < stackd.peek())
            {
                cout << "move " << stacks.peek() << " from " << s << " to " << d << endl;
                stackd.push(stacks.peek());
                stacks.pop();
            }
            else
            {
                cout << "move " << stackd.peek() << " from " << d << " to " << s << endl;
                stacks.push(stackd.peek());
                stackd.pop();
            }
            
        }
        else if(i%3==2)//s and a
        {
            if(stacks.peek() < stacka.peek())
            {
                cout << "move " << stacks.peek() << " from " << s << " to " << a << endl;
                stacka.push(stacks.peek());
                stacks.pop();
            }
            else
            {
                cout << "move " << stacka.peek() << " from " << a << " to " << s << endl;
                stacks.push(stacka.peek());
                stacka.pop();
            }
        }
        else if(i%3==0)// a and d
        {
            if(stacka.peek() < stackd.peek())
            {
                cout << "move " << stacka.peek() << " from " << a << " to " << d << endl;
                stackd.push(stacka.peek());
                stacka.pop();
            }
            else
            {
                cout << "move " << stackd.peek() << " from " << d << " to " << a << endl;
                stacka.push(stackd.peek());
                stackd.pop();
            }
        }
    }
}
int main()
{
    int n = 3;
    iterate(n);
}
