#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void printAllPalindromicPartitions(string &str)
{
    int n = str.length();

    for (int mask = 0; mask < (1 << (n - 1)); ++mask)
    {
        vector<string> partitions;

        int start = 0;
        for (int end = 0; end < n; ++end)
        {
            if (mask & (1 << end))
            {

                partitions.push_back(str.substr(start, end - start + 1));
                start = end + 1;
            }
        }

        partitions.push_back(str.substr(start));

        bool isPalindromePartition = true;
        for (string &partition : partitions)
        {
            if (!isPalindrome(partition, 0, partition.length() - 1))
            {
                isPalindromePartition = false;
                break;
            }
        }

        if (isPalindromePartition)
        {
            cout << "Palindromic Partition: ";
            for (const string &partition : partitions)
            {
                cout << partition << " ";
            }
            cout << endl;
        }
    }
}

int main()
{

    string input1 = "nitin";
    cout << "Input 1:\n";
    printAllPalindromicPartitions(input1);

    string input2 = "geeks";
    cout << "\nInput 2:\n";
    printAllPalindromicPartitions(input2);

    return 0;
}
