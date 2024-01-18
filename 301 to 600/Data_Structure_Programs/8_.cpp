#include <iostream>
#include <string>
#include <vector>

using namespace std;

void processQuery(string &S, const vector<int> &query)
{
    int operation = query[0];
    int segmentIndex = query[1];

    if (operation == 1)
    {
    }
    else if (operation == 2)
    {
    }
}

int main()
{
    string S = "AABBBCCCC";
    vector<vector<int>> queries = {{1, 0}, {2, 1}, {1, 0}, {2, 2}, {1, 3}};

    for (const auto &query : queries)
    {
        processQuery(S, query);
    }

    cout << S << endl;

    return 0;
}
