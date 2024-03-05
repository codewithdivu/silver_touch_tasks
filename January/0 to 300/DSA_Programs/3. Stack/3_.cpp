#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int checkPre(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > 'a' && s[i] < 'z' || s[i] > 'A' && s[i] < 'Z')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans = ans + s[i];
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && checkPre(st.top()) > checkPre(s[i]))
            {
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << InfixToPostfix("(a-b/c)*(a/k*l)");
    return 0;
}