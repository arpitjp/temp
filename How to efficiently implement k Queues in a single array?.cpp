#include<bits/stdc++.h>
using namespace std;

class kqueue {
    int k;
    int n;
    int free;
    unique_ptr<int[]> array;
    unique_ptr<int[]> next;
    unique_ptr<int[]> front;
    unique_ptr<int[]> rear;

    public:
        kqueue(int k, int n);
        bool isempty(int k);
        bool isfull();
        void push(int k, int val);
        void pop(int k);
};

kqueue::kqueue(int k, int n)
    : k(k),
      n(n),
      free(0),
      array(new int[n]),
      next(new int[n]),
      front(new int[k]),
      rear(new int[k])
      {
        for (int i = 0; i < k; i++)
            front[k] = -1;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
      }
//
bool kqueue::isempty(int k)
{
    return (front[k] == -1);
}
bool kqueue::isfull()
{
    return (free == -1);
}
void kqueue::push(int k, int val)
{
    if(isfull())
    {
        cout << "overflow" << endl;
        return;
    }
    int i = free;
    free = next[free];
    array[i] = val;
    cout << val << " pushed to queue " << k << endl;

    if(front[k] == -1)
        front[k] = i;
    else
        next[rear[k]] = i;

    rear[k] = i;
    array[i] = val;
    next[i] = -1;
}
void kqueue::pop(int k)
{
    if(isempty(k))
    {
        cout << "underflow" << endl;
        return;
    }
    int i = front[k];
    cout << array[i] << " popped from queue " << k << endl;
    front[k] = next[front[k]];
    next[i] = free;
    free = i;
}
int main()
{
    kqueue q(3, 5);
    q.push(1, 1);
    q.push(1, 2);
    q.push(1, 3);
    q.pop(1);
    q.pop(1);
    q.pop(1);
    q.pop(1);
}
