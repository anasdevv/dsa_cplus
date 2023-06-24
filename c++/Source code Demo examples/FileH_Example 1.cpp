// FileH_Example 1.cpp
// writes output(formatted) to a file, using <<

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
//declarations
char ch='z';
int i=77;
float f=6.02;
string str1="Hello";
string str2 = "File";
//open file
//ofstream outfile("File.txt");
fstream outfile;
outfile.open("File.txt",ios::out|ios::in|ios::trunc);

//write data to file
outfile<<ch<<i<<' '<<f<<str1<<' '<<str2;// write all these variables to file file.txt

//close file
outfile.close();

cout<<"Data is Written to the file\n";

system("pause");
return 0;
}















/*

fstream outfile;
outfile.open("File.txt");

used for fstream.. change ofstream to fstream & use ios::out
outfile.open("File.txt",ios::out);

fstream file;
file.open("File.txt",ios::out,ios::app)

fstream file;
file.open("File.txt",ios::in)

both for reading and writing
file.open("File.txt",ios::in,ios::out);

fstream file;
file.open("File.txt",ios::out,ios::trunc);

*/
