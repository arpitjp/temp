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
    n->left = NULL;
    n->right = NULL;
    return n;
}
void morris(node* root)
{
    node *temp;
    node *current = root;

    while(current!=null)
    {
        //left null hai
        if(current->left == null)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            temp = current->left;
            //find rightmost node of temp nad join it to current
            while(temp->right != null && temp->right != current)
                temp = temp->right;
            if(temp->right == current)
            {
                temp->right == null;
                cout << current->data << " ";
                current = current->right;
            }
            else
            {
                temp->right = current;
                current = current->left;
            }
        }
    }
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
    root->right->left = makenode(6);
    root->right->right = makenode(7);

    morris(root);
    cout << endl;
    //inorder(root);
    //preorder(root);
    //postorder(root);
}
