#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isDistinct(const vector<int> &input)
{
    int n = input.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (input[i] == input[j])
            {
                return false;
            }
        }
    }

    return true;
}

bool quantumOracle(const vector<int> &input)
{
    int n = input.size();
    int numQueries = static_cast<int>(sqrt(n));

    for (int q = 0; q < numQueries; ++q)
    {

        if (!isDistinct(input))
        {
            return false;
        }
    }

    return true;
}

int main()
{

    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    bool result = quantumOracle(input);

    cout << "All elements are distinct: " << (result ? "Yes" : "No") << endl;

    return 0;
}
