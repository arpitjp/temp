#include <bits/stdc++.h>
using namespace std;

int findpartition(int pre[], int n)
{
    int temp = pre[0];
    for (int i = 1; i < n; i++)
    {
        if (pre[i] > temp)
            return i;
    }
    return n; //greatest mila hi nhi
}
void findPostOrder(int pre[], int n)
{
    if (n == 0)
        return;

    int root = pre[0];
    int index = findpartition(pre, n);

    findPostOrder(pre + 1, index - 1);
    findPostOrder(pre + index, n - index);
    cout << root << " ";
}
int main()
{
    int pre[] = {40, 30, 32, 35, 80, 90, 100, 120};

    int n = sizeof(pre) / sizeof(pre[0]);

    // Calling function
    findPostOrder(pre, n);
    cout << endl;
    return 0;
}
