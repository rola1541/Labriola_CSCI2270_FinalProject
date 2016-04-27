#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

struct player
{
    string name;
    int atBats;
    int hits;
    int runsBattedIn;
    int strikeOuts;
    int homeRuns;
    int doubles;
    int triples;
    int walks;
    player *next = NULL;
};

struct boxScore
{
    string gameTitle;
    string scoringPlays;
    string substitutions;
    player homeLineup[15];
    player awayLineup[15];
    bool created = false;
};

class Game
{
    public:
        Game();
        ~Game();
        void findGame(int gameNumber);
        void printFullBoxScore(int gameNumber);
        void printPlayerStats(string playerName, int gameNumber);
        void printLineUp(int gameNumber);
        void printScoringPlays(int gameNumber);
        void substituePlayer(string plyaerIn, string playerOut, int gameNumber);
        void deleteGame(int gameNumber);
        void newGame(int gameNumber, string vs);
        void printSubstitutions(int gameNumber);
        boxScore allGames[162];
    protected:
    private:


};

#endif // GAME_H
