#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (str[i] == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (str[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string str;
    cout << "enter a string" << endl;
    cin >> str;

    if (isBalanced(str))
    {
        cout << "String is balanced" << endl;
    }
    else
    {
        cout << "string is not balanced" << endl;
    }

    return 0;
}