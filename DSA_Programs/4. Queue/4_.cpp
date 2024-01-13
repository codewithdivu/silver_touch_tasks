#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generateBinaryNumbers(int n)
{
    queue<string> binaryQueue;
    binaryQueue.push("1");

    for (int i = 1; i <= n; ++i)
    {
        string front = binaryQueue.front();
        binaryQueue.pop();

        cout << i << ": " << front << endl;

        binaryQueue.push(front + "0");
        binaryQueue.push(front + "1");
    }
}

int main()
{
    int num;

    cout << "Enter the number " << endl;
    cin >> num;

    generateBinaryNumbers(num);

    return 0;
}
