#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class Player
{
public:
    string name;
    int score;

    Player(const string &n) : name(n), score(0) {}
};

class Game
{
private:
    vector<Player> players;
    mutex mtx;

public:
    void addPlayer(const string &playerName)
    {
        lock_guard<mutex> lock(mtx);
        players.emplace_back(playerName);
    }

    void displayPlayers()
    {
        lock_guard<mutex> lock(mtx);
        cout << "Players in the game:\n";
        for (const auto &player : players)
        {
            cout << "Name: " << player.name << ", Score: " << player.score << "\n";
        }
    }

    void startGame()
    {

        for (int i = 0; i < 5; ++i)
        {

            this_thread::sleep_for(chrono::seconds(1));

            lock_guard<mutex> lock(mtx);
            for (auto &player : players)
            {
                player.score += 10;
            }

            displayPlayers();
        }
    }
};

int main()
{
    Game myGame;

    myGame.addPlayer("Player1");
    myGame.addPlayer("Player2");

    myGame.displayPlayers();

    thread gameThread(&Game::startGame, &myGame);

    gameThread.join();

    return 0;
}
