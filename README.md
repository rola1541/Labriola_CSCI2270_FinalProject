# Labriola_CSCI2270_FinalProject

Summary:
My program will act as a virtual baseball scorecard. A scorecard is used by anyone instersted in stat keeping at a baseball game to record the outcome of each at-bat in a baseball game. This program will use the same idea and allow the user to input the outcome of an at-bat for every at-bat in a game. After the game is finished, the user can look up any game and see the statistics for each player as well as the box score for the game. The program will have the relevant statistics for each player that starts as well as any replacment players.

How to Run:
The three files needed to run this program are Game.cpp, Game.h, and main.cpp. These are found in the ScoreCard file. Using codeblocks and selecting open an existing project and then navigating to the ScoreCard file and then ScoreCard.cbp will open a project with these three files.

This program is meant to be a companion to a baseball game so it works best while either watching a baseball game or with a play by play recap of a baseball game. The first step while following a game is to get the starting lineup for both teams which will be inputed one by one in batting order. After that, each at bat is recorded for an event such as hit or out based on a series of responses to the menu questions. The program tracks outs and will move to the next half inning after three outs are recorded. Statistics such as at bats, hits, strikeouts, home runs, and runs batted in are recorded based on given inputs. The program continues until the end of the game. After that, the user can look over the line up of the game, each players stats and box score, as well as any scoring plays in the game.

Dependencies:
None

System Requirements:
Should work on any platform

Group Members:
None

Contributors:
None

Open issues/bugs:
The program has the option to subsitute any player however once there is an at bat with a substitued player, there is a seg fault. 
Currently, not every baseball play is accounted for. Some examples would be walks, runs scored at the same time as an out, and stolen bases.
Pitching statistics are not kept yet but could potentially be implemented.
