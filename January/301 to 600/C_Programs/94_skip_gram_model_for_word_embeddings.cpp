#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

class SkipGramModel
{
private:
    unordered_map<string, vector<double>> wordEmbeddings;
    unordered_map<string, vector<double>> contextEmbeddings;
    unordered_map<string, double> biases;
    int embeddingSize;
    double learningRate;
    int negativeSamples;
    double subsamplingThreshold;

public:
    SkipGramModel(int embeddingSize, double learningRate, int negativeSamples, double subsamplingThreshold)
        : embeddingSize(embeddingSize),
          learningRate(learningRate),
          negativeSamples(negativeSamples),
          subsamplingThreshold(subsamplingThreshold) {}

    void train(const vector<string> &corpus, int epochs)
    {
        initializeEmbeddings(corpus);

        for (int epoch = 0; epoch < epochs; ++epoch)
        {
            for (const string &targetWord : corpus)
            {
                if (shouldSubsample(targetWord))
                {
                    continue;
                }

                for (const string &contextWord : corpus)
                {
                    if (targetWord == contextWord)
                    {
                        continue;
                    }

                    updateEmbeddings(targetWord, contextWord);
                    updateNegativeSamples(targetWord);
                }
            }
        }
    }

    void initializeEmbeddings(const vector<string> &corpus)
    {

        for (const string &word : corpus)
        {
            wordEmbeddings[word] = generateRandomVector(embeddingSize);
            contextEmbeddings[word] = generateRandomVector(embeddingSize);
            biases[word] = 0.0;
        }
    }

    vector<double> generateRandomVector(int size)
    {
        vector<double> vec;
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<double> distribution(0.0, 1.0);

        for (int i = 0; i < size; ++i)
        {
            vec.push_back(distribution(gen));
        }

        return vec;
    }

    bool shouldSubsample(const string &word)
    {

        double wordFrequency = getWordFrequency(word);
        double subsamplingProbability = 1.0 - sqrt(subsamplingThreshold / wordFrequency);
        return (rand() / static_cast<double>(RAND_MAX)) < subsamplingProbability;
    }

    double getWordFrequency(const string &word)
    {

        return 1.0;
    }

    void updateEmbeddings(const string &targetWord, const string &contextWord)
    {
        double score = calculateScore(targetWord, contextWord);
        double gradient = calculateGradient(score);

        updateEmbedding(targetWord, contextWord, gradient);
    }

    double calculateScore(const string &targetWord, const string &contextWord)
    {

        return dotProduct(wordEmbeddings[targetWord], contextEmbeddings[contextWord]) + biases[targetWord];
    }

    double calculateGradient(double score)
    {

        double sigmoid = 1.0 / (1.0 + exp(-score));
        return (1.0 - sigmoid);
    }

    void updateEmbedding(const string &targetWord, const string &contextWord, double gradient)
    {
        for (int i = 0; i < embeddingSize; ++i)
        {
            wordEmbeddings[targetWord][i] += learningRate * gradient * contextEmbeddings[contextWord][i];
            contextEmbeddings[contextWord][i] += learningRate * gradient * wordEmbeddings[targetWord][i];
        }

        biases[targetWord] += learningRate * gradient;
    }

    void updateNegativeSamples(const string &targetWord)
    {
        for (int i = 0; i < negativeSamples; ++i)
        {

            string negativeContextWord = sampleNegativeContextWord(targetWord);
            double score = calculateScore(targetWord, negativeContextWord);
            double gradient = calculateGradient(score);

            updateEmbedding(targetWord, negativeContextWord, gradient);
        }
    }

    string sampleNegativeContextWord(const string &targetWord)
    {

        vector<string> keys;
        for (const auto &entry : wordEmbeddings)
        {
            if (entry.first != targetWord)
            {
                keys.push_back(entry.first);
            }
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(0, keys.size() - 1);

        return keys[distribution(gen)];
    }

    double dotProduct(const vector<double> &vec1, const vector<double> &vec2)
    {

        double result = 0.0;
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result += vec1[i] * vec2[i];
        }
        return result;
    }

    const unordered_map<string, vector<double>> &getWordEmbeddings() const
    {
        return wordEmbeddings;
    }
};

int main()
{

    vector<string> corpus = {"I", "love", "natural", "language", "processing", "and", "word", "embeddings"};
    int embeddingSize = 50;
    double learningRate = 0.01;
    int negativeSamples = 5;
    double subsamplingThreshold = 1e-5;
    int epochs = 10;

    SkipGramModel skipGramModel(embeddingSize, learningRate, negativeSamples, subsamplingThreshold);
    skipGramModel.train(corpus, epochs);

    const unordered_map<string, vector<double>> &wordEmbeddings = skipGramModel.getWordEmbeddings();

    for (const auto &entry : wordEmbeddings)
    {
        cout << "Word: " << entry.first << ", Embedding: ";
        for (double value : entry.second)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
