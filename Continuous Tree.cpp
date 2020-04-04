// C++ program to check if a tree is continuous or not
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
};
node *newNode(int data)
{
    node *n = new node();
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

bool treeContinuous(node*& temp)
{
    if(temp == NULL)
        return 1;

    if (temp->left == NULL && temp->right == NULL)
        return true;
    if(temp->left == NULL && temp->right != NULL)
        return (abs(temp->right->data - temp->data) == 1 && treeContinuous(temp->right));
    if(temp->left != NULL && temp->right == NULL)
        return (abs(temp->left->data - temp->data) == 1 && treeContinuous(temp->left));

    return (abs(temp->left->data - temp->data) ==1 && abs(temp->right->data - temp->data) ==1 && treeContinuous(temp->left) && treeContinuous(temp->right));
}

int main()
{
    node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(10);
    treeContinuous(root) ? cout << "Yes" << endl : cout << "No" << endl;
}
