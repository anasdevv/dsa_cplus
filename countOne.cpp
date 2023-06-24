#include<iostream>
using namespace std;
int countOne(int n){
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return countOne(n%2)+countOne(n /2);
}
int main(){
	cout << countOne(28);
}
