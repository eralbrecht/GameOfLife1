//Rose Albrecht 2300456 ealbrecht@chapman.edu GameOfLife
using namespace std;
class Donut
{
	private:
		//all the variables that we only use here
	public:
		int columns;
		int rows;
		int lineCount;
		int columnCount;
		char newWorld;
		int c;
		int r;
		char editCells(char **world, int c, int r);
		Donut();
		~Donut();
		//all the methods in donut
};