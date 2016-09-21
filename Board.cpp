#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Board::Board(){
	initBoard();
}

//Board::~Board(){
//gBoard.clear();
//}

void Board::initBoard(){
	vector<char> tempB;
	for(int i=0;i<6;i++)
	{tempB.push_back('_');}
	for(int i=0;i<8;i++)
	{gBoard.push_back(tempB);}
}





void Board::printBoard(){
	cout<<endl;
	for(int r=0;r<6;r++)
	{
		for(int c=0;c<8;c++)
		{
			if(c!=0)
				cout<< "|" << gBoard[c][r] << "|";
		}
		cout<<endl;
	}
}

bool Board::checkWin(int col, int row){
  if(row==-1){
    return false;
  }
  int vertical=1;
  int horizontal=1;
  int diagonal1=1;
  int diagonal2=1;
  char player=gBoard[col][row];
  
  if(col < 7){
  for(int i=col+1;gBoard[i][row]==player&&i<7;i++,vertical++);
  for(int i=col-1;gBoard[i][row]==player&&i>=0;i--,vertical++);
  if(vertical>=4)return true;
  
  for(int j=row-1;gBoard[col][j]==player&&j>=0;j--,horizontal++);
  for(int j=row+1;gBoard[col][j]==player&&j<=7;j++,horizontal++);
  if(horizontal>=4) return true;

  for(int i=col-1,j=row-1;gBoard[i][j]==player&&i>=0&&j>=0;diagonal1++,i--,j--);
  for(int i=col+1,j=row+1;gBoard[i][j]==player&&i<=6&&j<=7;diagonal1++,i++,j ++);
  if(diagonal1>=4) return true;
  
  for(int i=col-1,j=row+1;gBoard[i][j]==player&&i>=0&&j<=7;diagonal2++,i--,j++);
  for(int i=col+1,j=row-1;gBoard[i][j]==player&&i<=6&&j>=0;diagonal2++,i++,j--);
  if(diagonal2>=4) return true;
  }
  return false;
}








int Board::findCol(){
  int i;
  for(i = 1; i < 8; ++i){
	  
		if (gBoard[i][0] == '_'){
			return i;
		}
		else if(gBoard[i][0]== 'X' || gBoard[i][1]=='O'){
		  continue;
		}
  }
  return i;
}


int Board::add(int col,char player){
  for(int i = 7; i >= 0; --i){
    if(gBoard[col][i] == '_'){
      gBoard[col][i] = player;
	  cout<<"FIRST"<<endl;
      return i;
    }
  }
  cout<<"SECOND"<<endl;
  return -1; 
}
