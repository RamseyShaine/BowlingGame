#include <iostream>
#include <stdlib.h>
#include <vector> 
#include "BowlingGame.hpp"

using namespace std; 

/*****************************************************************************
Function: checkPlayers()
Description: This function is used to validate the number of players is entered correctly.
The function validates between one and eight because eight is generally the maximum number 
of players in a bowling match. It also checks that the entry is not above eight or less than 
one and that it is a data type of int.
*****************************************************************************/
void Match::checkPlayers(int numPlayers){
	if(numPlayers <= 8 && numPlayers > 0){
		getNames(numPlayers);
	}
	else if (cin.fail()){
		cin.clear();
        cin.ignore(1000,'\n');
		cout << "Invalid entry please enter a number from 1 to 8.\n";
		cin >> numPlayers;
		checkPlayers(numPlayers);
	}
	else if(numPlayers > 8){
		cout<< "Sorry thats too many players.\nYou may only have up to 8 players in one game.\nPlease enter a number of 8 or less.\n"; 
		cin >> numPlayers;
		checkPlayers(numPlayers);
	}
	else if(numPlayers <= 0){
		cout << "Invalid entry please enter a number from 1 to 8.\n";
		cin >> numPlayers;
		checkPlayers(numPlayers);
	}
}
/****************************************************************************
Function: getNames()
description: This function adds the names of players into the multidimensional vector.
*****************************************************************************/
void Match::getNames(int numPlayers){
	string playerName = "";
	for (int i = 0; i < numPlayers; i++){
		cout <<  "Enter name for player " << (i+1) << endl;
		cin >> playerName;
		players.push_back(playerInfo());
		players[i].name = playerName;
		cout << "Player " << i+1 << " is " << players[i].name << endl << endl;
	}
}
/*****************************************************************************
Function: game()
Description: This function represents each player taking their turn in the match. 
Points are added based off of the result from the onHit() function. 
0 means the player rolled a strike
1 means the player rolled a spare
2 means the player rolled an open frame
*****************************************************************************/
void Match::game(){
	int rollPoints = 0;
	srand(time(0));
	int frames = 1;

	do{
		if (players.size() > 1){
			for (int i = 0; i < players.size(); i++){
				int currHit = onHit();
				players[i].frame = frames;
				cout << "Player " << players[i].name << " is on frame: " << players[i].frame << endl;
				cout << players[i].name << " just rolled a: ";

					if (currHit == 0){
						cout << "X\n";
						players[i].currResult = rolledTen();
						players[i].scoreCount += rolledTen();
					}
					else if (currHit == 1){
						players[i].currResult = pinsHit();
						players[i].scoreCount += rolledTen();
						cout << players[i].currResult <<"/\n";
					}
					else if (currHit == 2){
						int remainder = 0;
						int rollOne = 0;
						int rollTwo = 0;
						int ofScore = 0;

						rollOne = pinsHit();
						remainder  = 10 - rollOne;
						rollTwo = rand() % remainder;
						ofScore = rollOne + rollTwo;
						players[i].currResult = ofScore;
						players[i].scoreCount += ofScore;

						cout << "Open Frame: " << rollOne << "," << rollTwo << endl;

					}

				cout << "They have " << players[i].scoreCount << " points at this time.\n\n";
			}
		}
		else {
			for (int i = 0; i < players.size(); i++){
				int currHit = onHit();
				players[i].frame = frames;

				cout << "Player " << players[i].name << " is on frame " << players[i].frame << endl;
				cout << players[i].name << " just rolled a: ";

					if (currHit == 0){
						cout << "X\n";
						players[i].currResult = rolledTen();
						players[i].scoreCount += rolledTen();
					}
					else if (currHit == 1){
						players[i].currResult = pinsHit();
						players[i].scoreCount += rolledTen();
						cout << players[i].currResult <<"/\n";
					}
					else if (currHit == 2){
						int remainder = 0;
						int rollOne = 0;
						int rollTwo = 0;
						int ofScore = 0;

						rollOne = pinsHit();
						remainder  = 10 - rollOne;
						rollTwo = rand() % remainder;
						ofScore = rollOne + rollTwo;
						players[i].currResult = ofScore;
						players[i].scoreCount += ofScore;

						cout << "Open Frame: " << rollOne << "," << rollTwo << endl;
					}
				cout << "They have " << players[i].scoreCount << " points at this time.\n\n";

			}

		}

		frames++;
	}while(frames < 11);

}

/******************************************************************************
Function: rolledTen()
Description: This function is used if a player rolled a strike or spare to add 10
to their total score.
******************************************************************************/
int Match::rolledTen(){
	int rollPoints = 0; 
	rollPoints += 10; 
	return rollPoints;
}

/******************************************************************************
Function: pinsHit()
Description: This function Generates a random number from 1 to 9. It is used 
to determine how many pins the player knocked down on the first roll of a 
spare. It is also used to calculate the pins knocked down on the first roll 
of an open frame.
*****************************************************************************/
int Match::pinsHit(){
		int pins = rand() % 10;
		return pins;
}
/*******************************************************************************
Function: onHit()
Description: This function determines what the player has rolled by generating 
a random number from 0 to 2.
0 = strike
1 = spare
2 = open frame
*******************************************************************************/
int Match::onHit(){
		int hit = rand() % 3;
		return hit;
	}

int main(){
	
	int numPlayers = 0;// Variable used for cin of number of players

	Match match; 

	cout <<  "How many players will be in this game?\n";  
	cin >> numPlayers; 
	match.checkPlayers(numPlayers);

	match.game();

	return 0;
}

