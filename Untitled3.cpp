#include<iostream>
#include<fstream>
using namespace std;
bool isSafe(int row,int col,int n , bool arr[10][10] , int sIndex , int sLen){
	if((row >= 0 && row < n) && (col >= 0 && col < n)  && sIndex < sLen)
		return true;
	return false;
}
void solve(char board[10][10] , int r,int c,int n,string str,int strIndex,int strLen,bool visited[10][10]){
	if(r == n - 1 && c == n - 1)
		return;
	if(board[r][c] != str[strIndex])
		return;

	visited[r][c] = 1;
	if(isSafe(r+1,c,10,visited,strIndex+1,strLen)){
		solve(board,r+1,c,n,str,strIndex+1,strLen,visited);
	}
	if(isSafe(r,c+1,10,visited,strIndex+1,strLen)){
		solve(board,r,c+1,n,str,strIndex+1,strLen,visited);
	}
	if(isSafe(r,c-1,10,visited,strIndex+1,strLen)){
		solve(board,r,c-1,n,str,strIndex+1,strLen,visited);
	}
		if(isSafe(r+1,c+1,10,visited,strIndex+1,strLen)){
		solve(board,r+1,c+1,n,str,strIndex+1,strLen,visited);
	}
		if(isSafe(r-1,c,10,visited,strIndex+1,strLen)){
		solve(board,r-1,c,n,str,strIndex+1,strLen,visited);
	}
	return;
	
}
int main(){
	char board[10][10]={
							{'M','V','D','V','F','G','C','V','M','N'},
							{'P','R','O','P','E','R','V','B','S','P'},
							{'P','M','L','T','X','I','R','H','I','R'},
							{'R','L','T','H','T','F','L','R','E','O'},
							{'L','L','M','G','G','E','R','P','O','R'},
							{'X','C','U','G','F','C','M','O','P','E'},
							{'B','K','Y','J','A','W','J','L','O','R'},
							{'X','B','D','N','A','J','B','H','Y','I'},
							{'T','C','J','O','O','C','K','A','X','L'},
							{'P','R','O','E','X','S','P','Y','C','O'}
							};
	string p = "PROPER";
	int len = 6;
	int ans[10][10] = {{0}};
	int strIndex = 0;
	bool vis[10][10] = {{false}};
	int row = 0 , col = 0 ,k = 0;
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if(board[i][j] == p[k]){
				solve(board,i,j,10,p,k,len,vis);
			}
		}
		cout << endl;
	}

	 cout << endl;
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			cout << vis[i][j] << " ";
		}
		cout << endl;
	}
}	
