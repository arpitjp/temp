//push, pop, middle, delete
#include <bits/stdc++.h>
using namespace std;

class dll
{
public:
    int data;
    dll *next;
    dll *prev;
};

dll *create(int val)
{
    dll *n;
    n = new dll();
    n->data = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

class Stack
{
    dll *head = NULL;
    dll *mid = NULL;
    int count = 0;

public:
    void push(int val);
    void pop();
    void findmid();
    void delmid();
};

void Stack::push(int val)
{
    dll *n = create(val);
    if (count == 0)
    {
        head = n;
        mid = n;
        count++;
        cout << "successful, new top =\t" << head->data << "\tnew middle =\t" << mid->data << endl;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
    //shift middle up
    if (count % 2 == 0)
    {
        mid = mid->prev;
    }
    count++;
    cout << "successful, new top =\t" << head->data << "\tnew middle =\t" << mid->data << endl;
    return;
}

void Stack::pop()
{
    if (count == 0)
    {
        cout << "underflow :/" << endl;
        return;
    }
    dll *n = head;
    head = head->next;
    free(n);

    if (count % 2 == 1)
    {
        mid = mid->next;
    }
    count--;
    cout << "successfully popped" << endl;
}

void Stack::findmid()
{
    if (count == 0)
    {
        cout << "underflow :/" << endl;
        return;
    }
    else
        cout << "middle element is\t" << mid->data << endl;
}

void Stack::delmid()
{
    if (count == 0)
    {
        cout << "underflow :/" << endl;
        return;
    }
    if(count ==1)
    {
        free(mid);
        mid = NULL;
        head = NULL;
        count--;
        return;
    }
    if(count == 2)
    {
        dll *n = mid;
        mid = mid->prev;
        mid->next = NULL;
        count--;
        return;
    }

    dll *n = mid;
    if (count % 2 == 0)
    {
        mid = mid->prev;
        mid->next = n->next;
        n->next->prev = mid;
        free(n);
    }
    else if(count % 2 == 1)
    {
        mid = mid->next;
        mid->prev = n->prev;
        n->prev->next = mid;
        free(n);
    }
    count--;
}

int main()
{
    Stack s;
    s.pop();
    s.findmid();
    s.delmid();

    s.push(10);
    s.pop();
    s.findmid();
    s.delmid();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << endl;
    cout << endl;

    s.pop();
    s.findmid();
    s.pop();
    s.findmid();
    s.delmid();

    cout << endl;
    s.findmid();
    s.delmid();
    s.findmid();
    s.delmid();
    s.findmid();
    s.delmid();
    s.findmid();
    s.delmid();
    s.findmid();
    s.delmid();
}
