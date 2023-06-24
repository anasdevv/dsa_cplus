#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	char a = 'A';
	int b = 1;
	float f = 1.2;
	string str = "hello world";
	ofstream outfile("file.txt");
//		cout << "Can not open file." << endl;
	outfile << "Character : " << a << "\n" << "Integar : " << b << "\n" << "Float : " << f <<"\n" << str << "\n" ;
	return 0;
}

