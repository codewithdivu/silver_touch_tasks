#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SuffixAutomaton {
private:
    struct State {
        int length;
        int link;
        unordered_map<char, int> transitions;

        State() : length(0), link(-1) {}
    };

    vector<State> states;
    int last;

public:
    SuffixAutomaton(const string& text) {
        states.emplace_back(); // Initial state
        last = 0;

        for (char c : text) {
            addCharacter(c);
        }
    }

    void addCharacter(char c) {
        int new_state = states.size();
        states.emplace_back();
        states[new_state].length = states[last].length + 1;

        int p = last;
        while (p != -1 && states[p].transitions.find(c) == states[p].transitions.end()) {
            states[p].transitions[c] = new_state;
            p = states[p].link;
        }

        if (p == -1) {
            states[new_state].link = 0;
        } else {
            int q = states[p].transitions[c];
            if (states[p].length + 1 == states[q].length) {
                states[new_state].link = q;
            } else {
                int clone = states.size();
                states.emplace_back(states[q]); // Clone state q
                states[clone].length = states[p].length + 1;

                while (p != -1 && states[p].transitions[c] == q) {
                    states[p].transitions[c] = clone;
                    p = states[p].link;
                }

                states[q].link = clone;
                states[new_state].link = clone;
            }
        }

        last = new_state;
    }

    // Find occurrences of the pattern in the text
    vector<int> findOccurrences(const string& pattern) {
        vector<int> occurrences;
        int state = 0, length = 0;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            while (state != -1 && states[state].transitions.find(c) == states[state].transitions.end()) {
                state = states[state].link;
                length = states[state].length;
            }

            if (state == -1) {
                state = 0;
                length = 0;
            } else {
                state = states[state].transitions[c];
                length++;
            }

            if (length == pattern.size()) {
                occurrences.push_back(i - length + 1);
            }
        }

        return occurrences;
    }
};

int main() {
    string text = "ababab";
    string pattern = "ab";

    SuffixAutomaton sa(text);
    vector<int> occurrences = sa.findOccurrences(pattern);

    cout << "Pattern occurrences at positions: ";
    for (int pos : occurrences) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
