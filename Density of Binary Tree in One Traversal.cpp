#include<bits/stdc++.h>
using namespace std;
#define null NULL

class node {
    public:
        int data;
        node *left;
        node *right;
};
node *makenode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = null;
    n->right = null;
    return n;
}
int findheight(int& sz, node* temp)
{
    if(temp == null)
        return 0;
    sz++;
    return max(findheight(sz, temp->left), findheight(sz, temp->right)) + 1;
}
int main()
{
    node *root = makenode(1);
    root->left = makenode(2);
    root->right = makenode(3);
    root->right->left = makenode(3);
    root->right->right = makenode(3);
    root->left->left = makenode(4);
    root->left->right = makenode(5);
    root->left->left->left = makenode(6);
    int sz = 0;
    int height = findheight(sz, root);
    cout << heigt << endl;
}
