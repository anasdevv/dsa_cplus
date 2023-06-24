#include<iostream>
using namespace std;
void f(int n){
	if(n == 0) return;
	cout << n << " ";
//	n--;
	f(n--);
}
int main(){
	f(5);
}
