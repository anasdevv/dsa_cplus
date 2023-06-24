#include<iostream>
using namespace std;
double myPow(double x, int n) {
	
        if(n == 0 || x==1) return 1;
        if(n < 0){
        	n = (unsigned int)n;
        	x = 1/x;
		}
        else if(n % 2 == 0) return myPow(x*x,n/2);
        else return (x * myPow(x*x,(n-1)/2));
}
int main(){
	cout << " \"\ " << "Anas" << endl;
	
	return 0;
}
