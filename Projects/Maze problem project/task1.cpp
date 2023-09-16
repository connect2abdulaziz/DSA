//  TASK #1
//  Abdul Aziz
//  BCSF19A026
//  Add/drop CS-Afternoon
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.cpp"
using namespace std;

struct Pair // to track the path we have to store it an data type of Pair i.e i,j where i,j mean ith row and jth column
{
	int c{};
	int r{};
};
Stack<Pair> pathTracking(char **, Pair, Pair, int);
int main()
{
	string fileName;
	cout << "Enter File Name to read input from i.e (in.txt): ";
	getline(cin, fileName);
	while (true)
	{
		ifstream fin{};
		ofstream fout{};
		int size{};
		char **maze{};
		Pair source{}, destination{};
		fin.open(fileName);
		if (!fin)
		{
			cout << "ERROR!! ";
			cout << "Invalid file Name\n";
			cout << "File with Name (" << fileName << ") is not found\n";
			exit(0);
		}
		else
		{
			fin >> size;
			fin >> source.r >> source.c;
			fin >> destination.r >> destination.c;
			maze = new char *[size] {};
			for (int i = 0; i < size; i++)
				maze[i] = new char[size]{};
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					fin >> maze[i][j];
			fin.close();
		}
		char ch;
		cout << "Please Select from the following:\n";
		cout << "Press 1 to check for Assignment Task as it is\n";
		cout << "Press 2 to Customize the source and Destination\n";
		cout << "Press 0 to exit\n";
		cout << "Your Selection: ";
		cin >> ch;
		while (ch < '0' || ch > '2')
		{
			cout << "ERROR!! Invalid Selection\n";
			cout << "Re-select from 0-2: ";
			cin >> ch;
		}
		if (ch == '0')
			exit(0);
		if (ch == '2')
		{
			int i, j;
			cout << "Enter Source: ";
			cin >> i >> j;
			while (i < 0 || i > size - 1 || j < 0 || j > size - 1 || maze[i][j] != '0')
			{

				if (!(i < 0 || i > size - 1 || j < 0 || j > size - 1))
					cout << "ERROR!! Source must be 0 (open end)!\n";
				else
					cout << "ERROR!! Invalid Source indexes\n";
				cout << "Re-select from 0,0 to " << size - 1 << "," << size - 1 << ": ";
				cin >> i >> j;
			}
			source.r = i;
			source.c = j;
			cout << "Enter Destination: ";
			cin >> i >> j;
			while (i < 0 || i > size - 1 || j < 0 || j > size - 1 || maze[i][j] != '0')
			{
				if (!(i < 0 || i > size - 1 || j < 0 || j > size - 1))
					cout << "ERROR!! Destination must be 0 (open end)!\n";
				else
					cout << "ERROR!! Invalid Destination indexes\n";
				cout << "Re-select from 0,0 to " << size - 1 << "," << size - 1 << ": ";
				cin >> i >> j;
			}
			destination.r = i;
			destination.c = j;
		}
		// the function Track the path successfully and store it to a Stack
		Stack<Pair> path = pathTracking(maze, source, destination, size);
		// to check if path is available
		if (path.isEmpty())
			cout << "No possible Path found from (" << source.r << "," << source.c << ") to (" << destination.r << "," << destination.c << ")\n";
		else
		{
			fout.open("out.txt");
			if (!fout)
			{
				cout << "ERROR!! Output file can't generated\n";
				exit(0);
			}
			else
			{
				// Here now I display the required output on the console as well as
				//  writing to the output file out.txt.
				cout << size << endl;
				cout << source.r << " " << source.c << endl;
				cout << destination.r << " " << destination.c << endl;
				fout << size << endl;
				fout << source.r << " " << source.c << endl;
				fout << destination.r << " " << destination.c << endl;
				while (!path.isEmpty())
				{
					Pair temp = path.pop();
					cout << "(" << temp.r << "," << temp.c << ")";
					fout << "(" << temp.r << "," << temp.c << ")";
				}
				fout << endl;
				cout << endl;
				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{
						if (maze[i][j] == 3)
							maze[i][j] = '0';
						cout << maze[i][j] << " ";
						fout << maze[i][j] << " ";
					}
					cout << endl;
					fout << endl;
				}
				cout << "\nThe Output file out.txt is generated successfully\n";
				fout.close(); // closing the output file
			}
		}

		// Deallocating the dynamically created memory on heap
		// also handling the problem of dangling pointer
		for (int i = 0; i < size; i++)
		{
			if (maze[i])
			{
				delete[] maze[i];
				maze[i] = NULL;
			}
		}
		if (maze)
			delete[] maze;
		maze = NULL;
		cout << endl
			 << endl;
	}
	return 0;
}
Stack<Pair> pathTracking(char **maze, Pair source, Pair destination, int size)
{
	Stack<Pair> path;
	path.push(source);
	Pair temp;
	int i = source.r;
	int j = source.c;
	temp = source;
	maze[i][j] = 2;
	bool flag = false;
	while (!flag && !path.isEmpty())
	{
		if (temp.r == destination.r && temp.c == destination.c)
			flag = true;
		else
		{
			// checking for path if possible
			if (j < (size - 1) && maze[i][j + 1] == '0')
				j++;
			else if (i < (size - 1) && maze[i + 1][j] == '0')
				i++;
			else if (j > 0 && maze[i][j - 1] == '0')
				j--;
			else if (i > 0 && maze[i - 1][j] == '0')
				i--;
			else
				temp = path.pop();
			if (temp.r == i && temp.c == j)
			{
				if (maze[i][j] == 2) // to block the path at this point for being recursively circulating in this.
				{
					maze[i][j] = 3; // the dead path.
					if (path.isEmpty())
						break;
					i = path.stackTop().r;
					j = path.stackTop().c;
				}
				else
					maze[i][j] = 3; // the dead path
			}
			else
			{
				temp.r = i;
				temp.c = j;
				path.push(temp);
				maze[i][j] = 2; // to preserve the path we come from to not stuck in the same maze.
			}
		}
	}
	// Now the path is present in reverse order from destination to source thats why
	//  to reverse it we tack a temp stack and do it simply
	Stack<Pair> path1{};
	while (!path.isEmpty())
	{
		Pair p = path.pop();
		maze[p.r][p.c] = '*';
		path1.push(p);
	}
	return path1;
}