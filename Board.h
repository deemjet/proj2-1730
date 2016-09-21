#include <vector>
#include <iostream>
#ifndef BOARD_H
#define BOARD_H
using namespace std;


class Board {
private:
	vector<vector<char>> gBoard;
	void initBoard();
public:
	Board();
	int add(int col,char player);
	//~Board();
	void printBoard();
	bool checkWin(int col, int row);
	int findCol();
};

#endif
