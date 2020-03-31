//circular queue :)
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int capacity;
    unique_ptr<int[]> array;

public:
    Queue(int capacity);
    void enqueue(int val);
    void dequeue();
    int getfront();
    int getback();
    bool isempty();
    bool isfull();
};
Queue::Queue(int capacity)
    : size(0),
      capacity(capacity),
      array(new int[capacity]),
      front(0),
      rear(capacity - 1){};
//
bool Queue::isempty()
{
    return (size == 0);
}
bool Queue::isfull()
{
    return (size == capacity);
}
void Queue::enqueue(int val)
{
    if (isfull())
    {
        dequeue();
        //cout << "overflow :/" << endl;
        //return;
    }
    rear = (rear + 1) % capacity;
    array[rear] = val;
    size++;
}

void Queue::dequeue()
{
    if (isempty())
    {
        cout << "underflow :/" << endl;
        return;
    }
    front = (front+1)%capacity;
    size--;
}

int Queue::getfront()
{
    return (isempty()) ? (INT_MIN) : (array[front]);
}

int Queue::getback()
{
    return (isempty()) ? (INT_MIN) : (array[rear]);
}

int main()
{
    Queue q(5);
    cout << q.getback() << endl;
    cout << q.getfront() << endl;
    cout << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout << q.getfront() << endl;
    cout << q.getback() << endl;                           
    //q.dequeue();
    //q.enqueue(6);

    while (!q.isempty())
    {
        cout << q.getfront() << " ";
        q.dequeue();
    }
}
