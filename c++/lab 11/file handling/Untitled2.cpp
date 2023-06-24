#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	char a = 'A';
	int b = 1;
	float f = 1.2;
	string str = "hello world";
	fstream outfile("filee.txt",ios::out | ios::app); /* outfile.open("file.txt")*/
//		cout << "Can not open file." << endl;
	outfile << "This is test string" << a << "\n" << "Integar are good: " << b << "\n" << "Floats are bad " << f <<"\n" << str << "\n" ;
	outfile.close();
	return 0;
}
