#include "Minesweeper.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

Minesweeper::Minesweeper() {
	getInput();
	makeBoard();
	open = 0;
}

Minesweeper::~Minesweeper() {
	for(int i = 0; i < height; i++) {
		delete [] board[i];
		delete [] mask[i];
	}
	delete [] board;
	delete [] mask;
}

void Minesweeper::getInput() {
	bool valid;
	do {
		cout << "Enter {height} {width} {mines}: ";
		cin >> height >> width >> mines;
		valid = height > 1 && width > 1 && mines > 0 && mines <= height * width;
		if(!valid) cout << endl << "Invalid input." << endl;
	} while (!valid);
}

void Minesweeper::makeBoard() {
	board = new int*[height];
	mask = new int*[height];
	for(int i = 0; i < height; i++) {
		board[i] = new int[width];
		mask[i] = new int[width];

		for(int j = 0; j < width; j++) {
			board[i][j] = 0;
			mask[i][j] = 0;
		}
	}
}

bool Minesweeper::validCordinate(int row, int col) {
	return (row < height && row >= 0 && col < width && col >= 0);
}

void Minesweeper::placeMines() {
	srand(time(0) + rand() % 49);
	int row, col;
	int placedMines = 0;

	while(placedMines < mines) {
		row = rand() % height;
		col = rand() % width;

		if(board[row][col] == -1)
			continue;

		board[row][col] = -1;
		placedMines++;

		for(int i = 0; i < 9; i++) {
			int y = (row - 1) + i / 3;
			int x = (col - 1) + i % 3;

			if(board[y][x] != -1 && validCordinate(y,x)) {
				board[y][x]++;
			}
		}
	}
}

void Minesweeper::setFlag(int row, int col) {
	if(mask[row][col] == 1 || !(validCordinate(row, col)))
		return;
	else if(mask[row][col] != 1)
		mask[row][col] = mask[row][col] == 2 ? 0 : 2;
}

bool Minesweeper::openSquare(int row, int col) {
	if(!validCordinate(row, col) || mask[row][col] > 0)
		return false;
	cout << "I did this";
	mask[row][col] = 1;
	open++;

	if (open == 1) placeMines();

	if (board[row][col] == -1)
		return true;

	if (board[row][col] == 0) {
		for(int i = 0; i < 9; i++) {
			int y = (row - 1) + i / 3;
			int x = (col - 1) + i % 3;
			cout << row << col << y << x;
			if(!(x = row && y == col)) {
				openSquare(x,y);
			}
		}
	}
	return false;
}
/**
ostream& operator << (ostream& out, Minesweeper& m) {
	out << "   ";
		for(int i = 0; i < m.width; i++) {
			out << i << " ";
		}
		for (int i = 0; i < m.height; i++) {
			out << endl << i << " |";
			for(int j = 0; j < m.width; j++) {
				if(m.mask[i][j] == 0)
					out << "#";
				if(m.mask[i][j] == 1) {
					int num = m.board[i][j];
					if(num == -1) {
						//if(b) cout << '*';
						//else out << " ";
						out << "*";
					}
					else if(num == 0) out << " ";
					else cout << m.board[i][j];
				}
				if (m.mask[i][j] == 2) out << "f";
				out << "|";
			}
			out << endl;
		}
}
**/

void Minesweeper::printBoard(bool b) {
	cout << "   ";
		for(int i = 0; i < width; i++) {
			cout << i << " ";
		}
		for (int i = 0; i < height; i++) {
			cout << endl << i << " |";
			for(int j = 0; j < width; j++) {
				if(mask[i][j] == 0)
					cout << "#";
				if(mask[i][j] == 1) {
					int num = board[i][j];
					if(num == 0) cout << " ";
					else if(num == -1) {
						if(b) cout << '*';
						else cout << " ";
					}
					else cout << board[i][j];
				}
				if (mask[i][j] == 2) cout << "f";
				cout << "|";
			}
			cout << endl;
		}
}

void Minesweeper::play() {
	cout << "Welcome to minesweeper" << endl;
	cout << "Command options are: 'o' - OPEN, 'f' - FLAG, 'q' - QUIT:" << endl;
	cout << "[command] [row] [col]" << endl;

	bool win = true;
	char command;
	int row, col;

	while(open < (height * width - mines) && win) {
		cout.clear();
		this->printBoard(false);
		cin.clear();
		cin >> command >> row >> col;
		if((command != 'o' && command != 'f' && !validCordinate(row,col)) && command != 'q'){
			cout << "Not a valid statement, try again." << endl;
			continue;
		}

		switch (command) {

		case 'o':
			if(openSquare(row,col)) {
				cout << "You hit a mine." << endl;
				win = false;
				break;
			}
			break;
		case 'f':
			setFlag(row, col);
			continue;

		case 'q':
			cout << "I quit!" << endl;
			return;
		default:
			continue;
		}
	}
	if(win) {
		cout << "Hurray, you beat the game." << endl;
	}
}


