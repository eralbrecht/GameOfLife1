//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
//#include "GameOfLife1.cpp"
#ifndef CLASSIC_H
#define CLASSIC_H
using namespace std;
class Classic
{
private:
	

	//all the variables that we only use here
public:
	Classic();
	~Classic();
	int columns;
	int rows;
	int lineCount;
	int columnCount;
	char newWorld;
	int c;
	int r;
	char editCells(char **world, int c, int r);
	//all the methods in C
}; 
#endif