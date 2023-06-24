#include<iostream>
#include<fstream>
#define n 3
using namespace std;
int visited[n][n] = {{0}};
int calc(int board[n][n] ,int i , int j,int arr[],int &k){
	if( i == n - 1 && j == n - 1)
		return board[i][j];
	if(i >= n || j >= n) 
		return 0;
	if(!visited[i][j]){
	visited[i][j] = 1;
	int sum = calc(board,i+1,j,arr,k) + calc(board,i,j+1,arr,k);
	arr[k++] = sum;
	return sum;
	}
//	visited[i][j] = 0;
}
int main(){
	int board[n][n];
	ifstream f("input.txt");
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j++)
			f >> board[i][j];
	}
	int arr[10] = {0};
	int k = 0;
	cout << calc(board,0,0,arr,k);
	cout << endl;
	for(int i = 0 ; i < k ; i++){
		cout << arr[i] << " ";
	}
//	for(int i = 0 ; i < n ; i ++){
//		for(int j = 0 ; j < n ; j++)
//			cout <<  board[i][j] << " ";
//		cout << endl;	
//	}
}
