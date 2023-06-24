#include<iostream>
using namespace std;
void printMove(int disk,char from_rod,char to_rod){
	cout << "Move disk" << disk << " From rod " << from_rod << " To rod " << to_rod << endl;
}
void moveDisk(int n,char from_rod,char to_rod,char aux_rod){
	if(n == 1){
//	just move the smallest disk can be moved directly to anywhere
		printMove(1,from_rod,to_rod);
		return;
	}
//	move all-minus largest from FROM to AUX(using TO as extra)
	moveDisk(n-1,from_rod,aux_rod,to_rod);
//	move largest disk
	printMove(n,from_rod,to_rod);
//	move all-minus largest from AUX(where we left them) to TO (using FROM as extra)
	moveDisk(n-1,aux_rod,to_rod,from_rod);
}
int main(){
	
	int n = 3;
	moveDisk(n,'A','C','B');
	return 0;
}
