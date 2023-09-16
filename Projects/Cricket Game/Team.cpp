/*
Group Members:
Abdul Aziz		BCSF19A026
Imran Khan		BCSF20A018
Muhammad Umar	BCSF20A012
*/


#include "Team.h"
//Default Constructor as well as 2 peremeter Overloaded team(ID,Name).
Team::Team(int id, const string n) : scores(0), wickets(0), extra(0),winStatus(false), squad(), playing11()
{
	//assing the ID and Team Name to the attribute ID, Name (Team).
	setTeamID(id);
	setTeamName(n);
	// This Function generate the file of 5 Teams each 16 Player squad as we 
	// Write in the Function (generatingFile()) each time the Team obj is created
	// any where in the program. 
	generatingFile();
}

void Team::generatingFile()
{
	/// <summary>
	/// This Fuction generate a file (teamPlayers) with txt extension
	/// as well as place the 16 Player squad of the Given team as 
	/// mention in the projects.
	/// The function create the File with in the Directory of Project
	/// if You need to update the Game with more Teams just include the list
	/// of the respective team in the function with a single fout statement.
	/// </summary>
	ofstream fout;
	fout.open("teamPlayers.txt");
	if (!fout)
	{
		cout << "File could not Created Successfully\n";
	}
	else
	{
		// In each line the 1st place is Player ID, followed by the Status of the Player(Batsman, Bowler, Alrounder) and the rest of the line is the Player name.
		fout << "1 Batsman Babar Azam (c)\n2 Batsman Mohammad Rizwan\n3 Batsman Asif Ali\n4 Batsman Fakhar Zaman\n5 Batsman Haider Ali\n6 Allrounder Hasan Ali\n7 Allrounder Imad Wasim\n8 Bowler Haris Rauf\n9 Bowler Shaheen Shah Afridi\n10 Bowler Mohammad Hasnain\n11 Allrounder Mohammad Nawaz\n12 Allrounder Shadab Khan\n13 Bowler Mohammad Wasim\n14 Allrounder Mohammad Hafeez\n15 Batsman Sohaib Maqsood\n16 Allrounder Shoaib Malik\n";
		fout << "1 Batsman Aaron Finch (c)\n2 Batsman David Warner\n3 Batsman Steve Smith\n4 Allrounder Marcus Stoinis\n5 Batsman Mitchell Marsh\n6 Allrounder Glenn Maxwell\n7 Bowler Adam Zampa\n8 Bowler Pat Cummins (vc)\n9 Bowler Josh Hazlewood\n10 Bowler Kane Richardson\n11 Bowler Mitchell Starc\n12 Bowler Ashton Agar\n13 Bowler Mitchell Swepson\n14 Batsman Matthew Wade\n15 Bowler Josh Inglis\n16 Allrounder Dan Christian\n";
		fout << "1 Batsman Kane Williamson(c)\n2 Batsman Mark Chapman\n3 Batsman Martin Guptill\n4 Batsman Glenn Phillips\n5 Batsman Tim Seifert\n6 Batsman Daryl Mitchell\n7 Allrounder Jimmy Neesham\n8 Allrounder Mitchell Santner\n9 Bowler Todd Astle\n10 Bowler Trent Boult\n11 Bowler Adam Milne\n12 Bowler Kyle Jamieson\n13 Bowler Ish Sodhi\n14 Bowler Tim Southee\n15 Bowler Lockie Ferguson\n16 Batsman Rose Taylor\n";
		fout << "1 Batsman Brendan Taylor(c)\n2 Batsman Donald Tripano\n3 Batsman Sean Williams\n4 Allrounder Sikandar Raza\n5 Batsman Milton Shumba\n6 Batsman Tarisai Musakanda\n7 Batsman Dion Myers\n8 Bowler Blessing Muzarabani\n9 Bowler Richard Ngarava\n10 Bowler Wellington Masakadza\n11 Bowler Tadiwanashe Marumani\n12 Batsman Wessley Madhevere\n13 Bowler Tinashe Kamunhaukamwe\n14 Allrounder Luke Jongwe\n15 Allrounder Craig Ervine\n16 Allrounder Tendai Chatara\n";
		fout << "1 Batsman Dasun Shanaka (c)\n2 Allrounder Dhananjaya De Silva\n3 Batsman Avishka Fernando\n4 Batsman Bhanuka Rajapaksa\n5 Batsman Charith Asalanka\n6 Batsman Minod Bhanuka\n7 Allrounder Ramesh Mendis\n8 Allrounder Wanindu Hasaranga\n9 Bowler Dushmantha Chameera\n10 Bowler Isuru Udana\n11 Bowler Dhananjaya Lakshan\n12 Bowler Praveen Jayawickrama\n13 Bowler Akila Dananjaya\n14 Batsman Ashen Bandara\n15 Allrounder Chamika Karunaratne\n16 Batsman Lahiru Udara\n";
	}

}
void Team::setTeamID(int id)
{
	if (id > 0 && id < 6) //As for now there is 5 team so the validation for the team ID.
		teamID = id;
	else
		teamID = 0;
}
void Team::setTeamName(const string n)
{
	teamName = n;
}
void Team::setWinStatus(bool a)
{
	winStatus = a;
}
const int Team::getTeamID()const
{
	return teamID;
}
const string Team::getTeamName()const
{
	return teamName;
}
const int Team::getWickets()const
{
	return wickets;
}
const int Team::getScores()const
{
	return scores;
}
const bool Team::getWinStatus()const
{
	return winStatus;
}
const Player Team::getPlayer(int i)const
{
	if (i >= 0 && i < 11) // to Get any Player in the Team i is the ID no index (0-10).
		return playing11[i];
	else 
	{
		cout << "Invalid\nA team only of 11 Player so Boundray check for value othe than (0-10)\n";
		return Player();// A temprory player with no Data is return to prevent from run time error.
	}
}
const int Team::getExtra()const
{
	return extra;
}
//1st of all this function is called to Decide What the user want.
void Team::decisionOfGame()
{
	char ch;
	cout << "\t\t**Welcome**\n";
line:// if the user want to see the Rule before to Play this goto keyward jump back to that place.
	cout << "Select an option(1-3):\n";
	cout << "\t1. Play\n";
	cout << "\t2. Rules\n";
	cout << "\t3. Exit ";
	cin >> ch;
	while (ch < '1' || ch> '3')// Vallidation
	{
		cout << "Invalid\n";
		cout << "Re-select (1-3): ";
		cin >> ch;
	}
	system("cls");
	if (ch == '1') // user want to play
	{
		cout << "Select your team from the following.\n";
		cout << "\t1. Pakistan\n";
		cout << "\t2. Australia\n";
		cout << "\t3. New Zealand\n";
		cout << "\t4. Zimbabwe\n";
		cout << "\t5. Sri Lanka\n";
		cout << "Your team: ";
		cin >> ch;
		while (ch < '1' || ch> '5')// Team validation
		{
			cout << "Invalid\n";
			cout << "Re-select (1-5): ";
			cin >> ch;
		}
		system("cls");
		// the fstream varriable fin will send as a reference argument in the function (readFromFile).
		ifstream fin;
		if (ch == '1')
		{
			//Assigning the Team name and ID to the Team object.
			teamID = 1;
			teamName = "Pakistan";
			//In this function the squad array of 16 player is updated from the file.
			readFromFile(fin, 0);
		}
		else if (ch == '2')
		{
			teamID = 2;
			teamName = "Australia";
			readFromFile(fin, 1);
		}
		else if (ch == '3')
		{
			teamID = 3;
			teamName = "New Zealand";
			readFromFile(fin, 2);
		}
		else if (ch == '4')
		{
			teamID = 4;
			teamName = "Zimbabwe";
			readFromFile(fin, 3);
		}
		else
		{
			teamID = 5;
			teamName = "Sri Lanka";
			readFromFile(fin, 4);
		}
		// After Successfully Reading from the file than the next task to 
		// Selection of team and Batting order modifications.
		selectionOfPlaying11();
		battingOrderModification();
	}
	else if (ch == '2')
	{
		// If There is any new user want to know the Game Rule.
		// The following Rules is need to Read before Play.
		cout << "\t\t**Rules**\n";
		cout << "\nBowling Rules are below\n";
		cout << "\nNote Bowling Rules are Dependent on Batsman Behavier\nif the Batsman want to not Strike played Defensively than it's Okay\notherwise if will follow the following rules:\n";
		cout << "\n1. Noball\nBall is considered as No ball if the DistanceV is less than 50 feets\nWhenever a Noball it will go for 4 or 6 an (+1) extra runs and (-1) from ball left\n";
		cout << "\n2. Wide\nBall is considered as Wide if the DistanceH is Greater than 3 feets\nWhenever a Wide ball it will go for 4 runs and (+1) extra rusn with (-1) from the ball left\n";
		cout << "\n3. Bouncer\nBall is considered as Bouncer if Hiegth of ball exceeded 5 feets\nWhenever a Bouncer there may be Chance of 6 runs, Catch out  or Hitwicket\n";
		cout << "\n4. Spin\nBall is considered as Spin is Deviation of ball is +5 | -5 degree from 90\nWhenever a Spin there may be a probibilty of 0,1,2,4,6 runs as well as Chance of Out (LBW, Hitwicket, Catchout)\n";
		cout << "\nNote: (If the Ball is non of the above condition than as considered as Normal Ball) which has the Probiblity of runs (0,1,2,4,6) or out (LBW,Hitwickets,Catch)\n";
		cout << "\nBatting Rules are below\n";
		cout << "\n1 isStrike\nThe Batsman is asked to Strike the ball or leave it Defensive\nif Not Strike the Ball carray no runs\nif Strick the ball it depend on the Ball (Noball, Wide , Bouncer, Spin, Normal)\nso runs come accordingly\n\n";
		goto line;
	}
	else
	{
		exit(0);
	}
}
void Team::readFromFile(ifstream& fin, int a)
{
	//in the peremter (a) is the id no of the Selected team to read from the generated file 
	//we use the txt file as mention in the program to keep it txt.
	fin.open("teamPlayers.txt", ios::in);
	if (!fin)
	{
		cout << "File could not found\n";
	}
	else
	{
		string tempName;
		int tempID;
		// this loop is to skip the player from the list in the file if a != 0.
		for (int i = 0; i < a * 16; i++)
			getline(fin, tempName);
		// Now we are in the file in the selected location 
		// This loop will pick the player from the file and place it in the squad arrays.
		for (int i = 0; i < 16; i++)
		{
			//picking the ID
			fin >> tempID;
			//Setting the ID in squad array.
			squad[i].setPlayerID(tempID);
			//Picking and setting the Status(alrounder,Batsman, Bowler).
			fin >> tempName;
			squad[i].setPlayerStatus(tempName);
			//Now the rest of the line in the file is the whole name so we use getline.
			getline(fin, tempName);
			squad[i].setPlayerName(tempName);
		}
		fin.close();
	}
}
void Team::selectionOfPlaying11()
{
	cout << "Select Your squad of 11 playing from the following.\n\n";
	for (int i = 0; i < 16; i++)
	{
		squad[i].display();
		cout << endl;
	}
	cout << "\nEnter the number/ID to select the relevant Player.\n";
	int temp = 0;
	for (int i = 0; i < 11; i++)
	{
		cout << "Player " << i + 1 << ": ";
		cin >> temp;
		while (temp < 1 || temp > 16) //1st Validation
		{
			cout << "Invalid\nPlease select from the above list (1-16): ";
			cin >> temp;
		}
		for (int j = 0; j <= i; j++) //2nd Validation
		{
			//check if Player is already selected.
			if (playing11[j].getPlayerName() == squad[temp - 1].getPlayerName())
			{
				cout << "The Player is already selected once\nPlease Select another player: ";
				cin >> temp;
				while (temp < 1 || temp > 16) //1st Validation
				{
					cout << "Invalid\nPlease select from the above list (1-16): ";
					cin >> temp;
				}
				j = -1;
			}
		}
		// As array start from 0 so temp- 1 and i+1 mean to set the 
		// player ID.
		playing11[i] = squad[temp - 1];
		playing11[i].setPlayerID(i + 1);
	}
	system("cls");
}
void Team::battingOrderModification()
{
	cout << "Here is your selected team squad (Playing 11):\n\n";
	for (int i = 0; i < 11; i++)
	{
		playing11[i].display();
		cout << endl;
	}
	char choice;
	int temp1, temp2;
	// The loop will do modification unless the user entered N
	do
	{
		cout << "Do you want modify the batting order\n";
		cout << "(Y/N)? ";
		cin >> choice;
		while (!(toupper(choice) == 'Y' || toupper(choice) == 'N'))//Validations 
		{
			cout << "Invalid\nPlease press (Y/N): ";
			cin >> choice;
		}
		if (toupper(choice) == 'Y')
		{
			cout << "Please enter the id number of the players\n";
			cout << "which needs to be modified: ";
			cin >> temp1;
			while (temp1 < 1 || temp1 > 11)//Validation if ID is in range of 1-11.
			{
				cout << "Invalid\nPlease Enter in range of (1-11): ";
				cin >> temp1;
			}
			temp1--;// temp-- mean the Player array start from the 0
			cout << "Please specify the position number in the team\n";
			cout << "to insert the player: ";
			cin >> temp2;
			while (temp2 < 1 || temp2 > 11) // position validation from 1-11.
			{
				cout << "Invalid\nPlease Enter in range of (1-11): ";
				cin >> temp2;
			}
			temp2--; // Same as above 
			//swaping to make modify the batting orders
			string tempPlayr;
			// 1st to swip the player name and next the Status.
			tempPlayr = playing11[temp1].getPlayerName();
			playing11[temp1].setPlayerName(playing11[temp2].getPlayerName());
			playing11[temp2].setPlayerName(tempPlayr);

			tempPlayr = playing11[temp1].getPlayerStatus();
			playing11[temp1].setPlayerStatus(playing11[temp2].getPlayerStatus());
			playing11[temp2].setPlayerStatus(tempPlayr);
			cout << "Modified Successfully\n";
		}

	} while (toupper(choice) != 'N');
	//After modification Displaying the modified Playing 11.
	system("cls");
	cout << "\t**Modified List**\n\n";
	for (int i = 0; i < 11; i++)
	{
		playing11[i].display();
		cout << endl;
	}
	cout << endl << endl;
}
void Team::oponenetTeamSelection(int a)
{
	srand(time(0));
	int ch;
	cout << "Select your team from the following.\n";
	cout << "\t1. Pakistan\n";
	cout << "\t2. Australia\n";
	cout << "\t3. New Zealand\n";
	cout << "\t4. Zimbabwe\n";
	cout << "\t5. Sri Lanka\n";
	cout << "Your team: ";
	cin >> ch;
	system("cls");
	while (ch < 1 || ch> 5) // 1st Validation for Team selection for oponent 
	{
		cout << "Invalid\n";
		cout << "Re-select (1-5): ";
		cin >> ch;
	}
	while (ch == a) // 2nd Validation check if user pick its own team (team can't play against itself).
	{
		cout << "You Can't Play with Your own team\n";
		cout << "Re-Select: ";
		cin >> ch;
		while (ch < 1 || ch> 5)
		{
			cout << "Invalid\n";
			cout << "Re-select (1-5): ";
			cin >> ch;
		}
	}
	ifstream fin;
	if (ch == 1)
	{
		// to set team name and id.
		teamID = 1;
		teamName = "Pakistan";
		// the 2nd argument will tell the read function to pick the 16 player squad of the Selected team from the file.
		readFromFile(fin, 0);
	}
	else if (ch == 2)
	{
		teamID = 2;
		teamName = "Australia";
		readFromFile(fin, 1);
	}
	else if (ch == 3)
	{
		teamID = 3;
		teamName = "New Zealand";
		readFromFile(fin, 2);
	}
	else if (ch == 4)
	{
		teamID = 4;
		teamName = "Zimbabwe";
		readFromFile(fin, 3);
	}
	else
	{
		teamID = 5;
		teamName = "Sri Lanka";
		readFromFile(fin, 4);
	}
	// Selection of Playing 11 from the squad 
	for (int i = 0; i < 11; i++)
	{
		playing11[i] = squad[i];
		// Setting the Player ID for Playing 11 of the oponent team.
		playing11[i].setPlayerID(i + 1);
	}
	system("cls");
	// Displaying the oponent team of 11 players as we pick from the squad above.
	cout << "Oponent team Playing 11\n\n";
	for (int i = 0; i < 11; i++)
	{
		playing11[i].display();
		cout << endl;
	}
	cout << endl << endl;
}
const int Team::decisionOfToss()
{
	cout << "\n\t**Decision Of Toss**\n\n";
	srand(time(0));
	int choice;
	cout << "Heads or Tails?\n";
	cout << "\t1. Heads\n";
	cout << "\t2. Tails\n";
	cout << "Enter your Choice: ";
	cin >> choice;
	while (choice < 1 || choice > 2)// validation
	{
		cout << "Invalid Please Select 1 or 2: ";
		cin >> choice;
	}
	system("cls");
	int toss = (rand() % 2) + 1; //1,2
	if (choice == toss)
	{
		cout << "Congratulations! You won the toss.. Would\nyou like to bat or bowl 1st?\n";
		cout << "\t1. Bat\n\t2. Bowl\n";
		cout << "Your choice: ";
		cin >> choice;
		while (choice < 1 || choice > 2)// Validation for Bat/Bawl
		{
			cout << "Invalid Please Select 1 or 2: ";
			cin >> choice;
		}
		return choice;//return 1/2.
		system("cls");
	}
	else
	{
		cout << "Sorry, You lost the toss..\nthe opponent has chosen to bat.\n";
		cout << "\n\n\n";
		//As given in the Project the oponenet always bat 1st.
		return 2;
	}

}
void Team::batting( int& ball)
{
	srand(time(0));
	// int a = rand()%5
	// if ( a == 0)no ball, if ( a == 1 ) wide , 
	const int distanceV = 50, distanceH = 3, height = 6, deviation = 5;
	int userDistanceV = rand() % 100 + 40;// we assume that 10% chance of no ball randomly; 
	int  userDistanceH = rand() % 5;// we assume if rand no is 4 to be wide else not,
	int userHeight = rand() % 10;// we assume if rand no is 7, 8, 9 almost 33% chance of Bouncer.
	int userDeviation = (rand() % 20) - 10;// we assume that 40 % chance of spin ball as of rand 6,7,8,9,-6,-7,-8, -9,.
	//else normal ball.
	/*
	Randomization can be increase decrease
	according to game difficulty level.
	*/

	int a;
	cout << endl << endl;
	//Asking for Strike or not.
	cout << "Do you want to Strke the ball or take it Defensivelly\n";
	cout << "\t1. Strike\n";
	cout << "\t2. Defensive\n";
	cout << "Your selection: ";
	cin >> a;
	bool isStrike = false;
	while (a < 1 || a> 2) // validation Check.
	{
		cout << "invalid Selection\n";
		cout << "Select from 1 and 2: ";
		cin >> a;
	}
	system("cls");
	if (a == 1)
		isStrike = true;
	// We Initilize all the label to false than Check for all the bowl categry and 
	// update the label true if any
	bool noball = false, wide = false, bouncer = false, spin = false;
	if (userDistanceV < distanceV)
	{
		// No ball make 1 extra runs in the score and the over ball is increased by 1.

		cout << "Noball\n";
		ball--;// here i decrement the reference peremeter of ball because 
				// if ball in over is already 4 so to make it 4 and prevent
				// from ball exceed in the over will finish after 1 extra ball.
		extra++;
		scores++;
		noball = true;
	}
	else if (userDistanceH > distanceH)
	{
		//Same is noball
		cout << "Wide\n";
		ball--;
		extra++;
		scores++;
		wide = true;
	}
	else if (userHeight > height)
	{
		cout << "Bouncer\n";
		bouncer = true;
	}
	else if (abs(userDeviation) > deviation)
	{
		cout << "Spin\n";
		spin = true;
	}
	else
	{
		cout << "Normal Delieveray\n";
	}
	if (isStrike) // Checking if Batsman Strike or Not 
	{
		/// <summary>
		///  if strike the ball next see the ball categries:
		///  Noball: 6/4
		///  Wide: 4 always
		///  Bouncer: 6/HitWicket/Catchout
		///  Spin: 0/1/2/4/6/LBW/Hitwicket/Catchout
		///  if the above 4 label is false mean the ball is normal.
		///	 so normal: 0/1/2/4/6/LBW/Hitwicket/Catchout
		/// </summary>
	
		if (noball)
		{
			a = rand() % 2;
			if (a == 0)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}

		}
		else if (wide)
		{
			scores += 4;
			playing11[wickets].incrementPlayerScore(4);
			cout << "4 runs\n";

		}
		else if (bouncer)
		{
			a = rand() % 3;
			if (a == 0)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else
			{
				wickets += 1;
				if (a == 1)
					cout << "HitWicket Out\n";
				else
					cout << "Catchout\n";

			}
		}
		else if (spin)
		{
			a = rand() % 8;
			if (a == 0)
				scores += 0;
			else if (a == 1)
			{
				scores += 1;
				playing11[wickets].incrementPlayerScore(1);
				cout << "1 runs\n";
			}
			else if (a == 2)
			{
				scores += 2;
				playing11[wickets].incrementPlayerScore(2);
				cout << "2 runs\n";
			}
			else if (a == 3)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else if (a == 4)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else // randomly selection for HitWicket = 5, LBW = 6, Catchout = 7;
			{
				wickets += 1;
				if (a == 5)
					cout << "HitWicket Out\n";
				else if (a == 6)
					cout << "LBW Out\n";
				else
					cout << "Catchout\n";
			}
		}
		else
		{
			a = rand() % 8;
			if (a == 0)
				scores += 0;
			else if (a == 1)
			{
				scores += 1;
				playing11[wickets].incrementPlayerScore(1);
				cout << "1 runs\n";
			}
			else if (a == 2)
			{
				scores += 2;
				playing11[wickets].incrementPlayerScore(2);
				cout << "2 runs\n";
			}
			else if (a == 3)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else if (a == 4)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else // randomly selection for HitWicket = 5, LBW = 6, Catchout = 7;
			{
				wickets += 1;
				if (a == 5)
					cout << "HitWicket Out\n";
				else if (a == 6)
					cout << "LBW Out\n";
				else
					cout << "Catchout\n";
			}

		}
	}
	else
	{
	    /// <summary>
		///  if not strike the ball next see the ball categries:
		///  Noball: 0 no runs come from bat of Batsman /just decrement of Ball and increment the extra runs which already done above in the label checking
		///  Wide: 0 // same as noball
		///  Bouncer: 0
		///  Spin: 0
		/// </summary>
		cout << "Defensivelly played the ball\n";
		cout << "No runs\n";
	}
}
void Team::bowling(int& ball)
{
	srand(time(0));
	/// <summary>
	///  Same is Batting but just keep the isStrike Random and 
	///  ask the Bowling label from the user 
	///  //1 distanceV ,2 distanceH,3 Height,4 Deviation
	/// </summary>

	const int distanceV = 50, distanceH = 3, height = 6, deviation = 5;
	int userDistanceV, userDistanceH, userHeight, userDeviation;
	cout << "Enter DistanceV: ";
	cin >> userDistanceV;
	cout << "Enter DistancH: ";
	cin >> userDistanceH;
	cout << "Enter Height: ";
	cin >> userHeight;
	cout << "Enter Deviation: ";
	cin >> userDeviation;
	system("cls");
	bool noball = false, wide = false, bouncer = false, spin = false;
	if (userDistanceV < distanceV)
	{
		cout << "Noball\n";
		ball--;
		extra++;
		scores++;
		noball = true;
	}
	else if (userDistanceH > distanceH)
	{
		cout << "Wide\n";
		ball--;
		extra++;
		scores++;
		wide = true;
	}
	else if (userHeight > height)
	{
		cout << "Bouncer\n";
		bouncer = true;
	}
	else if (abs(userDeviation) > deviation)
	{
		cout << "Spin\n";
		spin = true;
	}
	else
	{
		cout << "Normal Delieveray\n";
	}
	bool isStrike = rand() % 2;//0 1
	int a;//random decision
	if (isStrike)
	{
		if (noball)
		{
			a = rand() % 2;
			if (a == 0)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}

		}
		else if (wide)
		{
			scores += 4;
			playing11[wickets].incrementPlayerScore(4);
			cout << "4 runs\n";

		}
		else if (bouncer)
		{
			a = rand() % 3;
			if (a == 0)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else
			{
				wickets += 1;
				if (a == 1)
					cout << "HitWicket Out\n";
				else
					cout << "Catchout\n";

			}
		}
		else if (spin)
		{
			a = rand() % 8;
			if (a == 0)
				scores += 0;
			else if (a == 1)
			{
				scores += 1;
				playing11[wickets].incrementPlayerScore(1);
				cout << "1 runs\n";
			}
			else if (a == 2)
			{
				scores += 2;
				playing11[wickets].incrementPlayerScore(2);
				cout << "2 runs\n";
			}
			else if (a == 3)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else if (a == 4)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else // randomly selection for HitWicket = 5, LBW = 6, Catchout = 7;
			{
				wickets += 1;
				if (a == 5)
					cout << "HitWicket Out\n";
				else if (a == 6)
					cout << "LBW Out\n";
				else
					cout << "Catchout\n";
			}
		}
		else
		{
			a = rand() % 8;
			if (a == 0)
				scores += 0;
			else if (a == 1)
			{
				scores += 1;
				playing11[wickets].incrementPlayerScore(1);
				cout << "1 runs\n";
			}
			else if (a == 2)
			{
				scores += 2;
				playing11[wickets].incrementPlayerScore(2);
				cout << "2 runs\n";
			}
			else if (a == 3)
			{
				scores += 4;
				playing11[wickets].incrementPlayerScore(4);
				cout << "4 runs\n";
			}
			else if (a == 4)
			{
				scores += 6;
				playing11[wickets].incrementPlayerScore(6);
				cout << "6 runs\n";
			}
			else // randomly selection for HitWicket = 5, LBW = 6, Catchout = 7;
			{
				wickets += 1;
				if (a == 5)
					cout << "HitWicket Out\n";
				else if (a == 6)
					cout << "LBW Out\n";
				else
					cout << "Catchout\n";
			}

		}
	}
	else
	{
		cout << "Defensivelly played the ball\n";
		cout << "No runs\n";
	}
}