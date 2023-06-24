// FileHandling_Example 8 Reading and Writing multiple records using loops.cpp

#include <fstream> //for file streams
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
//1. create a student class with function getdata() to take input
class student //class of persons
{
protected:
char St_Name[80]; //person’s name
short age; //person’s age
public:
void getData() //get person’s data
{
//cin.ignore();
cout << "Enter name: "; //cin >> St_Name;
cin.getline(St_Name,80);
cout << "Enter age: "; cin >> age;

}
void showdata()// display person's data
{
     cout<<"\nName = "<<St_Name;
     cout<<"\t\t\tAge = "<<age;     
}
};
////////////////////////////////////////////////////////////////
int main()
{
//2. Create class object and call getdata to take input
student st1; 
char ch;

//3. open file student.dat in binary mode for writing
ofstream outfile("STUDENT_File.DAT", ios::binary|ios::app);
do
{
         cout<<"\nEnter Student data\n";
         st1.getData();
         //4. Write data entered by user to the file
         outfile.write(reinterpret_cast<char *>(&st1), sizeof(student));
         cout<<"Enter another Student's Record (y/n)? ";
         cin>>ch;
         cin.ignore();
         cin.get();
}
while(ch=='y');

//5. close file
outfile.close();

// NOW GOING TO READ FILE & PRINT ALL RECORDS

ifstream infile;
infile.open("STUDENT_File.DAT",ios::binary);
infile.seekg(0,ios::beg);// move file pointer to start of file
while(infile.read(reinterpret_cast<char *> (&st1), sizeof(student)))
     {
         st1.showdata();
         cout<<"\n\n====================================\n";
     }
      //close file using file object & clear input buffers
      infile.close();
      system("pause");
return 0;
}


//1. create a student class with function getdata() to take input
//2. Create class object and call getdata to take input
//3. open file student.dat in binary mode
//4. Write data entered by user to the file
//5. close file

//changes
//add showdata to class
//use open function to open file
//take input using getdata in loop and writing on the spot
// then again go to start of file using seekg or (close file then open again)
//using loop to read all records
//close file


//1. create a student class with function getdata() to take input
//2. Create class object and call getdata to take input
//3. open file student.dat in binary mode
//4. Write data entered by user to the file
//5. close file
