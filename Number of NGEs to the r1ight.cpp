#include<bits/stdc++.h>
using namespace std;

void nges(int* a, int n, int* ngesofnext)
{
    stack<int> s;
    for (int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && a[i]>a[s.top()])
            s.pop();
        ngesofnext[i] = (s.empty()) ? (0) : (ngesofnext[s.top()] +1 );
        s.push(i);
    }
}
int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int next[n];

    nges(a, n, next);
    for(auto i:next)
        cout << i << endl;
}
