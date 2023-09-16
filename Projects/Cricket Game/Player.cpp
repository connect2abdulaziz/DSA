/*
Group Members:
Abdul Aziz		BCSF19A026
Imran Khan		BCSF20A018
Muhammad Umar	BCSF20A012
*/


#include "Player.h"
Player::Player(int id, const string n, const string s, int scr)
{
	// to set the Player Data in the Setter functions
	setPlayerID(id);
	setPlayerName(n);
	setPlayerStatus(s);
	setPlayerScore(scr);
}
void Player::setPlayerID(int id)
{
	playerID = id;
}
void Player::setPlayerName(const string n)
{
	playerName = n;
}
void Player::setPlayerStatus(const string s)
{
	playerStatus = s;
}
void Player::setPlayerScore(int scr)
{
	if (scr > 0) // score validations
		playerScore = scr;
	else
		playerScore = 0;
}
void Player::incrementPlayerScore(int runs)
{
	// as we know the condition only player runs the following runs so to keep the 
	// increment runs from some invalid runs.
	if (runs == 1 || runs == 2 || runs == 4 || runs == 6) 
		playerScore += runs;
}
const int Player::getPlayerID()const
{
	return playerID;
}
const string Player::getPlayerName()const
{
	return playerName;
}
const int Player::getPlayerScore()const
{
	return playerScore;
}
const string Player::getPlayerStatus()const
{
	return playerStatus;
}
void Player::display()const
{
	// Displaying the Player Detail in well formet
	cout << setw(3) << getPlayerID() << "." << setw(25) << getPlayerName() << setw(10) << "(" << getPlayerStatus() << ")";
}