#include<iostream>
using namespace std;
void printPattern(int row,int i = 0){
	if(row == 0) return;
	if(row > i){
		cout <<"*";
		printPattern(row,i+1);
	}else{
	cout <<"\n";
	printPattern(row-1,0);
	}
}
int main(){
	printPattern(4,0);
}
