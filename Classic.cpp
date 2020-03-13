//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
#include "Classic.h"
//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
Classic::Classic()
{
	
	//maybe have a method that would get rows and columns
	//need to allocate object
	//int columns;
	//int rows;
	//int lineCount;
	//int columnCount;
	//char newWorld;
	//all the variable that i will want to pass
}
Classic::~Classic()
{
	//nothing here
}
char** editCells(char **world, int c, int r)
{
	char newWorld[c][r];
	for (int i = 0; i < (c*r); ++i)
	{
		int nCount = 0;
		int lineCount = (i / c);
		int columnCount = i % r;
		//top row
		if (lineCount == 0)
		{
			//left
			if (columnCount == 0)
			{
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
			}
			//top mid
			if (columnCount > 0 && columnCount < c - 1)//first line -- not either top corner
			{

				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}

			}
			//top right
			if (columnCount == c - 1)
			{
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}
			}
		}
		//mid rows
		if (lineCount > 0 && lineCount < r-1)
		{
			//left edge
			if (columnCount == 0)
			{
				//count above
				if (world[lineCount -1][columnCount] == 'X')
				{
					nCount += 1;
				}
				//count diagonal right up
				if (world[lineCount -1][columnCount +1] == 'X')
				{
					nCount += 1;
				}
				//count right
				if (world[lineCount][columnCount + 1] == 'X')
				{
					nCount += 1;
				}
				//count diagonal right down
				if (world[lineCount + 1][columnCount + 1] == 'X')
				{
					nCount += 1;
				}
				//count below
				if (world[lineCount + 1][columnCount] == 'X')
				{
					nCount += 1;
				}	
			}
			//right edge
			if (columnCount == c-1)
			{

				if (world[lineCount - 1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount -1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
			}
			//mid columns
			if (columnCount > 0 && columnCount < c - 1)
			{
				if (world[lineCount -1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount + 1] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount -1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount -1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount -1][columnCount -1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
		}
		//bottom row
		if (lineCount == 0)
		{
			//left
			if (columnCount == 0)
			{
				if (world[lineCount - 1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount + 1] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
			}
			//mid
			if (columnCount > 0 && columnCount < c - 1)
			{

				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount + 1] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}

			}
			//right
			if (columnCount == c - 1)
			{
				if (world[lineCount - 1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}
			}
		}
		if (nCount < 2)
		{
			newWorld[columnCount][lineCount] = 'X';
		}
		if (nCount == 3)
		{
			newWorld[columnCount][lineCount] = 'X';
		}
		if (nCount > 3)
		{
			newWorld[columnCount][lineCount] = 'X';
		}
	}
	return (char**)newWorld;
}