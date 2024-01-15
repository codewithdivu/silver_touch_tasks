#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findIntersection(const vector<int> &arr1, const vector<int> &arr2)
{
    unordered_set<int> hashSet(arr1.begin(), arr1.end());

    vector<int> intersection;

    for (int num : arr2)
    {
        if (hashSet.count(num))
        {
            intersection.push_back(num);
            cout << num << " ";
            hashSet.erase(num);
        }
    }

    return intersection;
}

int main()
{
    int size1, size2;

    cout << "Enter the size of the first array: ";
    cin >> size1;

    vector<int> arr1(size1);

    cout << "Enter elements of the first array: ";
    for (int i = 0; i < size1; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> size2;

    vector<int> arr2(size2);

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < size2; ++i)
    {
        cin >> arr2[i];
    }

    vector<int> intersection = findIntersection(arr1, arr2);

    if (intersection.empty())
    {
        cout << "No intersection found." << endl;
    }
    else
    {
        cout << "Intersection of the two arrays: ";
        for (int num : intersection)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
