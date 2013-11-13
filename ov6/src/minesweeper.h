#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <ostream>
using std::ostream;

class Minesweeper {
private:
	int height, width, mines, open;
	int ** board,** mask;
public:
	Minesweeper();
	~Minesweeper();
	void getInput();
	void makeBoard();
	void placeMines();
	void setFlag(int row, int col);
	bool openSquare(int row, int col);
	void printBoard(bool b);
	void cleanUpMemory();
	void play();
	bool validCordinate(int row, int col);
	//ostream& operator << (ostream& out, const Minesweeper& m);

};
#endif
