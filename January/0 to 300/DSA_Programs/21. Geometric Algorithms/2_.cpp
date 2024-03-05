#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

struct Rectangle
{
    Point topLeft, bottomRight;
};

bool doRectanglesOverlap(const Rectangle &rect1, const Rectangle &rect2)
{
    if (rect1.bottomRight.x < rect2.topLeft.x || rect2.bottomRight.x < rect1.topLeft.x)
        return false;

    if (rect1.bottomRight.y < rect2.topLeft.y || rect2.bottomRight.y < rect1.topLeft.y)
        return false;

    return true;
}

int main()
{
    Rectangle rect1, rect2;

    cout << "Enter coordinates for the top-left corner of the first rectangle:" << endl;
    cout << "X: ";
    cin >> rect1.topLeft.x;
    cout << "Y: ";
    cin >> rect1.topLeft.y;

    cout << "Enter coordinates for the bottom-right corner of the first rectangle:" << endl;
    cout << "X: ";
    cin >> rect1.bottomRight.x;
    cout << "Y: ";
    cin >> rect1.bottomRight.y;

    cout << "Enter coordinates for the top-left corner of the second rectangle:" << endl;
    cout << "X: ";
    cin >> rect2.topLeft.x;
    cout << "Y: ";
    cin >> rect2.topLeft.y;

    cout << "Enter coordinates for the bottom-right corner of the second rectangle:" << endl;
    cout << "X: ";
    cin >> rect2.bottomRight.x;
    cout << "Y: ";
    cin >> rect2.bottomRight.y;

    if (doRectanglesOverlap(rect1, rect2))
        cout << "Rectangles overlap." << endl;
    else
        cout << "Rectangles do not overlap." << endl;

    return 0;
}
