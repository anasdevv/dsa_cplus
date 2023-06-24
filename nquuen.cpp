#include<iostream>
#define n 4
using namespace std;
/* column wise approach */
bool isSafe(int board[n][n] , int row , int col){
	int i , j;
	/* check right side */
	for(int i = 0 ; i < col ; i++){
		/* check if already a queen is placed in this col*/
		if(board[row][i] == 1){
			return false;
		}
	}
	/* check lower diagonal */
	for(i = row , j = col ; i >= 0 && j >= 0 ; i--,j--)
		if(board[i][j] == 1)
			return false;
	/* check upper diagonal */
	for(i = row , j = col ; i < 4  && j >= 0 ; i++,j--)
		if(board[i][j] == 1)
			return false;
	return true; 
}
bool isSafeRow (int board[n][n] , int row , int col){
	int i , j;
	/* check right side */
	for(int i = 0 ; i < row ; i++){
		/* check if already a queen is placed in this col*/
		if(board[i][col] == 1){
			return false;
		}
	}
	/* check lower diagonal */
	for(i = row , j = col ; i >= 0 && j >= 0 ; i--,j--)
		if(board[i][j] == 1)
			return false;
	/* check upper diagonal */
	for(i = row , j = col ; i >= 0  && j < 4 ; i--,j++)
		if(board[i][j] == 1)
			return false;
	return true; 
}
bool nqueenCol(int board[n][n],int col){
	if(col >= 4)
		return true;
	for(int i = 0 ; i < 4 ; i++){
		if(isSafe(board,i,col)){
			board[i][col] = 1;
			if(nqueenCol(board,col+1))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}
bool nqueenRow(int board[4][4],int row){
	if(row >= 4){
		return true;
	for(int i = 0 ; i < 4 ; i++){
		if(isSafeRow(board,row,i)){
			board[row][i] = 1;
			if(nqueenRow(board,row+1))
				return true;
			board[row][i] = 0;
		}
	}
	return false;	
		
	
	}
}
int main(){
	int board[4][4] = {{0}};
//	board[0][2] = 1;
	cout << nqueenRow(board,0) << endl;
	for(int i = 0 ; i < 4 ; i++){
	for(int j = 0 ; j < 4 ; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
