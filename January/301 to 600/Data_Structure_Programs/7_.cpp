#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

double evaluateFraction(const string &num, const string &den, const unordered_map<string, double> &values)
{
    if (num == den)
    {
        return 1.0;
    }

    if (values.count(num) == 0 || values.count(den) == 0)
    {
        return -1.0;
    }

    return values.at(num) / values.at(den);
}

vector<double> evaluateQueries(const vector<vector<string>> &fractions, const vector<double> &values, const vector<vector<string>> &queries)
{
    unordered_map<string, double> valueMap;
    for (int i = 0; i < fractions.size(); i++)
    {
        valueMap[fractions[i][0]] = values[i];
    }

    vector<double> results;
    for (const auto &query : queries)
    {
        double result = evaluateFraction(query[0], query[1], valueMap);
        results.push_back(result);
    }

    return results;
}

int main()
{
    vector<vector<string>> fractions = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> results = evaluateQueries(fractions, values, queries);

    for (double result : results)
    {
        cout << result << endl;
    }

    return 0;
}
