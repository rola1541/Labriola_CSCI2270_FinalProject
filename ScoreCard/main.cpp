#include <iostream>
#include "Game.h"

using namespace std;

void printMainMenu()
{
    cout << ">>>Main Menu<<<" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Find Game" << endl;
    cout << "3. Quit" << endl;
}

void gameMainMenu()
{
    cout << "What is happening in the game" << endl;
    cout << "1. Next batter" << endl;
    cout << "2. Pinch hitter" << endl;
    cout << "3. Defensive Replacement" << endl;
}

void batterMenu()
{
    cout << "What is the outcome of the at-bat" << endl;
    cout << "1. Hit" << endl;
    cout << "2. Out" << endl;
}

void hitMenu()
{
    cout << "What was the hit" << endl;
    cout << "1. Single" << endl;
    cout << "2. Double" << endl;
    cout << "3. Triple" << endl;
    cout << "4. Home Run" << endl;
}

void outMenu()
{
    cout << "What was the out" << endl;
    cout << "1. Fly out" << endl;
    cout << "2. Ground out" << endl;
    cout << "3. Strike out" << endl;
}

int main()
{
    int mainMenuChoice;
    int gameMainMenuChoice;
    int batterMenuChoice;
    int game;
    int awayBatter = -1;
    int homeBatter = -1;
    int hitMenuChoice;
    int outMenuChoice;
    int runsRecorded;
    int outsRecorded;
    string teamsPlaying;
    Game scoreBook;
    while(mainMenuChoice != 3)
    {
        printMainMenu();
        cin >> mainMenuChoice;
        if(mainMenuChoice == 1)
        {
            cout<< "What game number is this?" << endl;
            cin >> game;
            cout<< "Who is playing" << endl;
            cin.ignore();
            getline(cin, teamsPlaying);
            scoreBook.newGame(game, teamsPlaying);
            for(int inning = 1; inning < 10; inning++)
            {
                int awayOuts = 0;
                while(awayOuts != 3)
                {
                    gameMainMenu();
                    cin >> gameMainMenuChoice;
                    if(gameMainMenuChoice == 1)
                    {
                        batterMenu();
                        awayBatter++;
                        if(awayBatter == 9)
                        {
                            awayBatter = 0;
                        }
                        cin >> batterMenuChoice;
                        if(batterMenuChoice == 1)
                        {
                            hitMenu();
                            cin >> hitMenuChoice;
                            cout << "How many runs scored" << endl;
                            cin >> runsRecorded;
                            if(hitMenuChoice == 1)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 2)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                scoreBook.allGames[game].awayLineup[awayBatter].doubles++;
                                scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 3)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                scoreBook.allGames[game].awayLineup[awayBatter].triples++;
                                scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 4)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                scoreBook.allGames[game].awayLineup[awayBatter].homeRuns++;
                                scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                            }
                        }
                        else if(batterMenuChoice == 2)
                        {
                            outMenu();
                            cin >> outMenuChoice;
                            cout << "How many outs recorded" << endl;
                            cin >> outsRecorded;
                            if(outMenuChoice == 1)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                awayOuts = awayOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 2)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                awayOuts = awayOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 3)
                            {
                                scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                scoreBook.allGames[game].awayLineup[awayBatter].strikeOuts;
                                awayOuts++;
                            }
                        }
                    }
                    else if(gameMainMenuChoice == 2)
                    {

                    }
                    else if(gameMainMenuChoice == 3)
                    {

                    }
                }
                int homeOuts = 0;
                while(homeOuts != 3)
                {
                    gameMainMenu();
                    cin >> gameMainMenuChoice;
                    if(gameMainMenuChoice == 1)
                    {
                        batterMenu();
                        homeBatter++;
                        if(homeBatter == 9)
                        {
                            homeBatter = 0;
                        }
                        cin >> batterMenuChoice;
                        if(batterMenuChoice == 1)
                        {
                            hitMenu();
                            cin >> hitMenuChoice;
                            cout << "How many runs scored" << endl;
                            cin >> runsRecorded;
                            if(hitMenuChoice == 1)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 2)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                scoreBook.allGames[game].homeLineup[homeBatter].doubles++;
                                scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 3)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                scoreBook.allGames[game].homeLineup[homeBatter].triples++;
                                scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                            }
                            else if(hitMenuChoice == 4)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                scoreBook.allGames[game].homeLineup[homeBatter].homeRuns++;
                                scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                            }
                        }
                        else if(batterMenuChoice == 2)
                        {
                            outMenu();
                            cin >> outMenuChoice;
                            cout << "How many outs recorded" << endl;
                            cin >> outsRecorded;
                            if(outMenuChoice == 1)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                homeOuts = homeOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 2)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                homeOuts = homeOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 3)
                            {
                                scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                scoreBook.allGames[game].homeLineup[homeBatter].strikeOuts;
                                homeOuts++;
                            }
                        }
                    }
                    else if(gameMainMenuChoice == 2)
                    {

                    }
                    else if(gameMainMenuChoice == 3)
                    {

                    }
                }
            }
        }
        else if(mainMenuChoice == 2)
        {

        }
        else if(mainMenuChoice == 3)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Not valid option. Please try again" << endl;
        }
    }
    return 0;
}
