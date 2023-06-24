

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

//steps

//declarations
char ch;
int i;
float f;
string str1;
string str2;

//open existing file with data in it using ifstream object (File.txt)
ifstream infile("File.txt");

// Read data from file into the program variables again
infile>>ch>>i>>f>>str1>>str2;

// print those variables on the output screen
cout<<ch<<endl<<i<<endl<<f<<endl<<str1<<endl<<str2<<endl;

//close file
infile.close();

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++.
return 0;
}
