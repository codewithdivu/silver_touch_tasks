#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int i, int j)
{
    if (i == a.length())
    {
        return 0;
    }
    if (j == b.length())
    {
        return 0;
    }
    int ans = 0;
    if (a[i] == b[j])
    {
        return 1 + lcs(a, b, i + 1, j + 1);
    }
    else
    {
        int ans = max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
    }
    return ans;
}

int main()
{
    string a = "abcdef";
    string b = "abc";

    int ans = lcs(a, b, 0, 0);

    cout << "Longest Common Subsequence length is " << ans << endl;

    return 0;
}