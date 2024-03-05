#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(const string &num, int target, int start, long long currentVal, long long prevOperand, string currentExp, vector<string> &result)
{
    int n = num.size();

    if (start == n && currentVal == target)
    {
        result.push_back(currentExp);
        return;
    }

    for (int end = start + 1; end <= n; ++end)
    {
        string operandStr = num.substr(start, end - start);
        long long operand = stoll(operandStr);

        if (to_string(operand).size() != operandStr.size())
        {

            continue;
        }

        if (currentExp.empty())
        {
            backtrack(num, target, end, operand, operand, operandStr, result);
        }
        else
        {
            backtrack(num, target, end, currentVal + operand, operand, currentExp + "+" + operandStr, result);
            backtrack(num, target, end, currentVal - operand, -operand, currentExp + "-" + operandStr, result);
            backtrack(num, target, end, currentVal - prevOperand + prevOperand * operand, prevOperand * operand, currentExp + "*" + operandStr, result);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    backtrack(num, target, 0, 0, 0, "", result);
    return result;
}

int main()
{

    string num = "123";
    int target = 6;

    vector<string> result = addOperators(num, target);

    cout << "Expression(s) to achieve the target " << target << ":\n";
    for (const string &expression : result)
    {
        cout << expression << endl;
    }

    return 0;
}
