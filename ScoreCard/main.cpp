#include <iostream>
#include <string>
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

void findGameMenu()
{
    cout << "What would you like to know about this game" << endl;
    cout << "1. Print lineup" << endl;
    cout << "2. Full box score" << endl;
    cout << "3. Print player stats" << endl;
    cout << "4. Print scoring plays" << endl;
    cout << "5. Print substitutions" << endl;
    cout << "6. Erase game" << endl;
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
    int findGameMenuChoice;
    string teamsPlaying;
    string playerOut;
    string playerIn;
    string findPlayerStats;
    Game scoreBook;
    while(mainMenuChoice != 3)
    {
        printMainMenu();
        cin >> mainMenuChoice;
        if(mainMenuChoice == 1)
        {
            cout<< "What game number is this?" << endl;
            cin >> game;
            game = game - 1;
            cout<< "Who is playing" << endl;
            cin.ignore();
            getline(cin, teamsPlaying);
            scoreBook.newGame(game, teamsPlaying);
            for(int inning = 1; inning < 10; inning++)
            {
                int awayOuts = 0;
                while(awayOuts != 3)
                {
                    cout <<"It is the top of inning #" << inning << ": " << awayOuts<< " out(s)" << endl;
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
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" singles in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].awayLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" singles in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 2)
                            {
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->doubles++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" doubles in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].doubles++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].awayLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" doubles in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 3)
                            {
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->triples++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" triples in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].triples++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].awayLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" triples in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 4)
                            {
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->homeRuns++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" hits a home run to score run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].hits++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].homeRuns++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn = scoreBook.allGames[game].awayLineup[awayBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].awayLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" hits a home run to score run(s): ");
                                    }
                                }
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
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                }
                                awayOuts = awayOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 2)
                            {
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                }
                                awayOuts = awayOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 3)
                            {
                                if(scoreBook.allGames[game].awayLineup[awayBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].awayLineup[awayBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->strikeOuts++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].awayLineup[awayBatter].atBats++;
                                    scoreBook.allGames[game].awayLineup[awayBatter].strikeOuts++;
                                }
                                awayOuts++;
                            }
                        }
                    }
                    else if(gameMainMenuChoice == 2)
                    {
                        cout << "What player is being replaced" << endl;
                        cin>>playerOut;
                        cout << "Who is replacing him" << endl;
                        cin>>playerIn;
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.allGames[game].substitutions.append(playerIn);
                        scoreBook.allGames[game].substitutions.append(" replaced ");
                        scoreBook.allGames[game].substitutions.append(playerOut);
                        scoreBook.allGames[game].substitutions.append(": ");
                    }
                    else if(gameMainMenuChoice == 3)
                    {
                        cout << "What player is being replaced" << endl;
                        cin>>playerOut;
                        cout << "Who is replacing him" << endl;
                        cin>>playerIn;
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.allGames[game].substitutions.append(playerIn);
                        scoreBook.allGames[game].substitutions.append(" replaced ");
                        scoreBook.allGames[game].substitutions.append(playerOut);
                        scoreBook.allGames[game].substitutions.append(": ");
                    }
                }
                int homeOuts = 0;
                while(homeOuts != 3)
                {
                    cout <<"It is the bottom of inning #" << inning << ": " << homeOuts << " out(s)" << endl;
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
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" singles in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].homeLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" singles in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 2)
                            {
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->doubles++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" doubles in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].doubles++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].homeLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" doubles in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 3)
                            {
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->triples++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" triples in run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].triples++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].homeLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" triples in run(s): ");
                                    }
                                }
                            }
                            else if(hitMenuChoice == 4)
                            {
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->hits++;
                                    tmp->homeRuns++;
                                    tmp->runsBattedIn = tmp->runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(tmp->name);
                                        scoreBook.allGames[game].scoringPlays.append(" hits a home run to score run(s): ");
                                    }
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].hits++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].homeRuns++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn = scoreBook.allGames[game].homeLineup[homeBatter].runsBattedIn + runsRecorded;
                                    if(runsRecorded > 0)
                                    {
                                        scoreBook.allGames[game].scoringPlays.append(scoreBook.allGames[game].homeLineup[awayBatter].name);
                                        scoreBook.allGames[game].scoringPlays.append(" hits a home run to score run(s): ");
                                    }
                                }
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
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                }
                                homeOuts = homeOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 2)
                            {
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                }
                                homeOuts = homeOuts + outsRecorded;
                            }
                            else if(outMenuChoice == 3)
                            {
                                if(scoreBook.allGames[game].homeLineup[homeBatter].next != NULL)
                                {
                                    player *tmp = scoreBook.allGames[game].homeLineup[homeBatter].next;
                                    while(tmp->next != NULL)
                                    {
                                        tmp = tmp->next;
                                    }
                                    tmp->atBats++;
                                    tmp->strikeOuts++;
                                }
                                else
                                {
                                    scoreBook.allGames[game].homeLineup[homeBatter].atBats++;
                                    scoreBook.allGames[game].homeLineup[homeBatter].strikeOuts++;
                                }
                                homeOuts++;
                            }
                        }
                    }
                    else if(gameMainMenuChoice == 2)
                    {
                        cout << "What player is being replaced" << endl;
                        cin>>playerOut;
                        cout << "Who is replacing him" << endl;
                        cin>>playerIn;
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.allGames[game].substitutions.append(playerIn);
                        scoreBook.allGames[game].substitutions.append(" replaced ");
                        scoreBook.allGames[game].substitutions.append(playerOut);
                        scoreBook.allGames[game].substitutions.append(": ");
                    }
                    else if(gameMainMenuChoice == 3)
                    {
                        cout << "What player is being replaced" << endl;
                        cin>>playerOut;
                        cout << "Who is replacing him" << endl;
                        cin>>playerIn;
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.substituePlayer(playerIn, playerOut, game);
                        scoreBook.allGames[game].substitutions.append(playerIn);
                        scoreBook.allGames[game].substitutions.append(" replaced ");
                        scoreBook.allGames[game].substitutions.append(playerOut);
                        scoreBook.allGames[game].substitutions.append(": ");
                    }
                }
            }
        }
        else if(mainMenuChoice == 2)
        {
            cout << "Which game" << endl;
            cin>>game;
            game = game - 1;
            scoreBook.findGame(game);
            findGameMenu();
            cin>>findGameMenuChoice;
            if(findGameMenuChoice == 1)
            {
                scoreBook.printLineUp(game);
            }
            else if(findGameMenuChoice == 2)
            {
                scoreBook.printFullBoxScore(game);
            }
            else if(findGameMenuChoice == 3)
            {
                cout << "Which player" << endl;
                cin>>findPlayerStats;
                scoreBook.printPlayerStats(findPlayerStats, game);
            }
            else if(findGameMenuChoice == 4)
            {
                scoreBook.printScoringPlays(game);
            }
            else if(findGameMenuChoice == 5)
            {
                scoreBook.printSubstitutions(game);
            }
            else if(findGameMenuChoice == 6)
            {
                scoreBook.deleteGame(game);
                break;
            }
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
