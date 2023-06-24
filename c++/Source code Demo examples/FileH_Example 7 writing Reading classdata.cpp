// FileH_Example 7 writing Reading classdata.cpp
// saves student data(class object) to disk and later read it

#include <iostream>
#include <fstream>

using namespace std;

//1. create a student class with functions getData() & showdata() for output
class student
{
      private:
          char St_Name[80];
          short age;
              
      public:
             void getdata()// is used to take input from user
             {
                  cout<<"Enter name = ";
                  cin.getline(St_Name,80);
                  cout<<"Enter Age = ";
                  cin>>age;
             }
             void showdata()// is used to print data on output screen
             {
                  cout<<"\nName = "<<St_Name;
                  cout<<"\nAge = "<<age;
             }
             
};// end f class

int main()
{

//2. Create class object and call getdata to take input
student st1;
char ch;

//3. open file STUDENT_FILE.dat for writing in file
ofstream outfile("STUDENT_FILE.dat",ios::binary|ios::app);

do
{
cout<<"\nEnter Student data\n";
st1.getdata();// input
//4. Write data entered by user to the file using write function
outfile.write(reinterpret_cast<char *>(&st1), sizeof(student));
cout<<"Enter Another Student's Record (y/n) ?";
cin>>ch;
cin.ignore();
cin.get();

}while(ch=='y');

//5. close file
outfile.close();
//6. NOW GOING TO READ FILE & PRINT ALL RECORD
ifstream infile;
infile.open("STUDENT_FILE.dat",ios::binary);

//7. read student record
while(infile.read(reinterpret_cast<char *>(&st1),sizeof(student)))
{
//8. print record on the output screen
st1.showdata();
cout<<"\n\n===============================================";
}
//9. close file
infile.close();

system("pause");
// add system("pause"); you are using devC++, visual studio and code blocks
// do not use system("pause") in turbo C++ as it is not standard
return 0;
}

















//1. create a student class with functions getData() & showdata() for output
//2. Create class object and call getdata to take input
//3. open file student.dat for writing in file
//4. Write data entered by user to the file using write function
//5. close file
//6. NOW GOING TO READ FILE & PRINT ALL RECORDS
//7. read student record
//8. print record on the output screen
//9. close file
