#include<iostream>
#include<fstream>
using namespace std;
int main(){
	string x = "Hello this t3xt is 4 the 1st try 25";
	ofstream w;
	w.open("Input.txt");
	w << x;
	w.close();
}
