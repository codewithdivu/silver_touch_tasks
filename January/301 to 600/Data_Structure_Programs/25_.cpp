#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int selectRandomFromStream(int &currentRandom, int newItem, int itemCount)
{
    srand(time(nullptr));

    itemCount++;

    int randomIndex = rand() % itemCount;

    if (randomIndex == 0)
    {
        currentRandom = newItem;
    }

    return currentRandom;
}

int main()
{
    int currentRandom = -1;
    int itemCount = 0;

    int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; ++i)
    {
        int selectedRandom = selectRandomFromStream(currentRandom, stream[i], itemCount);
        itemCount++;

        cout << "Random number from the stream: " << selectedRandom << endl;
    }

    return 0;
}
