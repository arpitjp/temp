//circular queue :)
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int capacity;
    shared_ptr<int[]> array;
    //unique pointers prvent class Queue to have copy constructor
    //unique_ptr<int[]> array;

    public:
    Queue(int capacity);
    void insertback(int val);
    void insertfront(int val);
    void removefront();
    void removeback();
    int getfront();
    int getback();
    bool isempty()
    {
        return (size == 0);
    }
    bool isfull()
    {
        return (size == capacity);
    }
};
Queue::Queue(int capacity)
    : front(0),
      rear(capacity - 1),
      size(0),
      capacity(capacity),
      array(new int[capacity]){};
//
void Queue::insertback(int val)//enqueue
{
    if(isfull())
    {
        cout << "overflow :/" << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    array[rear] = val;
    size++;
}
void Queue::insertfront(int val)//reverse enqueue
{
    if(isfull())
    {
        cout << "overflow :/" << endl;
        return;
    }
    front = ((front == 0) ? (capacity - 1) : (front - 1));
    size++;
    array[front] = val;
}
void Queue::removefront()//dequeue
{
    if(isempty())
    {
        cout << "underflow :/" << endl;
        return;
    }
    front = (front+1)%capacity;
    size--;
}
void Queue::removeback()
{
    if(isempty())
    {
        cout << "underflow :/" << endl;
        return;
    }
    rear = (rear == 0) ? (capacity - 1) : rear - 1;
    size--;
}
int Queue::getfront()
{
    return (isempty()) ? INT_MIN : array[front];
}
int Queue::getback()
{
    return (isempty()) ? INT_MIN : array[rear];
}
void qprint(Queue q)
{
    cout << endl;
    while (!q.isempty())
    {
        cout << q.getfront() << " ";
        q.removefront();
    }
}
int main()
{
    Queue q(5);
    cout << q.getback() << endl;
    cout << q.getfront() << endl;
    cout << endl;

    q.insertback(1);
    q.insertback(2);
    q.insertback(3);
    q.insertfront(4);
    q.insertfront(5);
    q.insertfront(6);
    qprint(q);

    q.removefront();
    q.removeback();
    qprint(q);
    q.insertback(3);
    q.insertback(4);
    q.insertback(5);
    qprint(q);
}
