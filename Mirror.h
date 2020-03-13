//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
using namespace std;
class Mirror
{
private:
	//all the variables that we only use here
public:
	Mirror();
	~Mirror();
	int columns;
	int rows;
	int lineCount;
	int columnCount;
	char newWorld;
	int c;
	int r;
	char editCells(char **world, int c, int r);
	//all the methods in M
};