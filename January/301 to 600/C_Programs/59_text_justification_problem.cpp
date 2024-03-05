#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> fullJustify(const vector<string> &words, int maxWidth)
{
    vector<string> result;
    int i = 0;

    while (i < words.size())
    {
        int j = i + 1;
        int currentWidth = words[i].size();

        while (j < words.size() && currentWidth + words[j].size() + (j - i) <= maxWidth)
        {
            currentWidth += words[j].size();
            j++;
        }

        int numWords = j - i;
        int extraSpaces = maxWidth - currentWidth;

        string line = words[i];
        for (int k = 1; k < numWords; ++k)
        {

            int spaces = (j < words.size()) ? (extraSpaces / (numWords - 1) + ((k <= extraSpaces % (numWords - 1)) ? 1 : 0)) : 1;
            line += string(spaces, ' ') + words[i + k];
        }

        line += string(maxWidth - line.size(), ' ');

        result.push_back(line);
        i = j;
    }

    return result;
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> justifiedText = fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for (const string &line : justifiedText)
    {
        cout << "\"" << line << "\"\n";
    }

    return 0;
}
