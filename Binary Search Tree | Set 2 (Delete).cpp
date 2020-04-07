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
node* insert(node* root, int val)
{
    if(root == null)
        root = makenode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    if(val>root->data)
        root->right = insert(root->right, val);

    return root;
}
void inorder(node* root)
{
    if(root == null)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node* minright(node* root)
{
    if(root->left == null)
        return root;
    return minright(root->left);
}

node *deleteNode(node* root, int val)
{
    if(root == null)
        return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);

    else
    {
        //val == root->data
        if (root->left == null) //left null or both null
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == null) //left confirm null nhi
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = minright(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    

    return root;
}
int main()
{
    node *root = null;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
}
