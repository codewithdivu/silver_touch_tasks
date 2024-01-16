#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Game
{
public:
    void play()
    {
        initialize();
        startPlay();
        endPlay();
    }

    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

    virtual ~Game() {}
};

int main()
{

    return 0;
}