#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game {
public:
    string title;
    int progressPercentage;

    Game(const string& t) : title(t), progressPercentage(0) {}

    void updateProgress(int hours) {
        
        progressPercentage += hours * 5; 
    }
};

class Player {
public:
    string playerName;
    vector<Game> games;

    Player(const string& name) : playerName(name) {}

    void addGame(const Game& game) {
        games.push_back(game);
        cout << playerName << " added " << game.title << " to their inventory." << endl;
    }

    void playGame(Game& game, int hours) {
        
        cout << playerName << " played " << game.title << " for " << hours << " hours." << endl;
        game.updateProgress(hours);
    }
};

class Inventory {
private:
    vector<Player> players;

public:
    void addPlayer(const Player& player) {
        players.push_back(player);
    }
};

int main() {
    Player player1("Alice");
    Player player2("Bob");

    Game game1("Super Adventure");
    Game game2("Space Explorer");

    player1.addGame(game1);
    player2.addGame(game2);

    player1.playGame(game1, 3);
    player2.playGame(game2, 5);

    return 0;
}