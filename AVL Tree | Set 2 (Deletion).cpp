//AVL INSERTION DELETION

//delete mai rotation mai >=0 ka dhyan rakhna
//deletion mai first unvalanced sai recursively root tal jjaega but vo apne app hoga
 
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

    root->height = max(height(root->left), height(root->right)) + 1;
    b->height = max(height(b->left), height(b->right)) + 1;

    return b;
}
node* leftrot(node* root)
{
    node* b = root->right;
    node* d = b->left;

    b->left = root;
    root->right = d;

    root->height = max(height(root->left), height(root->right)) + 1;
    b->height = max(height(b->left), height(b->right)) + 1;

    return b;
}
node* insert(node* root, int val)
{
    //bst insert
    if(root == null)
        return makenode(val);
    
    if(val<root->data)
        root->left = insert(root->left, val);
    else if(val>root->data)
        root->right = insert(root->right, val);
    
    //update height of ancestor
    root->height = max(height(root->left), height(root->right)) + 1;

    //get balance to check well balance
    int balance = height(root->left) - height(root->right);

    //LL
    if(balance>1 && val<root->left->data)
        root = rightrot(root);
    //RR
    else if(balance<-1 && val>root->right->data)
        root = leftrot(root);
    //LR
    else if(balance>1 && val>root->left->data)
    {
        root->left = leftrot(root->left);
        root = rightrot(root);
    }
    //RL
    else if(balance<-1 && val<root->right->data)
    {
        root->right = rightrot(root->right);
        root = leftrot(root);
    }
    return root;
}
int getbal(node* root)
{
    if(root==null)
        return 0;
    return height(root->left) - height(root->right);
}
node* minvalue(node* root)
{
    if(root->left==null)
        return root;
    return minvalue(root->left);
}
node* deletenode(node* root, int val)
{
    //standard bst delete
    if(root == null)
        return root;

    if(val<root->data)
        root->left = deletenode(root->left, val);
    else if(val>root->data)
        root->right = deletenode(root->right, val);
    else//val == root->data
    {
        //both child or left null
        if(root->left==null)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == null)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // both not null
        node *temp = minvalue(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }

    //if root was the only node
    if(root==null)
        return root;
    
    //update height
    root->height = max(height(root->left), height(root->right)) + 1;

    //getbalance
    int balance = getbal(root);

    //LL
    if(balance>1 && getbal(root->left) >= 0)
        root = rightrot(root);
    //RR
    else if(balance<-1 && getbal(root->right)<=0)
        root = leftrot(root);
    //LR
    else if(balance>1 && getbal(root->left)<0)
    {
        root->left = leftrot(root->left);
        root = rightrot(root);
    }
    //RL
    else if(balance<-1 && getbal(root->right)>0)
    {
        root->right = rightrot(root->right);
        root = leftrot(root);
    }
    return root;
}
int main()
{
    node *root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preorder(root);

    root = deletenode(root, 10);

    cout << "\nPreorder traversal after deletion of 10 \n";
    preorder(root);
}
