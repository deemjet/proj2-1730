#include <iostream>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "SimpleComputerPlayer.h"
#include <vector>
using namespace std;

int main(int argc, char * argv[]){
	
	string arg1(argv[1]);
	string arg2(argv[2]);
	Player *player1;
	Player *player2;
	string name1 = "";
	string name2 = "";
	
  try {
    if(arg1 == "-h"){
      HumanPlayer p1;
	  player1=&p1;
	  name1=player1->name;
    }
    else if(arg1 == "-c"){
      SimpleComputerPlayer p1;
	  player1=&p1;
	  name1=player1->name;
    }
    if(arg2 == "-h"){
      HumanPlayer p2;
	  player2=&p2;
	  name2=player2->name;
    }
    else if(arg2 == "-c"){
      SimpleComputerPlayer p2;
	  player2=&p2;
	  name2=player2->name;
    }
  }
  catch(...){
    cout << "Only 2 command line arguments can be entered after the program name. The must be either -h or -c" << endl;
    return 0;
  }
  
  if(arg1 == "-c"){
	  name1="Zoey";
  }
  if(arg2 == "-c"){
	  name2="Zoey";
  }  
  Board board;
	board.printBoard();
	int col,row;
  for (int i = 0; i < 42; ++i){
	int j = 0;
	j = i + 2;
    j = j % 2;
	col = 0;
    if(j == 0){
      row=-1;  
		  if(arg1 == "-c"){
			  cout << "Zoey's turn, Please enter and integer between 1 and 7: ";
			  col = board.findCol();
			  cout << col << endl;
		  }else{
			  cout <<name1<< "'s turn, Please enter and integer between 1 and 7: ";
			  cin >> col;
		  }
		  cout<<endl;
		  row=board.add(col,'X');
		  if(row==-1)
		  {
			  cout<<"That choice isn't on the board.. go again."<<endl;
		  }
    
	  board.printBoard();
	  cout<<"REACH1 ROW/COL="<<row<<","<<col<<endl;
      if(board.checkWin(col, row))
	  {
		  cout<<"REACH1.5"<<endl;
		  cout<<name1<<" is our winner!"<<endl;
		  break;
	  }
	  cout<<"REACH2"<<endl;
	  if(player1->checkDraw())
	  {
		  cout<<"REACH2.5"<<endl;
		  cout<<"It's a draw!"<<endl;
		  break;
	  }
    }
    else if(j != 0){
	  row=-1;
    if(arg2 == "-c"){
			  cout <<"Zoey's turn, Please enter and integer between 1 and 7: ";
			  col=board.findCol();
			  cout << col << endl;
		  }else{
			  cout <<name2<< "'s turn, Please enter and integer between 1 and 7: ";
			  cin >> col;
		  }
		  cout<<endl;
		  row=board.add(col,'O');
		  if(row==-1)
		  {
			  cout<<"That choice isn't on the board.. go again."<<endl;
		  }
	  
	  board.printBoard();
	  cout<<"REACH1"<<endl;
      if(board.checkWin(col, row))
	  {
		  cout<<"REACH1.5"<<endl;
		  cout<<name2<<" is our winner!"<<endl;
		  break;
	  }
	  cout<<"REACH2"<<endl;
	  if(player2->checkDraw())
	  {
		  cout<<"REACH2.5"<<endl;
		  cout<<"It's a draw!"<<endl;
		  break;
	  }
    }
	player1->charsPlaced++;
  }
  return 0;
}
 
