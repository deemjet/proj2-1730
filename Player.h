#include <vector>
#include <iostream>
#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

//class Board;
class Player {
private:
	
public:
	string getName();
	int charsPlaced=0;
	string name;
	bool checkDraw(); //check if board is full
	void setName(string n);
};

#endif
