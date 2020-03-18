#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
};

node* newNode(int key) 
{ 
    node* temp = new node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

void printlist(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//detects loop and give node where loop starts
node* detectloop(node* head)
{
    node* p1;
    node* p2;
    p1 = head;
    p2 = head;

    //check if loop exists
    do
    {
        p1 = p1->next;

        p2 = p2->next;
        if(p2==NULL) return NULL;
        p2 = p2->next;
        if(p2==NULL) return NULL;
    } while (p1!=p2);

    p1 = head;
    //return position of start of loop
    do
    {
        p1 = p1->next;
        p2 = p2->next;
    } while (p1!=p2);
    
    return p1;
}

void removeloop(node* status)
{
    node* temp = status->next;
    
    while (temp->next!=status)
        temp = temp->next;
    temp->next = NULL;
    
}

int main()
{
// Create a loop for testing
    node* head = newNode(50); 
    head->next = head; 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10);
    //linear list input 
    head->next->next->next->next->next = NULL;

    //cyclic loop input
    //head->next->next->next->next->next = head->next->next;

//process
    node* status = detectloop(head);
    if(status!=NULL) 
        removeloop(status);
    
    printlist(head);
}