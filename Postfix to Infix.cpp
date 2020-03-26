//postfix to infix
#include<bits/stdc++.h>
using namespace std;

string PostfixToInfix(string exp)
{
    string s1, s2;
    stack<string> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if(isalpha(exp[i]))
            s.push(exp.substr(i, 1));
        else
        {
            s2 = s.top();
            s.pop();
            s1 = s.top();
            s.pop();
            s.push("(" + s1 + " " + exp.substr(i, 1) + " " + s2 + ")");
        }
    }
    return s.top();
}

int main()
{
    cout << PostfixToInfix("abcd^e-fgh*+^*+i-");
}
