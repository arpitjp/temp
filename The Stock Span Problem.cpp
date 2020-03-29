#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int *price, int n, int* span)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while( !s.empty() && price[i]>price[s.top()])
        {
            s.pop();
        }
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());
        s.push(i);
    }
}
int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85}; 
    int n = sizeof(price) / sizeof(price[0]); 
    int S[n]; 
  
    calculateSpan(price, n, S);
    
    for(auto i:S)
        cout << i << endl;
}
