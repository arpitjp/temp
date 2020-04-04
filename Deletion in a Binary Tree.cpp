#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *newnode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void deleteKey(node *&root, int key)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            root = NULL;
        return;
    }

    node *deep, *temp;
    queue<node *> q;
    q.push(root);

    //level order transversal
    while (!q.empty())
    {
        if (q.front()->data == key)
            temp = q.front();

        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        deep = q.front();
        q.pop();
    }
    temp->data = deep->data;
    delete (deep->left);
    delete (deep->right);
    //deep = NULL;
    delete (deep);
    return;
}
int main()
{
    node *root = newnode(10);
    root->left = newnode(11);
    root->left->left = newnode(7);
    root->left->right = newnode(12);
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);

    inorder(root);
    deleteKey(root, 11);
    cout << endl;
    inorder(root);
}
