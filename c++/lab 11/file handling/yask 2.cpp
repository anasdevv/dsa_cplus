
#include<iostream>

#include<fstream>

using namespace std;

void countwords()

{

ifstream fin;

fin.open("FileData.txt");
//	cout << "Can not open file" << endl;

char word[300];

int count=0;

while(!fin.eof())

{

fin>>word;

count++;

}

cout<<"Number of words in file are "<<count<<endl;
cout << "ho";
fin.close();

}

int main()

{

countwords();

system("pause");

return 0;

}
