#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> reservoirSampling(const vector<int> &stream, int k)
{
    vector<int> reservoir(k);

    for (int i = 0; i < k; ++i)
    {
        reservoir[i] = stream[i];
    }

    for (int i = k; i < stream.size(); ++i)
    {

        int randomIndex = rand() % (i + 1);

        if (randomIndex < k)
        {
            reservoir[randomIndex] = stream[i];
        }
    }

    return reservoir;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> stream;
    for (int i = 1; i <= 100; ++i)
    {
        stream.push_back(i);
    }

    int k = 5;
    vector<int> sampledItems = reservoirSampling(stream, k);

    cout << "Sampled items: ";
    for (int item : sampledItems)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
