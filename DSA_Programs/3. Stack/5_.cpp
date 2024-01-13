#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "enter a string" << endl;
    cin >> str;

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    string answer = "";
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    cout << answer << endl;

    return 0;
}