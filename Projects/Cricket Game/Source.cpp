/*
Group Members:
Abdul Aziz		BCSF19A026
Imran Khan		BCSF20A018
Muhammad Umar	BCSF20A012
*/

#include "Team.h"

int main()
{
	srand(time(0));
	Team t1, t2; // file will be generated 2 times but we keep the same name so overwrite the File just nothing to worry.
	t1.decisionOfGame();
	cout << "Chose The Opponent Team.\n";
	// in the argument we set the Team t1 ID to prevent from itself selection for oponent
	t2.oponenetTeamSelection(t1.getTeamID());
	//Toss selection return 1/2.
	int choice = t1.decisionOfToss();
	int matchType, noOfOvers;
	//Selection of Game.
	cout << "Select from the following\n";
	cout << "\t1. T20\n";
	cout << "\t2. ODI\n";
	cout << "\t3. T10\n";
	cout << "\t4. Other\n";
	cout << "Your Selection: ";
	cin >> matchType;
	while (matchType < 1 || matchType> 5)//Validation
	{
		cout << "Invalid Selection\n";
		cout << "Please Select (1-5): ";
		cin >> matchType;
	}
	if (matchType == 1)		//T20
	{
		noOfOvers = 20;
	}
	else if (matchType == 2) //ODI
	{
		noOfOvers = 50;
	}
	else if (matchType == 3) // T10
	{
		noOfOvers = 10;
	}
	else //User choice no of Overs
	{
		cout << "How many Overs Game you want\n";
		cin >> noOfOvers;
		while (noOfOvers < 1) // Overs in the match must be some positive no.
		{
			cout << "Invalid No of Overs\n";
			cout << "Must be a positive: ";
			cin >> noOfOvers;
		}
	}
	int i = 0, j = 0, k = 0, l = 0;
	// i, j for current no of overs and balls in that overs for team 1.
	// k, l for current no of overs and balls in that overs for team 2.
	bool innigsFinish = false; //innings finish label.
	if (choice == 1) // choice hold the return value from toss functions.
	{
		//Team 1 will bat 1st.
		system("cls");
		cout << "\t**1st Innings**\n\n";
		for (i = 0; i < noOfOvers; i++)
		{
			for (j = 0; j < 6; j++)
			{
				cout << "\n*************************************************\n";
				cout << "* " << t1.getTeamName() << " |" << t1.getScores() << "/" << t1.getWickets() << "|\tOvers: (" << i << "." << j << ")\t\t*\n";
				cout << "*************************************************\n";
				t1.batting(j);
				if (t1.getWickets() == 10)
				{
					innigsFinish = true;
					break;
				}
			}
			if (innigsFinish)
				break;
		}
		system("cls");
		cout << "\t**Innings Break**\n\n";
		cout << "Bowling........\n";
		cout << "Target: |" << t1.getScores() << "|";
		innigsFinish = false;
		for (k = 0; k < noOfOvers; k++)
		{
			for (l = 0; l < 6; l++)
			{
				cout << "\nTarget: |" << t1.getScores()<<"|";
				cout << "\n*************************************************\n";
				cout << "* " << t2.getTeamName() << " |" << t2.getScores() << "/" << t2.getWickets() << "|\tOvers: (" << k << "." << l << ")\t\t*\n";
				cout << "*************************************************\n";
				t2.bowling(l);
				if (t2.getWickets() == 10 || t2.getScores() > t1.getScores())
				{
					innigsFinish = true;
					break;
				}
			}
			if (innigsFinish)
				break;
		}
		system("cls");
		cout << "\t**Match Finish**\n";
	}
	else
	{
		//Team 2 bat 1st.
		system("cls");
		cout << "\t**1st Innings**\n\n";
		innigsFinish = false;
		for (k = 0; k < noOfOvers; k++)
		{
			for (l = 0; l < 6; l++)
			{
				cout << "\n*************************************************\n";
				cout << "* " << t2.getTeamName() << " |" << t2.getScores() << "/" << t2.getWickets() << "|\tOvers: (" << k << "." << l << ")\t\t*\n";
				cout << "*************************************************\n";
				t2.bowling(l);
				if (t2.getWickets() == 10)
				{
					innigsFinish = true;
					break;
				}
			}
			if (innigsFinish)
				break;
		}
		system("cls");
		cout << "\t**Innings Break**\n\n";
		cout << "Batting........\n";
		cout << "Target: |" << t2.getScores() << "|\n\n";
		innigsFinish = false;
		for (i = 0; i < noOfOvers; i++)
		{
			for (j = 0; j < 6; j++)
			{
				cout << "\nTarget: |" << t2.getScores() << "|";
				cout << "\n*************************************************\n";
				cout << "* " << t1.getTeamName() << " |" << t1.getScores() << "/" << t1.getWickets() << "|\tOvers: (" << i << "." << j << ")\t\t*\n";
				cout << "*************************************************\n";
				t1.batting(j);
				if (t1.getWickets() == 10 || t1.getScores() > t2.getScores())
				{
					innigsFinish = true;
					break;
				}
				
			}
			if (innigsFinish)
				break;
		}
		system("cls");
		cout << "\t**Match Finish**\n";
	}
	if (t1.getScores() == t2.getScores())
	{
		cout << "\n\t******This Match Draw*******\n\n";
	}
	else if (t1.getScores() > t2.getScores())
	{
		t1.setWinStatus(true);
		cout << "Congratulation! " << t1.getTeamName() << "\nYou Won the Match by " << t1.getScores() - t2.getScores() << endl;
	}
	else
	{
		t2.setWinStatus(true);
		cout << "You lose the Match\n\tBest Luck for the next game:)\n";
		cout << "Congratulation! " << t2.getTeamName() << "\nYou Won the Match by " << t2.getScores() - t1.getScores() << endl;
	}
	if (j == 6 || j == 5)
	{
		if (j == 6)
			j = 0;
		else
		{
			j = 0;
			i++;
		}
	}
	else
	{
		j++;
	}
	
	if (l == 6 || l == 5)
	{
		if (l == 6)
			l = 0;
		else
		{
			l = 0;
			k++;
		}
	}
	else
	{
		l++;
	}
	cout << "\n\n\t**Match Summary**\n\n\n";
	Player playerOfTheMatch; // Man of the Match
	if (t2.getWinStatus()) 
	{
		cout << "\n*************************************************\n";
		cout << "* " << t1.getTeamName() << " |" << t1.getScores() << "/" << t1.getWickets() << "|\tOvers: (" << i << "." << j << ")\t\t*\n";
		cout << "*************************************************\n";
		cout << endl << endl;
		cout << setw(3) << "ID" << setw(25) << "Player_Name" << setw(18) << "Status" << setw(15) << "Runs\n";
		for (int s = 0; s < 60; s++)
			cout << "_";
		cout << endl;
		Player temp;
		for (int s = 0; s <= t1.getWickets(); s++)
		{
			temp = t1.getPlayer(s);
			temp.display();
			cout << setw(10) << temp.getPlayerScore() << endl;
		}
		cout << "\n\t\tExtras: (" << t1.getExtra() << ")\n";
		cout << endl << endl << endl;
		cout << "\n*************************************************\n";
		cout << "* " << t2.getTeamName() << " |" << t2.getScores() << "/" << t2.getWickets() << "|\tOvers: (" << k << "." << l << ")\t\t*\n";
		cout << "*************************************************\n";
		cout << endl << endl;
		cout << setw(3) << "ID" << setw(25) << "Player_Name" << setw(18) << "Status" << setw(15) << "Runs\n";
		for (int s = 0; s < 60; s++)
			cout << "_";
		cout << endl;
		int max;
		temp = t2.getPlayer(0);
		max = temp.getPlayerScore();
		for (int s = 0; s <= t2.getWickets(); s++)
		{
			temp = t2.getPlayer(s);
			temp.display();
			cout << setw(10) << temp.getPlayerScore() << endl;
			if (max <= temp.getPlayerScore())
			{
				max = temp.getPlayerScore();
				playerOfTheMatch = t2.getPlayer(s);
			}
		}
		cout << "\n\t\tExtras: (" << t2.getExtra() << ")\n";
	}
	else
	{
		cout << "\n*************************************************\n";
		cout << "* " << t2.getTeamName() << " |" << t2.getScores() << "/" << t2.getWickets() << "|\tOvers: (" << k << "." << l << ")\t\t*\n";
		cout << "*************************************************\n";
		cout << endl << endl;
		cout << setw(3) << "ID" << setw(25) << "Player_Name" << setw(18) << "Status" << setw(15) << "Runs\n";
		for (int s = 0; s < 60; s++)
			cout << "_";
		cout << endl;
		Player temp;
		for (int s = 0; s <= t2.getWickets(); s++)
		{
			temp = t2.getPlayer(s);
			temp.display();
			cout << setw(10) << temp.getPlayerScore() << endl;
		}
		cout << "\n\t\tExtras: (" << t2.getExtra() << ")\n";
		cout << endl << endl << endl;
		cout << "\n*************************************************\n";
		cout << "* " << t1.getTeamName() << " |" << t1.getScores() << "/" << t1.getWickets() << "|\tOvers: (" << i << "." << j << ")\t\t*\n";
		cout << "*************************************************\n";
		cout << endl << endl;
		cout << setw(3) << "ID" << setw(25) << "Player_Name" << setw(18) << "Status" << setw(15) << "Runs\n";
		for (int s = 0; s < 60; s++)
			cout << "_";
		cout << endl;
		int max;
		temp = t1.getPlayer(0);
		max = temp.getPlayerScore();
		for (int s = 0; s <= t1.getWickets(); s++)
		{
			temp = t1.getPlayer(s);
			temp.display();
			cout << setw(10) << temp.getPlayerScore() << endl;
			if (max <= temp.getPlayerScore())
			{
				max = temp.getPlayerScore();
				playerOfTheMatch = t1.getPlayer(s);
			}
		}
		cout << "\n\t\tExtras: (" << t1.getExtra() << ")\n";
	}
	cout << "\n\n\t******Man Of The Match*******\n";
	playerOfTheMatch.display();
	cout << "\t\tRuns: " << playerOfTheMatch.getPlayerScore() << endl;
	return 0;
}