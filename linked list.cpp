#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
};

void printshiz(node* h)
{
    while(h != NULL)
    {
        cout << h->data << endl;
        h = h->next;
    }
}

int main()
{
    node* n; // always make new node using n
    node* h; // h is head node
    node* t; // temprory node used to make connections

    n = new node();
    n->data = 20;
    h = n;
    t = n;

    n = new node();
    n->data = 30;
    t->next = n;
    t = n;

    n = new node();
    n->data = 40;
    t->next = n;
    n->next = NULL;

    printshiz(h);

}