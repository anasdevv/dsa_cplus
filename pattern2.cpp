#include<iostream>
using namespace std;
void printPattern2(int row,int i = 0){
	if(row == 0) return;
	if(row > i){
		printPattern2(row,i+1);
		cout <<"*";
	} else { 
		printPattern2(row-1,0);
		cout <<"\n";
	} 
}
int main(){
	printPattern2(4,0);
}
