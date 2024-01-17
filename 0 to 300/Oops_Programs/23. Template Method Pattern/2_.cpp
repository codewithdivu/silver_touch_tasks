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

class Football : public Game
{
    void initialize()
    {
        cout << "football game is initialized" << endl;
    }
    void startPlay()
    {
        cout << "football game is start" << endl;
    }
    void endPlay()
    {
        cout << "football game is end" << endl;
    }
};
class Basketball : public Game
{
    void initialize()
    {
        cout << "basketball game is initialized" << endl;
    }
    void startPlay()
    {
        cout << "basketball game is start" << endl;
    }
    void endPlay()
    {
        cout << "basketball game is end" << endl;
    }
};

int main()
{
    Game *footballGame = new Football();
    footballGame->play();
    delete footballGame;
    Game *basketballGame = new Basketball();
    basketballGame->play();
    delete basketballGame;
    return 0;
}