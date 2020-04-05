#include<bits/stdc++.h>
using namespace std;

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
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(node* temp)
{
    if(temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void preorder(node* temp)
{
    if(temp == NULL)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(node* temp)
{
    if(temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}
int main()
{
    node *root = makenode(1);
    root->left = makenode(2);
    root->right = makenode(3);
    root->left->left = makenode(4);
    root->left->right = makenode(5);

    //inorder(root);
    //preorder(root);
    postorder(root);
    cout << endl;
}
