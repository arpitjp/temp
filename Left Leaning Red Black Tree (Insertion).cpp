//left leaning rbt
#include<bits/stdc++.h>
using namespace std;
#define null NULL

class node {
    public:
        int data;
        node *left;
        node *right;
        bool colour;
};
node* makenode(int val)
{
    node *n = new node();
    n->data = val;
    n->colour = 1;//red = 1
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
node* leftrot(node* root)
{
    node *b = root->right;
    node *d = b->left;
    b->left = root;
    root->right = d;
    return b;
}
node *rightrot(node *root)
{
    node *b = root->left;
    node *d = b->right;
    b->right = root;
    root->left = d;
    return b;
}
node* insert(node* root, int val)
{
    //simple bst inserrt
    if(root == null)
    {
        root = makenode(val);
        root->colour = 0;
        return root;
    }

    if(val<root->data)
    {
        root->left = insert(root->left, val);
    }
    else if(val>root->data)
    {
        root->right = insert(root->right, val);
    }
    else
        return null;
    
    //alterations cases
    //case1 right red, left black or null
    bool c;
    if(root->right->colour == 1 && (root->left == null ||  root->left->colour == 0))
    {
        root = leftrot(root);
        c = root->colour;
        root->colour = root->left->colour;
        root->left->colour = c;
    }
    //left red, left ka left red
    if (root->left != null && root->left->left !=null)
    {
        if (root->left->colour == 1 && root->left->left->colour == 1)
        {
            root = rightrot(root);
            c = root->colour;
            root->colour = root->right->colour;
            root->right->colour = c;
        }
    }
    //right child and left child both red
    if(root->left!=null && root->right!=null)
    {
        if (root->left->colour == 1 && root->right->colour == 1)
        {
            root->right->colour = 0;
            root->left->colour = 0;
            root->colour = 1;
        }
    }
        
    return root;
}
int main()
{
    node *root = null;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root);
}
