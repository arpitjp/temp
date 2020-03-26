//infix to postfix
#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c == '+' || c == '-')
        return 0;
    if(c == '*' || c == '/')
        return 1;
    if(c == '^')
        return 2;
    return -1;
}

string infixToPostfix(string exp)
{
    stack<char> s;
    string ans;

    for (char i : exp )
    {
        if(i == '(')
            s.push(i);
        else if(i == ')')
        { 
            while(s.top()!='(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }
        else if(precedence(i)==-1)
            ans += i;
        else
        {//operator except brackets
            if(s.empty())
                s.push(i);
            else if (precedence(i) > precedence(s.top()) || s.top() == '(')
                s.push(i);
            else
            {
                while(precedence(i)<=precedence(s.top()) && s.top()!='(')
                {
                    ans += s.top();
                    s.pop();
                    if(s.empty())
                        break;
                }
                s.push(i);
            }
        }
    }
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp) << endl;
}
