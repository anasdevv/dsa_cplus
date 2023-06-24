#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string str = "My name is anas";
	ofstream outfile("file4.txt");
	for(int i = 0; i < str.length() ; i++)
		outfile.put(str[i]);
	outfile.close();
	string strr ="";
	char c;
	ifstream infile("file4.txt");
	cout << infile.rdbuf();
	//while(infile){
	//	infile.get(c);
	//	strr += c;
//	}
//	cout << "\n" << str << endl;
}
