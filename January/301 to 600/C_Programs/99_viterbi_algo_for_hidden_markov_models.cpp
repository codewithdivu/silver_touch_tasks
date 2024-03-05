#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class HMM
{
public:
    vector<string> states;
    vector<string> observations;
    vector<vector<double>> transitionProb;
    vector<vector<double>> emissionProb;
    vector<double> initialProb;

    HMM(const vector<string> &states, const vector<string> &observations,
        const vector<vector<double>> &transitionProb,
        const vector<vector<double>> &emissionProb,
        const vector<double> &initialProb)
        : states(states), observations(observations),
          transitionProb(transitionProb), emissionProb(emissionProb),
          initialProb(initialProb) {}

    vector<string> viterbi(const vector<string> &observationSequence)
    {
        int numStates = states.size();
        int numObservations = observationSequence.size();

        vector<vector<double>> viterbiMatrix(numStates, vector<double>(numObservations, 0.0));
        vector<vector<int>> backpointerMatrix(numStates, vector<int>(numObservations, 0));

        for (int i = 0; i < numStates; ++i)
        {
            viterbiMatrix[i][0] = initialProb[i] * emissionProb[i][getIndex(observations, observationSequence[0])];
        }

        for (int t = 1; t < numObservations; ++t)
        {
            for (int j = 0; j < numStates; ++j)
            {
                double maxProbability = 0.0;
                int backpointer = 0;

                for (int i = 0; i < numStates; ++i)
                {
                    double probability = viterbiMatrix[i][t - 1] * transitionProb[i][j] * emissionProb[j][getIndex(observations, observationSequence[t])];
                    if (probability > maxProbability)
                    {
                        maxProbability = probability;
                        backpointer = i;
                    }
                }

                viterbiMatrix[j][t] = maxProbability;
                backpointerMatrix[j][t] = backpointer;
            }
        }

        double maxFinalProbability = 0.0;
        int finalState = 0;

        for (int i = 0; i < numStates; ++i)
        {
            if (viterbiMatrix[i][numObservations - 1] > maxFinalProbability)
            {
                maxFinalProbability = viterbiMatrix[i][numObservations - 1];
                finalState = i;
            }
        }

        vector<string> stateSequence(numObservations);
        stateSequence[numObservations - 1] = states[finalState];

        for (int t = numObservations - 2; t >= 0; --t)
        {
            finalState = backpointerMatrix[finalState][t + 1];
            stateSequence[t] = states[finalState];
        }

        return stateSequence;
    }

private:
    int getIndex(const vector<string> &vec, const string &element)
    {
        auto it = find(vec.begin(), vec.end(), element);
        if (it != vec.end())
        {
            return distance(vec.begin(), it);
        }
        return -1;
    }
};

int main()
{

    vector<string> states = {"Healthy", "Fever"};
    vector<string> observations = {"Normal", "Cold", "Dizzy"};
    vector<vector<double>> transitionProb = {{0.7, 0.3}, {0.4, 0.6}};
    vector<vector<double>> emissionProb = {{0.5, 0.4, 0.1}, {0.1, 0.3, 0.6}};
    vector<double> initialProb = {0.6, 0.4};

    HMM hmm(states, observations, transitionProb, emissionProb, initialProb);

    vector<string> observationSequence = {"Normal", "Cold", "Dizzy"};

    vector<string> result = hmm.viterbi(observationSequence);

    cout << "Most Likely State Sequence:" << endl;
    for (const string &state : result)
    {
        cout << state << " ";
    }
    cout << endl;

    return 0;
}
