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


void Game::deleteGame(int gameNumber)
{

    boxScore NullBoxScore;
    allGames[gameNumber] = NullBoxScore;
}

void Game::findGame(int gameNumber)
{

    if(allGames[gameNumber].created == true)
    {
        cout << "Game found" << endl;
    }
    else
    {
        cout << "No game found" << endl;
    }
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
    newBoxScore.created = true;
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

    allGames[gameNumber] = newBoxScore;
}

void Game::printFullBoxScore(int gameNumber)
{

    cout << "The away teams box score" << endl;
    for(int x = 0; x < 9; x++)
    {
        printPlayerStats(allGames[gameNumber].awayLineup[x].name, gameNumber);
    }
    cout << "The home teams box score" << endl;
    for(int y = 0; y < 9; y++)
    {
        printPlayerStats(allGames[gameNumber].homeLineup[y].name, gameNumber);
    }
}

void Game::printLineUp(int gameNumber)
{

    cout << "Today's home lineup is:" << endl;
    for(int x = 0; x < 9; x++)
    {
        cout << allGames[gameNumber].homeLineup[x].name << endl;
        if(allGames[gameNumber].homeLineup[x].next != NULL)
        {
            player *tmp = &allGames[gameNumber].homeLineup[x];
            while(tmp != NULL)
            {
                tmp = tmp->next;
                cout << tmp->name << endl;
            }
        }
    }
    cout << "Today's away lineup is:" << endl;
    for(int y = 0; y < 9; y++)
    {
        cout << allGames[gameNumber].awayLineup[y].name << endl;
        if(allGames[gameNumber].awayLineup[y].next != NULL)
        {
            player *tmp = &allGames[gameNumber].awayLineup[y];
            while(tmp != NULL)
            {
                tmp = tmp->next;
                cout << tmp->name << endl;
            }
        }
    }
}

void Game::printPlayerStats(string playerName, int gameNumber)
{

    for(int y = 0; y < 9; y++)
    {
        if(allGames[gameNumber].awayLineup[y].name == playerName)
        {
            cout << allGames[gameNumber].awayLineup[y].name << endl;
            cout << allGames[gameNumber].awayLineup[y].hits << " for " << allGames[gameNumber].awayLineup[y].atBats <<
            " with " << allGames[gameNumber].awayLineup[y].doubles << " doubles, " << allGames[gameNumber].awayLineup[y].triples
            << " triples, " << allGames[gameNumber].awayLineup[y].homeRuns << " home runs, " <<
            allGames[gameNumber].awayLineup[y].runsBattedIn << " RBI's, " << allGames[gameNumber].awayLineup[y].strikeOuts <<
            " strikeouts, and " << allGames[gameNumber].awayLineup[y].walks << " walks" << endl;
        }
        else if(allGames[gameNumber].awayLineup[y].next != NULL)
        {
            player *tmp = &allGames[gameNumber].awayLineup[y];
            while(tmp != NULL)
            {
                tmp = tmp->next;
                if(tmp->name == playerName)
                {
                    cout << tmp->name << endl;
                    cout << tmp->hits << " for " << tmp->atBats <<
                    " with " << tmp->doubles << " doubles, " << tmp->triples
                    << " triples, " << tmp->homeRuns << " home runs, " <<
                    tmp->runsBattedIn << " RBI's, " << tmp->strikeOuts <<
                    " strikeouts, and " << tmp->walks << " walks" << endl;
                }
            }
        }
        else if(allGames[gameNumber].homeLineup[y].name == playerName)
        {
            cout << allGames[gameNumber].homeLineup[y].name << endl;
            cout << allGames[gameNumber].homeLineup[y].hits << " for " << allGames[gameNumber].homeLineup[y].atBats <<
            " with " << allGames[gameNumber].homeLineup[y].doubles << " doubles, " << allGames[gameNumber].homeLineup[y].triples
            << " triples, " << allGames[gameNumber].homeLineup[y].homeRuns << " home runs, " <<
            allGames[gameNumber].homeLineup[y].runsBattedIn << " RBI's, " << allGames[gameNumber].homeLineup[y].strikeOuts <<
            " strikeouts, and " << allGames[gameNumber].homeLineup[y].walks << " walks" << endl;
        }
        else if(allGames[gameNumber].homeLineup[y].next != NULL)
        {
            player *tmp = &allGames[gameNumber].homeLineup[y];
            while(tmp != NULL)
            {
                tmp = tmp->next;
                if(tmp->name == playerName)
                {
                    cout << tmp->name << endl;
                    cout << tmp->hits << " for " << tmp->atBats <<
                    " with " << tmp->doubles << " doubles, " << tmp->triples
                    << " triples, " << tmp->homeRuns << " home runs, " <<
                    tmp->runsBattedIn << " RBI's, " << tmp->strikeOuts <<
                    " strikeouts, and " << tmp->walks << " walks" << endl;
                }
            }
        }
    }
}

void Game::printScoringPlays(int gameNumber)
{

    cout << allGames[gameNumber].scoringPlays << endl;
}

void Game::printSubstitutions(int gameNumber)
{

    cout << allGames[gameNumber].substitutions << endl;
}

void Game::substituePlayer(string playerIn, string playerOut, int gameNumber)
{

    player newPlayer;
    newPlayer.name = playerIn;
    for(int x = 0; x < 15; x++)
    {
        if(allGames[gameNumber].awayLineup[x].name == playerOut)
        {
            player *tmp = &allGames[gameNumber].awayLineup[x];
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = &newPlayer;
        }
        if(allGames[gameNumber].homeLineup[x].name == playerOut)
        {
            player *tmp = &allGames[gameNumber].homeLineup[x];
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = &newPlayer;
        }
    }
}


