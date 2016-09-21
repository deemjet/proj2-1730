#include <iostream>
#include <vector> 
#include "HumanPlayer.h"
#include <string>
using namespace std; 

HumanPlayer::HumanPlayer(){
  string n;
  cout << "Player, please enter your name: ";
  cin >> n;
  setName(n);
  cout << endl;
}

