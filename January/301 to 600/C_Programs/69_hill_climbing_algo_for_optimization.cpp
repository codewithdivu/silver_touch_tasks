#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

double objectiveFunction(const vector<double> &solution)
{

    double sum = 0.0;
    for (double xi : solution)
    {
        sum += xi * xi;
    }
    return sum;
}

vector<double> hillClimbing(int dimensions, double stepSize, int maxIterations)
{

    vector<double> currentSolution(dimensions);
    for (int i = 0; i < dimensions; ++i)
    {
        currentSolution[i] = (rand() % 2001 - 1000) / 100.0;
    }

    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {

        vector<double> neighborSolution = currentSolution;
        int indexToChange = rand() % dimensions;
        neighborSolution[indexToChange] += (rand() % 2001 - 1000) / 100.0 * stepSize;

        double currentCost = objectiveFunction(currentSolution);
        double neighborCost = objectiveFunction(neighborSolution);

        if (neighborCost < currentCost)
        {
            currentSolution = neighborSolution;
        }
    }

    return currentSolution;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int dimensions = 3;
    double stepSize = 0.1;
    int maxIterations = 1000;

    vector<double> result = hillClimbing(dimensions, stepSize, maxIterations);

    cout << "Optimal Solution: [";
    for (double xi : result)
    {
        cout << xi << " ";
    }
    cout << "]\n";

    cout << "Optimal Objective Value: " << objectiveFunction(result) << endl;

    return 0;
}
