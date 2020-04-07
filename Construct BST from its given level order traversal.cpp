#include<bits/stdc++.h>
using namespace std;
#define null NULL

class node {
    public:
        int data;
        node *left;
        node *right;
};
node* makenode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = null;
    n->right = null;
    return n;
}
void inorder(node* root)
{
    if(root == null)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node* insert(node* root, int val)
{
    if(root == null)
        return makenode(val);

    if(val<root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
node* makebst(node* root, int* arr, int n)
{
    if(n==0)
        return null;
    root = makenode(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(arr[i] <= root->data)
            root->left = insert(root->left, arr[i]);
        else
            root->right = insert(root->right, arr[i]);
    }
    return root;
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    node *root = null;
    root = makebst(root, arr, sizeof(arr)/sizeof(arr[0]));

    inorder(root);
    cout << endl;
}
