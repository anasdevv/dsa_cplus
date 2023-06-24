#include <iostream>
#include <fstream>

using namespace std;

int main()
{

//steps
//open file
ifstream infile;
infile.open("File.txt");
//if file does not open, display message
if(!infile)
cerr<<"\nCan’t open File.txt\n\n";
//else(if file opens).. 
else
cout<<"\nFile opened successfully";

//display error bit values using functions
cout<<"Error State = "<<infile.rdstate();// () // 0 for no error while opening file… non zero for error
cout<<"\ngood() = "<<infile.good(); //non-zer0=true(all well), 0 = false(error)
cout<<"\nfail() = "<<infile.fail()<<"\n\n"; //0=no error(not failed), non-zero=failed(error)

//close file
infile.close();

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++ as it is not standard
return 0;
}
