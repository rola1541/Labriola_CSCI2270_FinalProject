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
};

struct boxScore
{
    string gameTitle;
    player homeLineup[15];
    player awayLineup[15];
};

class Game
{
    public:
        Game();
        ~Game();
        void findGame();
        void printFullBoxScore();
        void printPlayerStats();
        void printLineUp();
        void printScoringPlays();
        void addPlayer();
        void substituePlayer(string plyaerIn, string playerOut, int gameNumber);
        void deleteGame();
        void newGame(int gameNumber, string vs);
        void printSubstitutions();
        boxScore allGames[162];
    protected:
    private:


};

#endif // GAME_H
