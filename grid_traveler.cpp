#include<iostream>
using namespace std;
int gridTraveler(int m , int n){
	if(m == 1 && n == 1) return 1;
	if(m == 0 || n == 0) return 0;
	return gridTraveler(m,n-1) + gridTraveler(n,m-1);
}
int main(){
	cout << gridTraveler(2,4);
}
