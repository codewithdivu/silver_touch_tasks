#include <bits/stdc++.h>
using namespace std;

int PostEvalution(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(operand2 + operand1);
                break;
            case '-':
                st.push(operand2 - operand1);
                break;
            case '*':
                st.push(operand2 * operand1);
                break;
            case '/':
                st.push(operand2 / operand1);
                break;
            case '^':
                st.push(pow(operand2, operand1));
                break;
            }
        }
    }
    return st.top();
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;

    cout << PostEvalution(str) << endl;
    return 0;
}