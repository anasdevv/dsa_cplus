//FileH_Example 6.cpp
// writing and reading an array of integers to/from a binary file

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;

int main()
{   
//steps
//0. declare an array
int Array[MAX_SIZE];
//1. assigning values to array of integers using loop
for(int j=0;j<MAX_SIZE;j++)
Array[j]=j;
//2. open binary file BFile.dat
ofstream os("BFile.dat", ios::binary);
//3. write complete array of integers to the binary file using write function for once
os.write(reinterpret_cast<char *>(Array), MAX_SIZE*sizeof(int));
//4. close file
os.close();

//5. erase buffer or data in array
for(int j=0; j<MAX_SIZE; j++) 
Array[j] = 0;
// open file BFile.dat for reading
ifstream is("Bfile.dat",ios::binary);
//7. read complete array of integers from the binary file using read function for once
is.read(reinterpret_cast<char *>(Array),MAX_SIZE*sizeof(int));

//8. print array on output screen and also we will check for errors if they occured
for(int j=0;j<MAX_SIZE;j++)
{
        if(Array[j]!=j)// checking whether elements are same or there is some error
        {
                       cout<<"Wrong data is read from the file\n";
                       return 1;// main returns here
        }// end of if condition
cout<<"\n\nArray["<<j<<"] = "<<Array[j];
}// end of loop
cout<<"\n\n Data is correct\n";

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++ as it is not standard
return 0;
}


//steps
//0. declarations
//1. assigning values to array of integers
//2. open binary file BFile.dat
//3. write complete array of integers to the binary file using write function for once
//4. close file
//5. erase buffer
//7. read complete array of integers to the binary file using read function for once
//8. print array on output screen and also 
