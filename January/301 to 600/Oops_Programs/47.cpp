#include <iostream>
#include <functional>
using namespace std;

enum class State {
    Start,
    Middle,
    End
};

struct CoroutineStateMachine {
    State state = State::Start;
    function<void(State)> callback;

    void operator()(State s) {
        state = s;
        callback(state);
    }
};

void myCoroutine(CoroutineStateMachine& coroutine) {
    coroutine(State::Start);
    cout << "In the middle..." << endl;
    coroutine(State::Middle);
    cout << "At the end!" << endl;
    coroutine(State::End);
}

int main() {
    CoroutineStateMachine coroutine;
    coroutine.callback = [&coroutine](State s) {
        coroutine(s);
    };
    myCoroutine(coroutine);
    return 0;
}
