#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int overlap(const string &a, const string &b)
{
    int maxOverlap = 0;
    int lenA = a.length();
    int lenB = b.length();

    for (int i = 1; i <= min(lenA, lenB); ++i)
    {
        if (a.substr(lenA - i) == b.substr(0, i))
        {
            maxOverlap = i;
        }
    }

    return maxOverlap;
}


string mergeStrings(const string &a, const string &b, int overlapLength)
{
    return a + b.substr(overlapLength);
}


string shortestSuperstring(const vector<string> &strings)
{
    int n = strings.size();

    while (n > 1)
    {
        int maxOverlap = INT_MIN;
        int overlapI = -1, overlapJ = -1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int currentOverlap = overlap(strings[i], strings[j]);

                if (currentOverlap > maxOverlap)
                {
                    maxOverlap = currentOverlap;
                    overlapI = i;
                    overlapJ = j;
                }
            }
        }

        if (maxOverlap == INT_MIN)
        {
            break; 
        }

        
        strings[overlapI] = mergeStrings(strings[overlapI], strings[overlapJ], maxOverlap);

        
        strings.erase(strings.begin() + overlapJ);

        --n;
    }

    return strings[0];
}

int main()
{
    vector<string> strings = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"};

    string result = shortestSuperstring(strings);

    cout << "Shortest Superstring: " << result << endl;

    return 0;
}
