//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
#include <iostream>
using namespace std;
//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
#include "Donut.h"
//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
Donut::Donut()
{
	//maybe have a method that would get rows and columns
	//need to allocate object
	int columns;
	int rows;
	int lineCount;
	int columnCount;
	char newWorld;
	//all the variable that i will want to pass
}
Donut::~Donut()
{
	//nothing here
}
char editCells(char world[], int c, int r)
{
	char newWorld[c][r];
	for (int i = 0; i < (c*r); ++i)
	{
		int nCount = 0;
		lineCount = (i / c);
		columnCount = i % r;
		//top row
		if (lineCount == 0)
		{
			//left corner
			if (columnCount == 0)
			{
				if (world[r-1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[r-1][columnCount + 1] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount + 1] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][c-1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][c-1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[r-1][c-1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
			//top mid
			if (columnCount > 0 && columnCount < c - 1)//first line -- not either top corner
			{
				if (world[r-1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[r-1][columnCount + 1] == 'X')//count diagonal right up
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
				if (world[lineCount + 1][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[r-1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}

			}
			//top right
			if (columnCount == c - 1)
			{
				if (world[r-1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[r-1][0] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][0] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount + 1][0] == 'X')//count diagonal right down
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
				if (world[r-1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
		}
		//mid rows
		if (lineCount > 0 && lineCount < r - 1)
		{
			//left edge
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
				if (world[lineCount + 1][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[lineCount + 1][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[lineCount + 1][c-1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][c-1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount - 1][c-1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
			//right edge
			if (columnCount == c - 1)
			{

				if (world[lineCount - 1][columnCount] == 'X')//count above
				{
					nCount += 1;
				}
				if (world[lineCount - 1][0] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][0] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[lineCount + 1][0] == 'X')//count diagonal right down
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
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
			//mid columns
			if (columnCount > 0 && columnCount < c - 1)
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
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
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
				if (world[0][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[0][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[0][c-1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][c-1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount - 1][c-1] == 'X')//count diagonal left up
				{
					nCount += 1;
				}
			}
			//mid
			if (columnCount > 0 && columnCount < c - 1)
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
				if (world[0][columnCount + 1] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[0][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[0][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
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
				if (world[lineCount - 1][0] == 'X')//count diagonal right up
				{
					nCount += 1;
				}
				if (world[lineCount][0] == 'X')//count right
				{
					nCount += 1;
				}
				if (world[0][0] == 'X')//count diagonal right down
				{
					nCount += 1;
				}
				if (world[0][columnCount] == 'X')//count below
				{
					nCount += 1;
				}
				if (world[0][columnCount - 1] == 'X')//count diagonal left down
				{
					nCount += 1;
				}
				if (world[lineCount][columnCount - 1] == 'X')//count left
				{
					nCount += 1;
				}
				if (world[lineCount - 1][columnCount - 1] == 'X')//count diagonal left up
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
	return newWorld[];
}
