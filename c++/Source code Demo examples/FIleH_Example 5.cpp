#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

//steps
//declarations
string str = "In some ways, programming is like painting";
char ch;
//open file for writing
ofstream outfile("File5.txt");
//writing characters one by one using loop
for(int j=0;j<str.size(); j++)
outfile.put(str[j]);// put(str[0]=I,j=1...put(str[1]))

cout<<"\nFile5.txt is written successfully\n";
//close file
outfile.close();

// Now Reading from file character by character using get function

//open file for reading
ifstream infile("File5.txt");
//1) using while loop to read characters one by one from the file OR 2) rdbuff function
/*while(infile)
{
   infile.get(ch);
   cout<<ch;             
}*/
cout << infile.rdbuf();
//makes programs short & when it reaches eof().. it returns automatically

cout<<"\n";
//close file
infile.close();


system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++ as it is not standard
return 0;
}
