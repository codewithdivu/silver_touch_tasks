#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Token
{
public:
    unordered_map<string, string> attributes;

    Token(const unordered_map<string, string> &attrs) : attributes(attrs) {}
};

class AlphaNode
{
public:
    vector<Token *> tokens;

    AlphaNode() {}

    void addToken(Token *token)
    {
        tokens.push_back(token);
    }
};

class BetaMemory
{
public:
    vector<pair<Token *, Token *>> joinedTokens;

    BetaMemory() {}

    void addJoinedTokens(Token *left, Token *right)
    {
        joinedTokens.emplace_back(left, right);
    }
};

class ReteII
{
public:
    unordered_map<string, AlphaNode> alphaMemory;
    vector<BetaMemory> betaMemory;

    void addToAlphaMemory(Token *token, const string &attribute)
    {
        alphaMemory[attribute].addToken(token);
    }

    void joinBetaMemory(const string &leftAttribute, const string &rightAttribute)
    {
        BetaMemory newBetaMemory;
        AlphaNode &leftAlphaNode = alphaMemory[leftAttribute];
        AlphaNode &rightAlphaNode = alphaMemory[rightAttribute];

        for (Token *leftToken : leftAlphaNode.tokens)
        {
            for (Token *rightToken : rightAlphaNode.tokens)
            {
                if (checkJoinCondition(leftToken, rightToken))
                {
                    newBetaMemory.addJoinedTokens(leftToken, rightToken);
                }
            }
        }

        betaMemory.push_back(newBetaMemory);
    }

    bool checkJoinCondition(Token *leftToken, Token *rightToken)
    {

        return true;
    }

    void printBetaMemory()
    {
        int memoryIndex = 0;
        for (const BetaMemory &memory : betaMemory)
        {
            cout << "Beta Memory " << memoryIndex << ":" << endl;
            for (const auto &joinedTokens : memory.joinedTokens)
            {
                printToken(joinedTokens.first);
                cout << " and ";
                printToken(joinedTokens.second);
                cout << endl;
            }
            cout << "-------------------" << endl;
            memoryIndex++;
        }
    }

    void printToken(Token *token)
    {
        for (const auto &attribute : token->attributes)
        {
            cout << attribute.first << ": " << attribute.second << " ";
        }
    }
};

int main()
{

    ReteII rete;

    Token token1({{"Name", "John"}, {"Age", "25"}});
    Token token2({{"Name", "Jane"}, {"Age", "30"}});
    Token token3({{"City", "New York"}, {"Salary", "50000"}});

    rete.addToAlphaMemory(&token1, "Name");
    rete.addToAlphaMemory(&token2, "Name");
    rete.addToAlphaMemory(&token3, "City");

    rete.joinBetaMemory("Name", "City");

    rete.printBetaMemory();

    return 0;
}
