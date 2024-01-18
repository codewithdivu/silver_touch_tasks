#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double targetFunction(double x)
{

    return x * x + 2 * x + 1;
}

struct GeneticProgram
{
    vector<double> coefficients;
    double fitness;

    GeneticProgram(int degree)
    {
        coefficients.resize(degree + 1);
        for (double &coef : coefficients)
        {
            coef = rand() % 21 - 10;
        }
        fitness = 0.0;
    }

    double evaluate(double x) const
    {
        double result = 0.0;
        for (int i = 0; i < coefficients.size(); ++i)
        {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    void calculateFitness()
    {
        fitness = 0.0;
        const int numSamples = 100;
        const double interval = 2.0;
        for (int i = 0; i < numSamples; ++i)
        {
            double x = -1.0 + i * (interval / (numSamples - 1));
            double error = evaluate(x) - targetFunction(x);
            fitness -= error * error;
        }
    }
};

class GeneticProgramming
{
private:
    vector<GeneticProgram> population;
    const int populationSize;
    const int maxGenerations;
    const int polynomialDegree;

public:
    GeneticProgramming(int popSize, int maxGen, int degree)
        : populationSize(popSize), maxGenerations(maxGen), polynomialDegree(degree) {}

    void initializePopulation()
    {
        srand(static_cast<unsigned>(time(0)));
        population.clear();
        for (int i = 0; i < populationSize; ++i)
        {
            population.push_back(GeneticProgram(polynomialDegree));
        }
    }

    void evolvePopulation()
    {
        for (int generation = 0; generation < maxGenerations; ++generation)
        {
            evaluatePopulation();
            selection();
            crossover();
            mutation();
        }
        evaluatePopulation();
    }

    void printBestProgram() const
    {
        const GeneticProgram &bestProgram = *max_element(population.begin(), population.end(),
                                                         [](const GeneticProgram &p1, const GeneticProgram &p2)
                                                         {
                                                             return p1.fitness < p2.fitness;
                                                         });
        cout << "Best Genetic Program:\n";
        cout << "Fitness: " << bestProgram.fitness << endl;
        cout << "Coefficients: ";
        for (double coef : bestProgram.coefficients)
        {
            cout << coef << " ";
        }
        cout << endl;
    }

private:
    void evaluatePopulation()
    {
        for (GeneticProgram &program : population)
        {
            program.calculateFitness();
        }
    }

    void selection()
    {
        vector<GeneticProgram> newPopulation;
        for (int i = 0; i < populationSize; ++i)
        {
            int index1 = rand() % populationSize;
            int index2 = rand() % populationSize;
            const GeneticProgram &parent1 = population[index1];
            const GeneticProgram &parent2 = population[index2];
            newPopulation.push_back(parent1.fitness > parent2.fitness ? parent1 : parent2);
        }
        population = move(newPopulation);
    }

    void crossover()
    {
        for (int i = 0; i < populationSize; i += 2)
        {
            int crossoverPoint = rand() % (polynomialDegree + 1);
            for (int j = crossoverPoint; j <= polynomialDegree; ++j)
            {
                swap(population[i].coefficients[j], population[i + 1].coefficients[j]);
            }
        }
    }

    void mutation()
    {
        for (GeneticProgram &program : population)
        {
            if (rand() % 100 < 5)
            {
                int mutationIndex = rand() % (polynomialDegree + 1);
                program.coefficients[mutationIndex] += (rand() % 21 - 10);
            }
        }
    }
};

int main()
{

    const int populationSize = 100;
    const int maxGenerations = 100;
    const int polynomialDegree = 2;

    GeneticProgramming gp(populationSize, maxGenerations, polynomialDegree);
    gp.initializePopulation();
    gp.evolvePopulation();
    gp.printBestProgram();

    return 0;
}
