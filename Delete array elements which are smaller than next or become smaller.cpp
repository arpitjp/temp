#include<bits/stdc++.h>
using namespace std;

template<typename T>
void deleteElements(T& arr, int k)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    stack<int> s;
    s.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        while(!s.empty() && count < k && s.top() < arr[i] )
        {
            s.pop();
            count++;
        }
        s.push(arr[i]);
    }

    int m = s.size(); 
    vector<int> v(m); // Size of vector is m 
    while (!s.empty()) { 
          
        // push element from stack to vector v 
        v[--m] = s.top(); 
        s.pop(); 
    } 
      
    // printing result 
    for (auto x : v) 
        cout << x << " "; 
          
    cout << endl; 
}
int main()
{
    int k = 2;
    int arr[] = {20, 10, 25, 30, 40};
    deleteElements(arr, k);
}
