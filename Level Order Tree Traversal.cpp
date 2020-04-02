//level order tree transversal
// using function

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *makenode(int data)
{
    node *n;
    n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// O(n2) time complexity :{}
/*
int height(node *root)
{
    if (root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return (lheight >= rheight) ? (lheight + 1) : (rheight + 1);
}
void printlevel(int h, node *root)
{
    if (root == NULL)
        return;
    if (h == 1)
        cout << root->data << " ";
    printlevel(h - 1, root->left);
    printlevel(h - 1, root->right);
}
void transversal(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printlevel(i, root);
}
*/

void queueprint(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        cout << q.front()->data << " ";
        if(q.front()->left != NULL)
            q.push(q.front()->left);
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
    }
    return;
}

int main()
{
    node *root = makenode(1);
    root->left = makenode(2);
    root->right = makenode(3);
    root->left->left = makenode(4);
    root->left->right = makenode(5);
    //transversal(root);
    queueprint(root);
}
