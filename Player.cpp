#include <iostream>
#include "Board.h"
#include "Player.h"
#include <string>
#include <vector>
using namespace std;


bool Player::checkDraw(){
	if(charsPlaced==42){
		//cout<<"It's a draw!"<<endl;
		return true;
	}
	return false;
}

void Player::setName(string n){
	this->name=n;
}

string Player::getName(){
  return this->name;
}