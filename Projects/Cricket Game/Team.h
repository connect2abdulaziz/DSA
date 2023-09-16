/*
Group Members:
Abdul Aziz		BCSF19A026
Imran Khan		BCSF20A018
Muhammad Umar	BCSF20A012
*/

#pragma once
#include "Player.h"
class Team
{
	int teamID;		 // Team no from 1-5
	string teamName; // Team Name from the List
	int scores;		 // Team total runs
	int extra;		 // Extra runs
	int wickets;	 // Total Wickets
	bool winStatus;  // Win Status label
	// To keep the composition concept we make 
	// 2 Arrays with size 16 for squad and 11 for playing11 Respectivally.
	Player squad[16];
	Player playing11[11];
public:
	Team(int =0, const string = "");//Default Constructor as well as 2 Peremeter Overloaded (ID, Name) 
	//All the Required Setter and getter functions.
	void setTeamID(int); 
	void setTeamName(const string = "");
	void setWinStatus(bool);
	const int getTeamID()const;
	const string getTeamName()const;
	const int getWickets()const;
	const int getScores()const;
	const Player getPlayer(int i)const;
	const bool getWinStatus()const;
	const int getExtra()const;
	//Read From the file 
	void readFromFile(ifstream&, int);
	//Generte the List of Teams 
	void generatingFile();
	//Decision of Game (rule, play, exit) and the required implementations.
	void decisionOfGame();
	//Selection of playing 11 form the squads of each Team.
	void selectionOfPlaying11();
	//Batting Order Modifications of Your Team of 11  Players
	void battingOrderModification();
	//Oponenet Team Selection from the list of 5 Team as given.
	void oponenetTeamSelection(int);
	//Decision of Toss randomely and the implementation requird after toss.
	const int decisionOfToss();
	//Batting and Bowling function the reference Peremeter is the no of balls which may incremeant/Decrement Accordingly.
	void batting(int &);
	void bowling(int &);

};

