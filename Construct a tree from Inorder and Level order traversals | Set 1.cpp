#include<bits/stdc++.h>
using namespace std;
#define null NULL
class node {
    public:
        int data;
        node *left, *right;
};
node *makenode(int val)
{
    node *n = new node();
    n->data = val;
    n->left = null;
    n->right = null;
    return n;
}
int search(int val, int in[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(in[i] == val)
        {
            temp = i;
            break;
        }
    }
    return temp;
}
int * extract(int level[], int n, int in[], int m)
{
    int *temp = new int[m];
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(level[i] == in[j])
            {
                temp[c++] = level[i];
                continue;
            }
        }
    }
    return temp;
}
node* buildTree(int level[], int in[], int n)
{
    if(n<=0)
        return null;
    
    if(n==1)
    {
        node *root = makenode(level[0]);
        return root;
    }

    node *root = makenode(level[0]);
    int index = search(root->data, in, n);

    int *llevel = extract(level + 1, n - 1, in, index);
    int *rlevel = extract(level + 1, n - 1, in + index + 1, n - index - 1);

    root->left = buildTree(llevel, in, index);
    root->right = buildTree(rlevel, in + index + 1, n - index - 1);

    delete[] llevel;
    delete[] rlevel;
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
int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14}; 
    int n = sizeof(in)/sizeof(in[0]); 
    node *root = buildTree(level, in, n);
    inorder(root);
    cout << endl;
}
