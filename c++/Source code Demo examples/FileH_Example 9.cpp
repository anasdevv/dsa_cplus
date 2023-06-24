#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
//steps
fstream F;
// opening a file in input and output mode (as using functions related to get and put pointer)
F.open("file1.txt", ios::in|ios::out);
cout<<"\nfile1.txt is opened"<<endl;
// getting current location of get pointer using tellg() function
cout<<"\n\ncurrent location = "<<F.tellg()<<endl;
// moving get pointer to the 8th byte/characters from beginning using seekg() function
F.seekg(8,ios::beg);
// now, getting the current location of get poiner using tellg() function
cout<<"\n\nAfter F.seekg(8,ios::beg) Now current location of get ptr=  "<<F.tellg()<<endl;    
// extracting one character from current location using get() function
char ch=F.get();  
// printing the character
cout<<"\n\nThe extracted character pointed by get pointer = "<<ch<<endl; 
// now, move the get pointer 10 more bytes/characters from the beginning using seekg function
F.seekg(10,ios::beg);   
// now, getting current location of get pointer using tellg() function
cout<<"\n\nAfter F.seekg(10,ios::beg) now current location of get ptr = "<<F.tellg()<<endl;    
// again, extracing the one character from current location using get function
ch=F.get();    
// printing the character
cout<<"\n\nExtracted character from current location  = "<<ch<<endl;       
// again, move put pointer 7 bytes/characters from beginning using seekp() function
F.seekp(7,ios::beg);    
// writting a character 'Z' at current location using put() function
F.put('Z');    
// now, moving get pointer 8 bytes/characters away from the end using seekg() funciton
F.seekg(-8,ios::end);    
// now, printing the current location of get pointer using tellg() function
cout<<"\n\ncurrent position of get ptr after F.seekg(-8,ios::end) = "<<F.tellg()<<endl;    
// extracting one character from current location using get() function
ch=F.get();    
// printing the character
cout<<"\n\nPrinting the character = "<<ch<<endl;    
// closing the file
F.close();

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++.
return 0;
}
