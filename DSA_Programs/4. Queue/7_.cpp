#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> myDeque;

    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);

    myDeque.push_front(0);
    myDeque.push_front(-1);

    cout << "Deque elements: ";
    for (const auto &element : myDeque)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "First element: " << myDeque.front() << endl;
    cout << "Last element: " << myDeque.back() << endl;

    myDeque.pop_front();

    myDeque.pop_back();

    cout << "Deque elements after removal: ";
    for (const auto &element : myDeque)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
