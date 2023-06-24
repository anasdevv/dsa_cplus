//FileH_Example 3.cpp

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

//steps


// declarations
const int MAX=80;
char buffer[MAX];
ofstream outfile;
//Create file for writing
outfile.open("StringFile.txt");

//write the following text in file
outfile<<"this is the data that my StringFile.txt contains\n";
outfile<<"this is the first line\n";
outfile<<"this is the second line of my file\n";
outfile<<"this is the third line... file ends here\n";

cout<<"data written\n";
//close file
outfile.close();

// now we are going to read the same file

// open file for reading
ifstream infile("StringFile.txt");

//until we reach to the end of file, put all data in the char variable buffer
while(infile)
{
     infile.getline(buffer, MAX);
     cout<<buffer<<endl;// printing data line by line on the output screen
     
}
//close file or optional
infile.close();

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++.
return 0;
}
