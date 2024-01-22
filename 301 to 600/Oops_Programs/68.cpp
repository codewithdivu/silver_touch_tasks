
#include <iostream>
using namespace std;

class Piece {
public:
    virtual void move() const = 0;
    virtual ~Piece() {}
};

class King : public Piece {
public:
    void move() const override {
        cout << "King moves." << endl;
    }
};

class Queen : public Piece {
public:
    void move() const override {
        cout << "Queen moves." << endl;
    }
};

class Player {
public:
    string name;
    Piece* piece;

    Player(const string& n, Piece* p) : name(n), piece(p) {}

    void makeMove() const {
        piece->move();
    }
};

class Board {
private:
    Piece* pieces[8][8];

public:
    Board() {
        
        pieces[0][0] = new King();
        pieces[0][1] = new Queen();
        
    }

    ~Board() {
        
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete pieces[i][j];
            }
        }
    }
};

class ChessGame {
private:
    Player* player1;
    Player* player2;
    Board board;

public:
    ChessGame(Player* p1, Player* p2) : player1(p1), player2(p2) {}

    void play() {
        cout << "Chess Game Begins!" << endl;

        
        cout << player1->name << "'s turn:" << endl;
        player1->makeMove();

        
        cout << player2->name << "'s turn:" << endl;
        player2->makeMove();

        
    }
};

int main() {
    
    King king1, king2;
    Queen queen1, queen2;

    Player player1("Player 1", &king1);
    Player player2("Player 2", &queen2);

    
    ChessGame chessGame(&player1, &player2);

    
    chessGame.play();

    return 0;
}
