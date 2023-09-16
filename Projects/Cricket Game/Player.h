/*
Group Members:
Abdul Aziz		BCSF19A026
Imran Khan		BCSF20A018
Muhammad Umar	BCSF20A012
*/


#pragma once
#include <iostream> 
#include <fstream> //file handling
#include <string>  // to use string
#include <iomanip> // for manipulation setw etc
#include <ctime>   // for random selection initilization with time 
#include <cstdlib> // random selection
using namespace std;
class Player
{
	int playerID; //int value
	string playerName; 
	string playerStatus; // Batsman, Bowler, Alrounder 
	int playerScore;

public:
	Player(int =0, const string = "", const string = "", int =0);//Default and peremetrized Constructor
	void setPlayerID(int);
	void setPlayerName(const string = "");
	void setPlayerStatus(const string = "");
	void setPlayerScore(int);
	void incrementPlayerScore(int);
	const int getPlayerID()const; //const function to keep the concept of encapsulation
	const string getPlayerName()const;
	const string getPlayerStatus()const;
	const int getPlayerScore()const;
	void display()const; // Displaying the Detail of 1 player
};

