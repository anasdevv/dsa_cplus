#include<iostream>
#include <fstream>
#include<vector>
#include <algorithm>
using namespace std;

void stringCopy(char *s,string str,int len){
	for(int i = 0 ; i < len ; i++){
		s[i] = str[i];
	}
}
class Record;
int objectCountInFile();
class Record
{
    char name[50];
    char st_id[20];
    int age;
    int semester;
    char address[30];
   
    public:
    	int getAge(){
    		return age;
		}
    Record(string n, string id, int age, int sem, string a)
    {
    	cout << n << " len : " <<  n.length() << endl;
        stringCopy(name,n,n.length());
        stringCopy(st_id,id,id.length());
        this->age = age;
        this->semester = sem;
        stringCopy(address,a,a.length());
    }
    void setRecord(Record t){
	}
	int getSemester(){
		return semester;
	}
    Record(){};
    bool operator < (const Record &r)const{
		return age < r.age;
	}
   void writeInFile(){
   	ofstream f;
   	f.open("student.dat",ios::app);
   	if(f.fail()){
   		cout << "Can not open file " << endl;
   		return;
	   }
	   f.write((char*)this,sizeof(*this));
	   f.close();
   }
   void readFromFile(int i = 0){
   	ifstream f;
   	f.open("student.dat",ios::binary);
   	if(f.fail()){
   		cout << "Can not open file " << endl;
   		return;
	   }
	   f.seekg(i * sizeof(Record));
	   f.read((char*)this,sizeof(*this));
	   f.close();
   }
   char * getName(){
   	return name;
   }
    void display()
    {
        cout<<name<<endl<<st_id<<endl<<age<<endl<<semester<<endl<<address<<endl;
       
    }
    void displayAll(){
    	ifstream f;
    	f.open("student.dat",ios::binary);
    	Record t;
    	for(int i = 0 ; i < objectCountInFile() ; i++ ){
    		t.readFromFile(i);
    		t.display();
			}	
		}
    void sortFile(){
    	vector<Record> rcrds;
    	Record temp;
    	Record array[objectCountInFile()];
    	for(int i = 0; i < objectCountInFile() ; i++){
    		temp.readFromFile(i);
    		rcrds.push_back(temp);
		}
		sort(rcrds.begin(),rcrds.end());
		remove("student.dat");
		for(auto it = rcrds.begin() ; it!= rcrds.end() ; it++){
			it->writeInFile();
		}
	}
	int countOfStudentsInSem(int n){
		Record r;
		int count = 0;
		for(int i = 0 ; i < objrctCountInFile() ; i++){
			r.readFromFile(i);
			if(r.getSemester() == n){
				count++;
			}
		}
		return count;
	}
	void deleteStudWhoseNameStartsWithA(){
		ifstream g;
		Record r;
		g.open("temp.dat");
		for(int i = 0 ; i < objectCountInFile() ; i++){
			r.readFromFile(i);
			string str = r.getName();
			if(str[0] == 'a' || str[0] = 'A')
				continue;
			f.write((char*)&r,sizeof(Record));
		}
		g.close();
		remove("student.dat");
		rename("temp.dat","student.dat");
	}
};
/*
struct Ascending{
	inline bool operator() (const Record &record1,const Record &record2){
		return record1.age() < record2.age();
	}
};*/
int objectCountInFile(){
	ifstream f;
	f.open("student.dat",ios::binary);
	f.seekg(0,ios::end);
	return (int)f.tellg()/sizeof(Record);
	
}

int main()
{
	
	Record t("Maarij","k21-4547",19,2,"Mars");
	Record y("Maarij","k21-4547",18,2,"Mars1");
	/*Record u("Maarij","k21-4547",12,2,"Mars2");
	Record i("Maarij","k21-4547",15,2,"Mars3");
	Record o("Maarij","k21-4547",25,2,"Mars4");
         //Store 100 records in file
	t.writeInFile();
	y.writeInFile();
	y.writeInFile();
	i.writeInFile();
	o.writeInFile();
	Record *p; */
	t.writeInFile();
	y.writeInFile();
	cout << objectCountInFile() << endl;
	Record temp;
	Record temp1("Anas","123",12,2,"ABC-123");
//	temp1.writeInFile();
//	temp.readFromFile();
//	temp.display();
//	cout << temp.display() << endl;
	
	Record *p;
	p->sortFile();
	p->displayAll();

}

//Q1: Store the data in file in ascending order of age
//Q2: Display the count of student based on semester by reading from the file. For instace Semester 1: 40, Semester 2: 30 etc
//Q3: Delete the records whose name start with 'a'
//Q4: Define the function that could update the record of any student
