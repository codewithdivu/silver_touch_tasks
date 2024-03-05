#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>

using namespace std;

int generateRandomNumber(const vector<double> &probabilities)
{
    double randomValue = static_cast<double>(rand()) / RAND_MAX;

    double cumulativeProbability = 0.0;
    for (size_t i = 0; i < probabilities.size(); ++i)
    {
        cumulativeProbability += probabilities[i];
        if (randomValue < cumulativeProbability)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    vector<double> probabilities = {0.2, 0.5, 0.3};

    double sumProbabilities = accumulate(probabilities.begin(), probabilities.end(), 0.0);
    if (sumProbabilities != 1.0)
    {
        cerr << "Error: Probabilities must sum to 1.0." << endl;
        return 1;
    }

    const int numSamples = 1000;
    vector<int> histogram(probabilities.size(), 0);

    for (int i = 0; i < numSamples; ++i)
    {
        int randomValue = generateRandomNumber(probabilities);
        histogram[randomValue]++;
    }

    cout << "Random numbers distribution:" << endl;
    for (size_t i = 0; i < histogram.size(); ++i)
    {
        cout << "Value " << i << ": " << static_cast<double>(histogram[i]) / numSamples << endl;
    }

    return 0;
}
