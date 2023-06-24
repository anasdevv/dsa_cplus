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

void DiskOut();// writes one record to file
void DiskIn(int);//reads one record at a time from file
static int DiskCount();// count no of students in the file
};
////////////////////////////////////////////////////////////////

void student::DiskIn(int st_no)// reads one record at a time
{
     ifstream infile;
     infile.open("STUDENT_File.dat",ios::binary);
     // takes the get pointer to the record that we are going to read
     infile.seekg(st_no*sizeof(student));
     //read the record using read statement
     infile.read( (char*)this, sizeof(*this));// reads record
}

void student::DiskOut()
{
     ofstream outfile;
     outfile.open("STUDENT_File.dat", ios::app | ios::binary); 
     outfile.write((char*)this, sizeof(*this));
}

int student::DiskCount()// to count no of students in the file
{
    ifstream infile;
    infile.open("STUDENT_File.dat", ios::binary);
    infile.seekg(0,ios::end);
    cout<<"tellg() = "<<infile.tellg()<<endl;
    //calculate no. of students and return that value= no of students in the file
    return (int)infile.tellg()/sizeof(student);
}

int main()
{
//2. Create class object and call getdata to take input
student st1; 
char ch;

//3. open file student.dat in binary mode for writing

do
{
         cout<<"\nEnter Student data\n";
         st1.getData();
         //4. Write data entered by user to the file
         st1.DiskOut(); // writing one record to the file at a time
         cout<<"Enter another Student's Record (y/n)? ";
         cin>>ch;
         cin.ignore();
         cin.get();
}
while(ch=='y');

// add DiskCount() function here that counts the no of students in the file
int n=student::DiskCount();// n contains no of students in the file
cout<<"\nThere are "<<n<<" students in the file\n";
// NOW GOING TO READ FILE & PRINT ALL RECORDS

for(int j=0;j<n;j++)// used to read all records from file one by one
{
         st1.DiskIn(j);// reading one record at a time from the file
         st1.showdata();
         cout<<"\n\n====================================\n";
}// end of for loop
      
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
