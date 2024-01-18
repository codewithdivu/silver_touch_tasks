#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

double objectiveFunction(const vector<double> &x)
{

    double sum = 0.0;
    for (double xi : x)
    {
        sum += xi * xi;
    }
    return sum;
}

vector<double> differentialEvolution(int populationSize, int dimension, int maxGenerations, double crossoverRate, double mutationFactor)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> randUniform(0.0, 1.0);

    vector<vector<double>> population(populationSize, vector<double>(dimension));
    for (int i = 0; i < populationSize; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            population[i][j] = randUniform(gen);
        }
    }

    for (int generation = 0; generation < maxGenerations; ++generation)
    {
        for (int i = 0; i < populationSize; ++i)
        {

            int r1, r2, r3;
            do
            {
                r1 = rand() % populationSize;
                r2 = rand() % populationSize;
                r3 = rand() % populationSize;
            } while (r1 == i || r2 == i || r3 == i || r1 == r2 || r1 == r3 || r2 == r3);

            vector<double> mutant(dimension);
            for (int j = 0; j < dimension; ++j)
            {
                mutant[j] = population[r1][j] + mutationFactor * (population[r2][j] - population[r3][j]);
            }

            for (int j = 0; j < dimension; ++j)
            {
                if (randUniform(gen) > crossoverRate)
                {
                    mutant[j] = population[i][j];
                }
            }

            double fMutant = objectiveFunction(mutant);
            double fCurrent = objectiveFunction(population[i]);

            if (fMutant < fCurrent)
            {
                population[i] = mutant;
            }
        }
    }

    double bestFitness = objectiveFunction(population[0]);
    vector<double> bestSolution = population[0];

    for (int i = 1; i < populationSize; ++i)
    {
        double fitness = objectiveFunction(population[i]);
        if (fitness < bestFitness)
        {
            bestFitness = fitness;
            bestSolution = population[i];
        }
    }

    return bestSolution;
}

int main()
{

    int populationSize = 50;
    int dimension = 10;
    int maxGenerations = 1000;
    double crossoverRate = 0.8;
    double mutationFactor = 0.5;

    vector<double> solution = differentialEvolution(populationSize, dimension, maxGenerations, crossoverRate, mutationFactor);

    cout << "Optimal Solution: [";
    for (double xi : solution)
    {
        cout << xi << " ";
    }
    cout << "]\n";

    cout << "Optimal Objective Value: " << objectiveFunction(solution) << endl;

    return 0;
}
