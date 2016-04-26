#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::addPlayer()
{

}

void Game::deleteGame()
{

}

void Game::findGame()
{

}

void Game::newGame(int gameNumber, string vs)
{
    string homePlayer;
    string awayPlayer;
    int homeLineUp = 0;
    int awayLineUp = 0;
    player newPlayer;
    boxScore newBoxScore;
    newBoxScore.gameTitle = vs;
    while(homeLineUp != 9)
    {
        cout << "Enter the home " << homeLineUp + 1 << " slot's name" << endl;
        cin >> homePlayer;
        newPlayer.name = homePlayer;
        newBoxScore.homeLineup[homeLineUp] = newPlayer;
        homeLineUp++;
    }
    while(awayLineUp != 9)
    {
        cout << "Enter the away " << awayLineUp + 1 << " slot's name" << endl;
        cin >> awayPlayer;
        newPlayer.name = awayPlayer;
        newBoxScore.awayLineup[awayLineUp] = newPlayer;
        awayLineUp++;
    }
    cout << "Today's home lineup is:" << endl;
    for(int x = 0; x < homeLineUp; x++)
    {
        cout << newBoxScore.homeLineup[x].name << endl;
    }
    cout << "Today's away lineup is:" << endl;
    for(int y = 0; y < awayLineUp; y++)
    {
        cout << newBoxScore.awayLineup[y].name << endl;
    }

    allGames[gameNumber - 1] = newBoxScore;
}

void Game::printFullBoxScore()
{

}

void Game::printLineUp()
{

}

void Game::printPlayerStats()
{

}

void Game::printScoringPlays()
{

}

void Game::printSubstitutions()
{

}

void Game::substituePlayer(string playerIn, string playerOut, int gameNumber)
{
    player newPlayer;
    newPlayer.name = playerIn;
}


