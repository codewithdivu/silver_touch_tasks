#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team {
private:
    string name;

public:
    Team(const string& teamName) : name(teamName) {}

    const string& getName() const {
        return name;
    }
};

class Match {
private:
    Team team1;
    Team team2;
    int scoreTeam1;
    int scoreTeam2;
    bool isMatchPlayed;

public:
    Match(const Team& t1, const Team& t2) : team1(t1), team2(t2), scoreTeam1(0), scoreTeam2(0), isMatchPlayed(false) {}

    const Team& getTeam1() const {
        return team1;
    }

    const Team& getTeam2() const {
        return team2;
    }

    int getScoreTeam1() const {
        return scoreTeam1;
    }

    int getScoreTeam2() const {
        return scoreTeam2;
    }

    bool getIsMatchPlayed() const {
        return isMatchPlayed;
    }

    void playMatch(int score1, int score2) {
        scoreTeam1 = score1;
        scoreTeam2 = score2;
        isMatchPlayed = true;
    }
};

class Tournament {
private:
    vector<Match> matches;

public:
    void addMatch(const Team& team1, const Team& team2) {
        matches.emplace_back(team1, team2);
    }

    void updateMatchResult(int matchIndex, int score1, int score2) {
        if (matchIndex >= 0 && matchIndex < matches.size()) {
            matches[matchIndex].playMatch(score1, score2);
        } else {
            cout << "Invalid match index!\n";
        }
    }

    void displayResults() const {
        cout << "Tournament Results:\n";
        cout << "-------------------------\n";
        for (const Match& match : matches) {
            cout << match.getTeam1().getName() << " vs " << match.getTeam2().getName() << ": ";
            if (match.getIsMatchPlayed()) {
                cout << match.getScoreTeam1() << " - " << match.getScoreTeam2();
            } else {
                cout << "Not played yet";
            }
            cout << "\n";
        }
        cout << "-------------------------\n";
    }

    void determineWinners() const {
        cout << "Tournament Winners:\n";
        cout << "-------------------------\n";
        for (const Match& match : matches) {
            if (match.getIsMatchPlayed()) {
                cout << (match.getScoreTeam1() > match.getScoreTeam2() ? match.getTeam1().getName() : match.getTeam2().getName()) << " wins!\n";
            } else {
                cout << "Winner not determined yet for " << match.getTeam1().getName() << " vs " << match.getTeam2().getName() << "\n";
            }
        }
        cout << "-------------------------\n";
    }
};

int main() {
    using namespace std;

    Team team1("Team A");
    Team team2("Team B");
    Team team3("Team C");
    Team team4("Team D");

    Tournament tournament;

    tournament.addMatch(team1, team2);
    tournament.addMatch(team3, team4);

    tournament.updateMatchResult(0, 2, 1);
    tournament.updateMatchResult(1, 0, 3);

    tournament.displayResults();
    tournament.determineWinners();

    return 0;
}
