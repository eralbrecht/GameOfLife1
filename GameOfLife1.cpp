//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
//include other game modes
using namespace std;
int main()
{
	int columns;
	int rows;
	int repeat;
	int generation = 1;
	//add in game type options
	cout << "what game version would you like to play?" << endl;
	cout << "options include donut, mirror, or classic" << endl;
	cout << "please enter 'd' 'm' or 'c'" << endl;
	char gameMode;
	cin >> gameMode;
	cout << "would you like to print to console or a text file enter c or txt?" << endl;
	string outputMode;
	cin >> outputMode;
	//initiate the file for if we decide we want to print to it
	ofstream outputfile;
	outputfile.open("rosealbrechtoutput.txt", ios::out | ios::app);
	if (outputMode == "txt")
	{
		outputfile << "RoseAlbrecht 2300456" << endl;
		outputfile << "Game Of Life" << endl;
		outputfile << "Starting Game Board" << endl;
	}
	cout << "would you like to provide a map file" << endl;
	cout << "for a map of the world in which the" << endl;
	cout << "simulation would occur? y or n" << endl;
	char inputChoice;
	cin >> inputChoice;
	if (inputChoice == 'y')
	{
		cout << " - 39 -";
		string fileName;
		cout << "what is the name of the file you would like read?" << endl;
		cout << "please insure that your input file is as follows:" << endl;
		cout << "columns" << endl;
		cout << "rows" << endl;
		cout << "empty cells as '-' living cells as 'X' with no other charachters present" << endl;
		cout << "each row of cells should be a new line in the input file" << endl;
		cin >> fileName;
		if (outputMode == "c")
		{
			cout << " - 50 -";
			cout << "RoseAlbrecht 2300456" << endl;
			cout << "Starting Game Board:" << endl;
			cout << "each row of cells should be a new line in the input file" << endl;
		}
		cout << " - 54 - " << endl;
		ifstream inputFile;
		inputFile.open(fileName);
		int lineCount = 0;
		string str;//temp string while reading file
		string worldString;//will hold all the letters relevent to the world generation
		while (getline(inputFile, str))
		{
			if (lineCount == 0)
			{
				columns = stoi(str);//this will turn the string into an int
			}
			if (lineCount == 1)
			{
				rows = stoi(str);
			}
			if (lineCount > 1)
			{
				for (char letter : str)
				{
					if (letter == 'X' || letter == 'x' || letter == '-')
					{
						worldString = worldString + letter;

					}
				}
			}
			lineCount += 1;
		}
		//initialize all worlds to the size of the simulation space
		char world[columns][rows];
		//char newWorld[columns][rows];
		char archiveWorld[columns][rows];
		int tempPosition = 0;
		lineCount = 0;
		int columnCount;
		for (int i = 0; i < worldString.length(); ++i)
		{
			lineCount = i / columns;
			columnCount = i % columns;
			world[columnCount][lineCount] = worldString[i];//print the string into the array
		}
		tempPosition = 0;
		for (int h = 1; h <= rows; h++)//this for loop will print the initial world
		{
			for (int w = 1; w <= columns; w++)
			{
				world[w][h] = worldString[tempPosition];
				tempPosition += 1;
				if (outputMode == "c");
				{
					cout << world[w][h] << '\0';
				}
				if (outputMode == "txt");
				{
					outputfile << world[w][h];
				}

			}
			if (outputMode == "c");
			{
				cout << endl;
			}
			if (outputMode == "txt");
			{
				outputfile << endl;
			}

		}
		//read the file enough to get height and width
		//implament something here to input the file and use it and a array method to make the necessary 2D array
	}
	if (inputChoice == 'n')
	{
		cout << "how many rows would you like?" << endl;
		cin >> rows;
		cout << "how many columns would you like?" << endl;
		cin >> columns;
		cout << "what population density would you like(choose a number between 0 and 1)?" << endl;
		double popDensity;
		cin >> popDensity;
		char world[columns][rows];
		int populatedCells = popDensity * (rows*columns);
		int actuallyPopulated = 0;
		while (actuallyPopulated <= populatedCells)
		{
			int xcoord = (rand() % columns) + 1;
			int ycoord = (rand() % rows) + 1;
			if ((world[xcoord][ycoord]) != 'X')
			{
				world[xcoord][ycoord] = 'X';
				actuallyPopulated += 1;
			}
		}
		for (int h = 1; h <= rows; h++)
		{
			for (int w = 1; w <= columns; w++)
			{
				if ((world[w][h]) != 'X')
				{
					world[w][h] = '-';
				}
				if (outputMode == "c");
				{
					cout << world[w][h] << '\0';
				}
				if (outputMode == "txt");
				{
					outputfile << world[w][h];
				}
			}
			if (outputMode == "c");
			{
				cout << endl;
			}
			if (outputMode == "txt");
			{
				outputfile << endl;
			}
		}
	}
	if (gameMode == 'c')
	{
		Classic classicGame;
		while (true)
		{
			char newWorld[columns][rows] = classicGame.editCells(world[], columns, rows);
			//print newWorld
			cout << "generation # " << generation << endl;
			generation += 1;
			Sleep(100);//http://www.cplusplus.com/forum/beginner/14954/
			for (int h = 1; h <= rows; h++)
			{
				for (int w = 1; w <= columns; w++)
				{
					if ((newWorld[w][h]) != 'X')
					{
						newWorld[w][h] = '-';
					}
					if (outputMode == "c");
					{
						cout << newWorld[w][h] << '\0';
					}
					if (outputMode == "txt");
					{
						outputfile << newWorld[w][h];
					}
				}
				if (outputMode == "c");
				{
					cout << endl;
				}
				if (outputMode == "txt");
				{
					outputfile << endl;
				}
			}
			//shift worlds
			if (newWorld == world || newWorld == archiveWorld)
			{ 
				repeat += 1;
			}
			if (repeat > 10)
			{
				cout << "your world is repeating or oscillating, simulation terminated" << endl;
				break;
			}
			archiveWorld = world;
			world = newWorld;
		
		}
	}
	if (gameMode == 'd')
	{
		Donut donutGame;
		while (true)
		{
			char newWorld[columns][rows] = donutGame.editCells(world[], columns, rows);
			//print newWorld
			cout << "generation # " << generation << endl;
			generation += 1;
			Sleep(100);//http://www.cplusplus.com/forum/beginner/14954/
			for (int h = 1; h <= rows; h++)
			{
				for (int w = 1; w <= columns; w++)
				{
					if ((newWorld[w][h]) != 'X')
					{
						newWorld[w][h] = '-';
					}
					if (outputMode == "c");
					{
						cout << newWorld[w][h] << '\0';
					}
					if (outputMode == "txt");
					{
						outputfile << newWorld[w][h];
					}
				}
				if (outputMode == "c");
				{
					cout << endl;
				}
				if (outputMode == "txt");
				{
					outputfile << endl;
				}
			}
			//shift worlds
			if (newWorld == world || newWorld == archiveWorld)
			{ 
				repeat += 1;
			}
			if (repeat > 10)
			{
				cout << "your world is repeating or oscillating, simulation terminated" << endl;
				break;
			}
			archiveWorld = world;
			world = newWorld;
		
		}
	}
	if (gameMode == 'm')
	{
		Mirror mirrorGame;
		while (true)
		{
			char newWorld[columns][rows] = mirrorGame.editCells(world[], columns, rows);
			//print newWorld
			cout << "generation # " << generation << endl;
			generation += 1;
			Sleep(100);//http://www.cplusplus.com/forum/beginner/14954/
			for (int h = 1; h <= rows; h++)
			{
				for (int w = 1; w <= columns; w++)
				{
					if ((newWorld[w][h]) != 'X')
					{
						newWorld[w][h] = '-';
					}
					if (outputMode == "c");
					{
						cout << newWorld[w][h] << '\0';
					}
					if (outputMode == "txt");
					{
						outputfile << newWorld[w][h];
					}
				}
				if (outputMode == "c");
				{
					cout << endl;
				}
				if (outputMode == "txt");
				{
					outputfile << endl;
				}
			}
			//shift worlds
			if (newWorld == world || newWorld == archiveWorld)
			{ 
				repeat += 1;
			}
			if (repeat > 10)
			{
				cout << "your world is repeating or oscillating, simulation terminated" << endl;
				break;
			}
			archiveWorld = world;
			world = newWorld;
		
		}
	}
}

