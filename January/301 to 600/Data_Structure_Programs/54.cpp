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
        states.emplace_back(); 
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
                states.emplace_back(states[q]); 
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

    
    long long countDistinctSubstrings() {
        long long result = 0;
        for (const State& state : states) {
            result += state.length - states[state.link].length;
        }
        return result;
    }
};

int main() {
    string text = "ababab";
    SuffixAutomaton sa(text);

    
    long long distinctSubstrings = sa.countDistinctSubstrings();
    cout << "Number of distinct substrings: " << distinctSubstrings << endl;

    return 0;
}
