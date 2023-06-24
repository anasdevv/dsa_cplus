#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string str1;
	string str2;
	string str3;
	string str4;
	ifstream infile("filee.txt");
	char str [1000];
	while(!infile.eof()){
		 infile.getline(str,1000);
		 cout << str << endl;
	}
	for(int i = 0 ; i < 500;i++)
	cout << str[i];
//	 system("pause");
	return 0;	
}
