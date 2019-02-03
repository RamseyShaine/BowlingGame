#include <iostream>
#include <stdlib.h>
#include <vector> 
#include <string>

using namespace std;

/*****************************************************************************
Data Structure Name: playerInfo
Description: The playerInfo struct conatins pertinent information about all players in the Match.
*******************************************************************************/
struct playerInfo{
	string name; // Players name
	int scoreCount; // Players individual total score
	int frame; // Frame of the match the player is rolling for
	int currRoll; // Current roll for player in frame
	int currResult; // Pins hit in current roll
	int frameScore; // Total pins hit in one frame
	int lastRoll; // Used to hold value of previous roll if it was a strike or spare
};

/*****************************************************************************
Class: Match
Description: The Match class declares all functions used for the score calculation.
******************************************************************************/
class Match{

	public: vector <playerInfo> players; //Multidimensional vector containing players information
			void game ();// Calculate points of current roll. 
			int pinsHit ();// Number of pins hit on current roll
			int onHit ();// Random generation of hit type (strike, spare, or open frame)
			void checkPlayers (int numPlayers);// Tests that number of players entered is a valid entry 
			void getNames (int numPlayers);// Gets names of players 
			int rolledTen (); // Adds 10 to total after strike or spare
};
