#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string str;
	ifstream infile("FileData.txt");
//	infile.open("FileData.txt");
	if(!infile){
		cerr << "Can not open file" << endl;
		return 0;
	}
	cout << infile.rdbuf();
	cout << "hi";
}
