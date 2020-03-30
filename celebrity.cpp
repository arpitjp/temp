//stack, recur, 2 pointers
// extra step needed to ensure whether a celebrity exists or not
#include <bits/stdc++.h>
using namespace std;

template <typename T>
int celebrity_Stack(T &MATRIX, int n)
{
    stack<int> s;
    int top;
    for (int i = 0; i < n - 1; i++)
        s.push(i);
    top = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (MATRIX[top][s.top()] == 1)
        {
            top = s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    return top;
}

template <typename T>
int celebrity_2Pointers(T &MATRIX, int n)
{
    int f, l;
    f = 0;
    l = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (MATRIX[f][l] == 1)
        {
            f++;
        }
        else
            l--;
    }
    return l;
}

template <typename T>
int celebrity_Recur(T &MATRIX, int n)
{
    if (n == 0)
        return n;
    int temp = celebrity_Recur(MATRIX, n - 1);
    return (MATRIX[n][temp] == 1) ? (temp) : (n);
}
int main()
{
    bool MATRIX[4][4] = {{0, 0, 0, 1},
                         {0, 0, 0, 1},
                         {0, 0, 0, 1},
                         {0, 0, 0, 1}};

    cout << celebrity_2Pointers(MATRIX, 4) << endl;
    cout << celebrity_Recur(MATRIX, 3) << endl;
    cout << celebrity_Stack(MATRIX, 4) << endl;
}
