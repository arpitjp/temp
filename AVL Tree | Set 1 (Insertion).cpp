#include<bits/stdc++.h>
using namespace std;
#define null NULL

class node {
    public:
        int data;
        int height;
        node *left;
        node *right;
};
node* makenode(int val)
{
    node *n = new node();
    n->data = val;
    n->height = 1;
    n->left = null;
    n->right = null;
    return n;
}
void preorder(node* root)
{
    if(root==null)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int height(node* root)
{
    if(root==null)
        return 0;
    return root->height;
}
node* rightrot(node* root)
{
    node *b = root->left;
    node *d = b->right;

    b->right = root;
    root->left = d;

    //update height
    root->height = max(height(root->left), height(root->right)) + 1;
    b->height = max(height(b->left), height(b->right)) + 1;

    return b;
}
node* leftrot(node* root)
{
    node *b = root->right;
    node *d = b->left;

    b->left = root;
    root->right = d;

    //update height
    root->height = max(height(root->left), height(root->right)) + 1;
    b->height = max(height(b->left), height(b->right)) + 1;

    return b;
}
int getbal(node* root)
{
    if(root == null)
        return 0;
    return height(root->left) - height(root->right);
}
node* insert(node* root, int val)
{
    //simple bst
    if(root == null)
        return makenode(val);

    if(val<root->data)
        root->left = insert(root->left, val);
    else if(val>root->data)
        root->right = insert(root->right, val);

    //upadte height of ancestor
    root->height = max(height(root->left), height(root->right)) + 1;
    //get balance
    int balance = getbal(root);

    //LL
    if(balance>1 && val<root->left->data)
        root =  rightrot(root);
    //RR
    else if(balance<-1 && val>root->right->data)
        root =  leftrot(root);
    //LR
    else if (balance > 1 && val > root->left->data)
    {
        root->left = leftrot(root->left);
        root =  rightrot(root);
    }
    //RL
    else if (balance < -1 && val < root->right->data)
    {
        root->right = rightrot(root->right);
        root =  leftrot(root);
    }
    return root;
}
int main()
{
    node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    cout << "Preorder traversal of the constructed AVL tree is " << endl;
    preorder(root);
}
