#include<bits/stdc++.h>
using namespace std;
#define null NULL
#define max 100
bool mat[max][max] = {0};

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

//preorder root left right
void ancestorMatrix(node* root, vector<int>& v, int& sz)
{
    if(root == null)
        return;
    
    for (int i = 0; i < v.size(); i++)
    {
        mat[v[i]][root->data] = 1;
    }
    v.push_back(root->data);
    sz++;

    ancestorMatrix(root->left, v, sz);
    ancestorMatrix(root->right, v, sz);
    v.erase(v.end() - 1);

    return;
}

int main()
{
    node *root        = makenode(5); 
    root->left        = makenode(1); 
    root->right       = makenode(2); 
    root->left->left  = makenode(0); 
    root->left->right = makenode(4); 
    root->right->left = makenode(3);
    vector<int> v;
    int sz = 0;
    ancestorMatrix(root, v, sz);

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
