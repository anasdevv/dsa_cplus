#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<windows.h>
#include <unistd.h>
#include<ctime>
using namespace std;
const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int strForPwdLength = sizeof(alphanum)-1;
int main();
void gotoxy (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }
void stringCopy(char *a,string str,int n){
	for(int i = 0 ; i < n ; i++){
		a[i] = str[i];
	}
	a[n] = '\0';
}
string toLower(string s){
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] >= 65 && s[i] < 97)
			s[i] += 32;
	}
	return s;
}
string removeSpace(string s){
	string str = "";
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == ' '){
			continue;
		}
		str += s[i];
	}
	return str;
}
int facultyCount();
int totalStudents();
class floats{
	public:
	float totMarks;
	float marksObt;
	bool marksFlag;
	float weightageObt;
	float totalWeightage;
	floats();
};

class Marks{
		public:
		floats sessionals[2];
		floats assignments[3];
		floats quizes[3];
		floats final;
		double total;
		void setSessionalObtMarks(float marks , int n);
		void setSessionalTotMarks(float marks , int n);
		float getSessionalObtMarks(int n);
		float getAssignmentObtMarks(int n);
		void setAssignmentObtMarks(float marks,int n);
		void setAssignmentTotMarks(float marks,int n);
		float getQuizObtMarks(int n);
		void setQuizObtMarks(float marks,int n);
		void setQuizTotMarks(float marks,int n);
		void setFinalTotMarks(float marks);
		void setFinalObtMarks(float marks);
		Marks();
		double getTotalMarks(){
			double a;
		for(int i = 0 ; i < 2 ; i++)
			a += sessionals[i].weightageObt; 
		for(int i = 0 ; i < 3 ; i++){
			a += assignments[i].weightageObt;
			a += quizes[i].weightageObt;
		}
		a += final.weightageObt;
		total = a;
		return a;
	}
};
class Course{
	protected:
		char courseName[100];
		double creditHours;
		char courseCode[30];
		char courseInstructor[30];
		double gpa;
		int attendance[48];
		public:
			static int attendanceCounter;
			void markAttendancePresent(){
				attendance[attendanceCounter] = 1;
				attendanceCounter++;
			}
			void markAttendanceAbsent(){
				attendance[attendanceCounter] = 5;
				attendanceCounter++;
			}
		double viewAttendancePercent(){
				int present = 0, tot = 0;
				for(int i = 0 ; i < 48 ; i++){
					if(attendance[48] == 1)
						present++;
					if(attendance[48] == 5)
						tot++;
				}
				return ((present / attendanceCounter ) * 100);
			}
			double getCreditHours(){
				return creditHours;
			}
			char *getInstructorName(){
				return courseInstructor;
			}
			char *getCourseCode(){
				return courseCode;
			}
			char *getCourseName(){
				return courseName;
			}
			char *getInstuctorName(){
				return courseInstructor;
			}
			char grade;
			float gg;
			Course(){
			gg = 0.00;
			for(int i = 0 ; i < 48 ;i++)
				attendance[i] = 0;
			};
			void setGpa(){
				gpa = marks.total;
			}
			Marks marks;
			Course(string courseName,double creditHours,string courseCode,string instructor);
			void virtual courseDisplay();
			void updateGpa(char);
			float getGpa();
			void updateGrade();
			float getTotalMarks(){
				return gg;
			}
	void virtual writeInFile(){
		ofstream f;
		f.open("courses.txt",ios::app);
		f.write((char*)this,sizeof(*this));
	}
	void virtual readFromFile(int i = 0){
		ifstream f;
		f.open("courses.txt");
		f.seekg(i * sizeof(Course));
		f.read((char *)this,sizeof(*this));
	}
	void courseMarksDisplay(){
		cout << "Total Marks\tTotal Weightage\tMarks Obtained\tWeightage Obtained" << endl;
		cout << "Sessional Marks : " << endl;
		for(int i = 0 ; i < 2 ; i++){
			cout <<  marks.sessionals[i].totMarks << "\t\t" << marks.sessionals[i].totalWeightage << "\t\t" << marks.sessionals[i].marksObt << "\t\t" << marks.sessionals[i].weightageObt << endl;
		}
		cout << "Assignment Marks : " << endl;
		for(int i = 0 ; i < 3 ; i++){
			cout << marks.assignments[i].totMarks << "\t\t" << marks.assignments[i].totalWeightage << "\t\t" << marks.assignments[i].marksObt << "\t\t" << marks.assignments[i].weightageObt << endl;
		}
		cout << "Quiz Marks : " << endl;
		for(int i = 0 ; i < 3 ; i++){
			cout << marks.quizes[i].totMarks << "\t\t" << marks.quizes[i].totalWeightage << "\t\t" << marks.quizes[i].marksObt << "\t\t" << marks.quizes[i].weightageObt << endl;	
		}
		cout << "Final Marks : " << endl;		
		cout << marks.final.totMarks << "\t\t" << marks.final.totalWeightage << "\t\t" << marks.final.marksObt << "\t\t" << marks.final.weightageObt << endl;	
		cout << "Total : " << getTotalMarks() << endl;
	}
};
class LabMarks{
	public:
		floats labs[13];
		floats mid;
		floats project;
		floats final;
		public:
			LabMarks(){
				for(int i = 0 ; i < 13 ; i++){
					labs[i].marksObt = labs[i].totalWeightage = labs[i].totMarks = labs[i].weightageObt = 0;
				}
				mid.marksObt = mid.totalWeightage = mid.totalWeightage = mid.totMarks = mid.weightageObt = 0;
				project.marksObt = project.totalWeightage = project.totalWeightage = project.totMarks = project.weightageObt = 0;
				final.marksObt = final.totalWeightage = final.totalWeightage = final.totMarks = final.weightageObt = 0;
			}
			void setLabObtainedMarks(float marks,int n){
				n--;
				labs[n].marksObt = marks;
				labs[n].marksFlag = 1;
			float a = ((labs[n].marksObt / labs[n].totMarks) * labs[n].totalWeightage);
			 labs[n].weightageObt = a;
			}
		void setLabTotMaks(float marks,int n){
			n--;
			labs[n].totMarks = marks;
		}
		void setLabMidExamMarksObt(float marks){
				mid.marksObt = marks;
				mid.marksFlag = 1;
			float a = ((mid.marksObt / mid.totMarks) * mid.totalWeightage);
			 mid.weightageObt = a;
			}
		void setLabMidExamMarksTot(float marks){
				mid.totMarks = marks;
		}
		void setFinalMarksObt(float marks){
			final.marksObt = marks;
			float a = ((final.marksObt / final.totMarks) * final.totalWeightage);
			final.weightageObt = a;
			final.marksFlag = 1;
		}
		void setFinalMarksTot(float marks){
			final.totMarks = marks;
		}
		void setProjectMarksTot(float marks){
			project.totMarks = marks;
		}
		void setProjectMarksObt(float marks){
			project.marksObt = marks;
			float a = ((project.marksObt / project.totMarks) * project.totalWeightage);
			 project.weightageObt = a;
			 project.marksFlag = 1;
		}
			
};
class Lab : virtual public Course
{
	LabMarks Marks;
	public:
		Lab(){};
		Lab(string courseName,double creditHours,string courseCode,string instructor):
			Course(courseName,creditHours,courseCode,instructor){};
		void UpdateTotalMarks(){
			for(int i = 0 ; i < 13 ;i++)
				if(Marks.labs[i].marksFlag){
					gg += Marks.labs[i].weightageObt;
					Marks.labs[i].marksFlag = 0;
				}
			if(Marks.mid.marksFlag){
				gg += Marks.mid.weightageObt;
				Marks.mid.marksFlag = 0;
			}
			if(Marks.final.marksFlag){
				gg += Marks.final.weightageObt;
				Marks.final.marksFlag = 0;
			}
			if(Marks.project.marksFlag){
				Marks.project.marksFlag = 0;
				gg += Marks.project.weightageObt;
			}

		}
	void labMarksDisplay(){
		cout << "Total Marks\tTotal Weightage\tMarks Obtained\tWeightage Obtained" << endl;
		cout << "Lab Marks : " << endl;
		for(int i = 0 ; i < 13 ; i++){
			cout <<Marks.labs[i].totMarks << "\t\t" <<Marks.labs[i].totalWeightage << "\t\t" <<Marks.labs[i].marksObt << "\t\t" << Marks.labs[i].weightageObt << endl;
		}
		cout << "Mid Makrs : " << endl;
		cout << Marks.mid.totMarks << "\t\t" << Marks.mid.totalWeightage << "\t\t" << Marks.mid.marksObt << "\t\t" << Marks.mid.weightageObt << endl;
		cout << "Project: " << endl;
		cout << Marks.project.totMarks << "\t\t" << Marks.project.totalWeightage << "\t\t" << Marks.project.marksObt << "\t\t" << Marks.project.weightageObt << endl;	
		cout << "Final Marks : " << endl;		
		cout << Marks.final.totMarks << "\t\t" << Marks.final.totalWeightage << "\t\t" << Marks.final.marksObt << "\t\t" << Marks.final.weightageObt << endl;	
		cout << "Total : " << getTotalMarks() << endl;
	}
	void virtual writeInFile(){
		ofstream f;
		f.open("courses.txt",ios::app);
		f.write((char*)this,sizeof(*this));
	}
	void virtual readFromFile(int i = 0){
		ifstream f;
		f.open("courses.txt");
		f.seekg(i * sizeof(Course));
		f.read((char *)this,sizeof(*this));
	}
};
int totalCoursesRegistered(){
	ifstream f;
	f.open("Courses.txt");
	f.seekg(0,ios::end);
	return f.tellg() / sizeof(Course);
}
class Employee{
	protected:
	char name[50];
	char address[30];
	char cnic[30];
	char phoneNo[30];
	char salary;
	bool warningFlag;
	public:
		Employee(string name,string address,string cnic,string phoneNo);
		void virtual display();
		static int totEmps;
		void setWarningFlag(bool);
		bool getWarningFlag();
		void setSalary(double);
		double getSalary();
		Employee(){};
		char * getEmpName(){
			return name;
		}
		void virtual writeInFile() = 0;
		void virtual readFromFile(int) = 0;
};
class Student
{
	char stName[35];
	char stPersonalEmail[15];
	char stID[11];
	char stUniEmail[11];
	int semester;
	double cgpa;
	bool stWarning;
	char stPwd[10];
	char phnNo[15];
	public:
	vector <Course> courses;
	vector <Lab> labs;
	static int StId;
	void setGpa(){
		float a;
		float p;
		float s,c;
		for(auto it = courses.begin() ; it != courses.end() ;it++){
			a = it->getCreditHours();
			p = it->marks.getTotalMarks();
			s = p * a;
			c += a;
		}
		for(auto it = labs.begin() ; it != labs.end() ;it++){
			a = it->getCreditHours();
			p = it->marks.getTotalMarks();
			s = p * a;
			c += a; 
		}
		cgpa = s /  c;
	}
	Student(string name,string pEmail,string phn,int n){
		stringCopy(phnNo,phn,phn.length());
		int nn = 6;
    	srand(time(0));	 
 		stringCopy(stName,name,name.length());
		stringCopy(stPersonalEmail,pEmail,pEmail.length());
		this->semester = n;
		cgpa = 0;
		stWarning = false;
		string str = getStudName();
		str = removeSpace(str);
		string ss;
		ss.push_back(tolower(stName[0]));
		ss.push_back(tolower(stName[1]));
		string id = "s-k-" + ss + to_string(StId);
		string s = toLower(str) + to_string(StId) + "@nu.edu.pk";
		stringCopy(stID,id,id.length());
		stringCopy(stUniEmail,s,s.length()); 
		for(int i = 0; i < nn; i++)
 		 	stPwd[i] = alphanum[rand() % strForPwdLength];
		stPwd[nn] = '\n';
	}
	void completeStudDisplay(){
		cout << "Name : " << stName << endl;
		cout << "Phone Number : " << phnNo << endl;
		cout << "ID : " << stID << endl;
		cout << "Password : " << stPwd << endl;
		cout << "Personal Email : " << stPersonalEmail << endl;
		cout << "University Email : " << stUniEmail << endl;
		cout << "Semester : " << semester << endl;
		cout << "GPA : " << cgpa << endl;
	}
	void courseMarksDisplay(string courseCode){
		bool flag = true;
		for(auto it = courses.begin() ; it != courses.end() ; it++){
			if(it->getCourseCode() == courseCode){
				system("cls");
				cout << "Record Found : !!\n\n" << endl; 
				it->courseMarksDisplay();
				flag = false;
			}
		}
		if(flag){
			cout << "Course Not Found" << endl;
		}
	}
	char * getStudentPwd(){
		return stPwd;
	}
	void getStudentIDPWd(){
		cout << "Student ID : " << getStudId() << endl;
		cout << "Password : " << getStudentPwd() << endl;
	}
	void assignCourseToStud(Course s){
		courses.push_back(s);
	}
	void writeInFile(){
		ofstream f;
		f.open("Student.txt");
		f.write((char*)this,sizeof(*this));
	}
	void readFromFile(int i = 0){
		ifstream f;
		f.open("Student.txt");
		Student t;
		f.seekg(i * sizeof(Student));
		f.read((char *)this,sizeof(*this));
	}
	char *getStudName(){
		return stName;
	}
	char *getStudId(){
		return stID;
	}
	Student(){};
	void studBasicDisplay(){
		cout << "Name : " << stName << endl;
		cout << "ID : " << stID << endl;
		cout << "Email : " << stUniEmail << endl; 
	}
};
void studRegCourse(Student S){
	char ch;
	cout << "Do You Want To register Course Now ? ( press 0   for no )" << endl;
	cin >> ch;
	if(ch == '0')
		return;
	while(1){
		string courseName , courseCode, instructor;
		double creditHours;
	/*	string courseName,double creditHours,string courseCode,string instructor */
	cout << "Enter Course Name : ";
	cin >> courseName;
	cout << "Enter Course Code : ";
	cin >> courseCode;
	cout << "Enter Credit Hours ";
	cin >> creditHours;
	cout << "Enter Instructor Name : ";
	cin >> instructor;
	Course c(courseName, creditHours, courseCode, instructor);
	S.courses.push_back(c);
	cout << "Do you want to add another course  ( press 0   for no ) ";
	cin >> ch;
		if(ch == '0')
		return;
	}
}
int totalStudents(){
	ifstream f;
	f.open("Student.txt");
	if(f.fail())
		return 0;
	f.seekg(0,ios::end);
	return (int)f.tellg() / sizeof(Student);
}
int Student::StId = 10;
void editQuizTotMarks(Course &c)
{
	int n;
	float f;
	cout<<"ENTER 1 TO EDIT QUIZ 1 TOTALMARKS"<<endl;
	cout<<"ENTER 2 TO EDIT QUIZ 2 TOTAL MARKS"<<endl;
	cout<<"ENTER 3 TO EDIT QUIZ 3 TOTAL MARKS"<<endl;
	cin >> n;
	n--;
	if(n >= 0 && n <= 2 ){
	cout << "Enter marks : ";
	cin >> f;
	c.marks.quizes[n].totMarks  = f;
	return;
	}

}
void updateStudentRecord(string id){
	ifstream f;
	ofstream g;
	f.open("Student.txt");
	g.open("temp.txt");
	Student ff;
	for(int i = 0; i < totalStudents(); i++){
		ff.readFromFile(i);
		if(ff.getStudId() == id)
			continue;
		g.write((char*)&ff,sizeof(Student));
	}
	remove("Student.txt");
	rename("temp.txt","Student.txt");
	ff.writeInFile();
}
void editQuizObtMarks(Course &c){
	int n;
	cout<<"ENTER 1 TO EDIT QUIZ 1 OBTAINED MARKS"<<endl;
	cout<<"ENTER 2 TO EDIT QUIZ 2 OBTAINED MARKS"<<endl;
	cout<<"ENTER 3 TO EDIT QUIZ 3 OBTAINED MARKS"<<endl;
	cin >> n;
	n--;
	float f;
	cout << "Enter Marks : ";
	cin >> f;
	c.marks.setQuizObtMarks(f,n);
	c.updateGpa('q');
}
void editAssignmentTotMarks(Course &c)
{	
	int n;
	cout<<"ENTER 1 TO EDIT ASSIGNMENT 1 TOTAL MARKS"<<endl;
	cout<<"ENTER 2 TO EDIT ASSIGNMENT 2 TOTAL MARKS"<<endl;
	cout<<"ENTER 3 TO EDIT ASSIGNMENT 3 TOTAL MARKS"<<endl;
	cin >> n;
	cout << "Enter Marks : ";
	float f;
	cin >> f;
	n--;
	if(n >= 0 && n <= 2)
	   c.marks.setAssignmentTotMarks(f,n);
}
void editAssignmentObtMarks(Course &c)
{	
	int n;
	float f;
	cout<<"ENTER 1 TO EDIT ASSIGNMENT 1 TOTAL MARKS"<<endl;
	cout<<"ENTER 2 TO EDIT ASSIGNMENT 2 TOTAL MARKS"<<endl;
	cout<<"ENTER 3 TO EDIT ASSIGNMENT 3 TOTAL MARKS"<<endl;
	cin >> n;
	cout << "Enter Marks : ";
	cin >> f;
	n--;
	if(n >= 0 && n <= 2)
	   c.marks.setAssignmentTotMarks(f,n);
	   c.updateGpa('a');
}
void editSessionalTotMarks(Course &c)
{	
	int n;
	cout<<"ENTER 1 TO EDIT SESSIONAL 1 TOTAL MARKS"<<endl;
	cout<<"ENTER 2 TO EDIT SESSIONAL 2 TOTAL MARKS"<<endl;
	cin >> n;
	cout << "Enter Marks : ";
	float f;
	cin >> f;
	n--;
	if(n >= 0 && n <= 1)
	   c.marks.setSessionalTotMarks(f,n);
}
void editSessionalObtMarks(Course &c)
{	
	int n;
	cout<<"ENTER 1 TO EDIT SESSIONAL 1 TOTAL MARKS"<<endl;
	cout<<"ENTER 2 TO EDIT SESSIONAL 2 TOTAL MARKS"<<endl;
	cin >> n;
	cout << "Enter Marks : ";
	float f;
	cin >> f;
	n--;
	if(n >= 0 && n <= 1)
	   c.marks.setSessionalObtMarks(f,n);
	   c.updateGpa('s');
}

void editFinalTotMarks(Course &c)
{
	float f;
	cout << "Enter Marks :";
	cin >> f;
	c.marks.setFinalTotMarks(f);
}
void editFinalObtMarks(Course &c)
{
	float f;
	cout << "Enter Marks :";
	cin >> f;
	c.marks.setFinalObtMarks(f);
	c.updateGpa('f');
}	

class Faculty : public Employee{
	protected:
		char pwd[10];
		char empType[50];
		char department[50];
		char position[50];
		char ID[50];
		char positon[50];
		int noOfCoursesAlot;
		int semeseterAlot;
		char section[20];
		char email[20];
		public:
			Faculty(){};
			Faculty(string name,string address,string cnic,string phoneNo,string department,string position,string sectionn,int s);
			vector <Course> assignedCourses;
			vector <Lab> assignedLabs;
			void viewAssignedCourses();
			void assignCourse(Course c);
			static int forId;
			static int forEmail;
			void display(){
				Employee::display();
				cout << "Department : " << department << endl;
				cout << "ID : " << ID << endl;
				cout << "Password : " << pwd << endl;
				cout << "Email : " << email << endl;
			}
			void writeInFile(){
				ofstream f;
				f.open("Faculty.txt");
				if(f.fail()){
   				   cout << "Can not open file " << endl;
   				   return;
	   			}
				f.write((char*)this,sizeof(*this));
				f.close();
			}
			char * getFacultyPwd(){
				return pwd;
			}
			void readFromFile(int i){
				ifstream f;
				f.open("Faculty.txt");
				if(f.fail()){
   				   cout << "Can not open file " << endl;
   				   return;
	   			}
				f.seekg(i * sizeof(Faculty));
				f.read((char *)this,sizeof(*this));
				f.close();
			}
			void viewTotStudents(){
				ifstream f;
				Student s;
				for(int i = 0 ; i < totalStudents() ; i++){
					s.readFromFile(i);
					for(auto it = s.courses.begin() ; it != s.courses.end() ; it++){
						if(it->getInstructorName() == this->getEmpName()){
							break;
						}
						s.studBasicDisplay();
						cout <<"\n\n";
					}
				}
			}
			char * getFacultyId(){
				return ID;
			}
		void markAttendanceOfAllStuds(string str){
			Student s;
			char ch;
			for(int i = 0 ; i < totalStudents(); i++){
				s.readFromFile(i);
				getchar;
				for(auto it = s.courses.begin() ; it != s.courses.end() ; it++){
					if(it->getCourseCode() == str){
						cout << s.getStudName() << " " << s.getStudId() << endl;
						cout << "Press 1 to mark present and 0 for absent : ";
						cin >> ch;
						if(ch == '1')
							it->markAttendancePresent();
						else
							it->markAttendanceAbsent();
					} 
				}
			}
		}
		void updateStudMarks(string id,string code){
			Student s;
			int n;
			for(int i = 0 ; i < totalStudents(); i++){
				s.readFromFile(i);
				if(s.getStudId() == id){
					for(auto it = s.courses.begin() ; it != s.courses.end() ; it++){
						if(it->getCourseCode() == code){
							cout << "1. Edit Quiz Marks " << endl;
							cout << "2. Edit Assignemnt Marks " << endl;
							cout << "3. Edit Sessional " << endl;
							cout << "4. Edit Final " << endl;
							cin >> n;
							if(n == 1)
								editQuizObtMarks(*it);
							if(n == 2)
								editAssignmentObtMarks(*it);
							if(n == 3)
								editSessionalObtMarks(*it);
							if(n == 4)
								editFinalObtMarks(*it);
						}
					}
				}
				
			}
			
		}
		void setAssignmentTotMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editAssignmentTotMarks(*it);
				}
			}
		}
		void setQuizTotMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editQuizTotMarks(*it);
				}
			}
		}
		void setSessionalTotMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editSessionalTotMarks(*it);
				}
			}
		}
		void setFinalTotMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editFinalTotMarks(*it);
				}
			}
		}
		void setAssignmentObtMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editAssignmentObtMarks(*it);
				}
			}
		}
		void setQuizObtMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editQuizObtMarks(*it);
				}
			}
		}
		void setSessionalObtMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editSessionalObtMarks(*it);
				}
			}
		}
		void setFinalObtMarksForAllStud(){
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
					if(it->getInstructorName() == getEmpName())
					editFinalObtMarks(*it);
				}
			}
		}
};
int facultyCount(){
	ifstream f;
	f.open("Faculty.txt");
	f.seekg(0,ios::end);
	return (int)f.tellg() / sizeof(Faculty);
}
Faculty::Faculty(string namee,string addresss,string cnicc,string phoneNoo,string departmentt,string positionn,string sectionn,int s):
	Employee(namee,address,cnicc,phoneNoo)
{
	stringCopy(section,sectionn,sectionn.length());
	stringCopy(department,departmentt,departmentt.length());
	stringCopy(this->position, positionn,positionn.length());
	forId++;
	string Email;	
	string str = getEmpName();
	str = removeSpace(str);
	string ss;
	ss.push_back(tolower(namee[0]));
	ss.push_back(tolower(namee[1]));
	string id = "f-k-" + ss + to_string(forId);
	Email = toLower(removeSpace(namee)) + to_string(forId) + "@nu.edu.pk";
	stringCopy(email,Email,Email.length());
	stringCopy(ID,id,id.length());
	this->semeseterAlot = s;
	int nn = 6;
    srand(time(0));
    	for(int i = 0; i < nn; i++)
 		 	pwd[i] = alphanum[rand() % strForPwdLength];
		pwd[nn] = '\n';
}
int totalAdm();
class Administration : public Employee
{
	char id[20];
	char admPwd[10];
	char email[20];
	public:
		static int forID;
		Administration(){};
		Administration(string namee,string addresss,string cnicc,string phoneNoo):
		Employee(namee,address,cnicc,phoneNoo){
		forID++;
		string Email;	
		string str = getEmpName();
		str = removeSpace(str);
		string ss;
		ss.push_back(tolower(namee[0]));
		ss.push_back(tolower(namee[1]));
		string ID = "adm-k-" + ss + to_string(forID);
		Email = toLower(removeSpace(namee)) + to_string(forID) + "@nu.edu.pk";
		stringCopy(email,Email,Email.length());
		stringCopy(id,ID,ID.length());
    	srand(time(0));
    	int n = 6;
    	for(int i = 0; i < n; i++)
 			 admPwd[i] = alphanum[rand() % strForPwdLength];
		admPwd[n] = '\n';
		}
		Administration createAdministrator(){
		string name ,address, cnic, phoneNo;
		int n, s;
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter Address : ";
		cin >> address;
		cout << "Enter CNIC : ";
		cin >> cnic;
		cout << "Phone Number : ";
		cin >> phoneNo;
		Administration a(name,address , cnic , phoneNo);
		return a;
		}
		void removeAdm(string id){
			bool flag = true;
			ofstream f;
			Administration s;
			f.open("temp.txt");
			for(int i = 0 ; i < totalAdm() ; i++){
				s.readFromFile(i);
				if(s.getAdmId() == id)	{
					flag = false;
					continue;
				}

				f.write((char*)&s,sizeof(Student));	
			}
			if(flag){
				cout << "Not Found !" << endl;
				return;
			}
			f.close();
			remove("Adm.txt");
			rename("temp.txt","Adm.txt");
		}
		void removeStudent(string id){
			bool flag = true;
			ofstream f;
			Student s;
			f.open("temp.txt");
			for(int i = 0 ; i < totalStudents() ; i++){
				s.readFromFile(i);
				if(s.getStudId() == id)	{
					flag = false;
					continue;
				}

				f.write((char*)&s,sizeof(Student));	
			}
			if(flag){
				cout << "Student Not Found !" << endl;
				return;
			}
			f.close();
			remove("Student.txt");
			rename("temp.txt","Student.txt");
		}
		void removeFaculty(string id){
			bool flag = true;
			Faculty s;
			ofstream f;
			f.open("temp.txt");
			for(int i = 0 ; i < facultyCount() ; i++){
				s.readFromFile(i);
				if(s.getFacultyId() == id){
					flag = false;
					continue;
				}
				f.write((char*)&s,sizeof(Student));	
			}
			if(flag){
				cout << "Student Not Found !" << endl;
				return;
			}
			f.close();
			remove("Student.txt");
			rename("temp.txt","Student.txt");
		}
	Faculty createFaculty(){
		string name ,address, cnic, phoneNo, department, position, section;
		int n, s;
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter Address : ";
		cin >> address;
		cout << "Enter CNIC : ";
		cin >> cnic;
		cout << "Phone Number : ";
		cin >> phoneNo;
		cout << "Enter department : ";
		cin >> department;
		cout << "Enter Position :";
		cin >> position;
		cout << "Enter Section :";
		cin >> section;
		cout << "Enter Semester Alot";
		cin >> s;
		Faculty f(name,address,cnic,phoneNo,department,position,section,s);
		return f; 
	}
	void updateFacultyRecord(string id){
	ifstream f;
	ofstream g;
	f.open("Faculty.txt");
	g.open("temp.txt");
	Faculty ff;
	for(int i = 0; i < facultyCount(); i++){
		ff.readFromFile(i);
		if(ff.getFacultyId() == id)
			continue;
		g.write((char*)&ff,sizeof(Faculty));
	}
	remove("Faculty.txt");
	rename("temp.txt","Faculty.txt");
	ff.writeInFile();
	}
	void FacultyRegisterCourse(Faculty f){
	string name,cc;
	int ch;
	cout << "Enter Course Name : ";
	cin >> name;
	cout << "Enter Course Code : ";
	cin >> cc;
	cout << "Enter Credit Hours : ";
	cin >> ch;
	if(ch != 3){
		Lab l(name,ch,cc,f.getEmpName());
		f.assignedLabs.push_back(l);
	}
	Course c(name,ch,cc,f.getEmpName());
	f.assignedCourses.push_back(c);
	return;
	}
	Faculty searchFaculty(string id){
		Faculty f;
		bool flag;
		for(int i = 0 ; i < facultyCount() ; i++){
			f.readFromFile(i);
			if(f.getFacultyId() == id){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "Not Found" << endl;
		}
		return f;
		
	}
	Student searchStudent(string id){
		Student f;
		bool flag;
		for(int i = 0 ; i < totalStudents() ; i++){
			f.readFromFile(i);
			if(f.getStudId() == id){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "Not Found" << endl;
		}
		return f;
		
	}	
		void addStudent(Student s){
			s.writeInFile();
		}
		void writeInFile(){
				ofstream f;
				f.open("Adm.txt");
				if(f.fail()){
   				   cout << "Can not open file " << endl;
   				   return;
	   			}
				f.write((char*)this,sizeof(*this));
				f.close();
			}
		void readFromFile(int i){
				ifstream f;
				f.open("Adm.txt");
				if(f.fail()){
   				   cout << "Can not open file " << endl;
   				   return;
	   			}
				f.seekg(i * sizeof(Administration));
				f.read((char *)this,sizeof(*this));
				f.close();
			}	
		Student createStudent(){  /* string name,string pEmail,int n*/
			string name;
			string pEmail,phoneNo;
			int semester;
			cout << "Enter name : ";
			cin >> name;
			cout << "Enter Personal Email :";
			cin >> pEmail;
			cout << "Enter Phone Number : ";
			cin >> phoneNo;
			cout << "Enter Semester :";
			cin >> semester;
			Student s(name,pEmail,phoneNo,semester);
			studRegCourse(s);
			s.writeInFile();
			system("cls");
			s.studBasicDisplay();
			system("pause");
			return s;
		}
		void assignCourseToStud(Course c,string id){
			Student s;
			bool flag;
			for(int i = 0 ; i < totalStudents() ;i++){
				s.readFromFile(i);
				if(s.getStudId() == id){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << "Student not found !" << endl;
			}
			s.courses.push_back(c);
	}
		char * getAdmId(){
				return id;
			}
		int virtual getNumOfStudEnrolled(string courseCode){
				Student s;
				int count = 0;
				for(int i = 0 ; i < totalStudents();i++){
					s.readFromFile(i);	
					for(auto it = s.courses.begin() ; it!= s.courses.end() ; it++){
						if(it->getCourseCode() == courseCode)
						count ++;
					}
					for(auto it = s.labs.begin(); it != s.labs.end(); it++){
						if(it->getCourseCode() == courseCode)
							count++;
					}	
				}
				return count;
			}
	void addCourseToFaculty(string facultyID){
		Faculty f;
		bool flag;
		for(int i = 0 ; i < facultyCount() ; i++){
			f.readFromFile(i);
			if(f.getFacultyId() == facultyID){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Record Not Found" << endl;
			return;
		}
		updateFacultyRecord(facultyID);
		FacultyRegisterCourse(f);
		cout << "Course Assigned!" << endl;
	}
	char * getAdmPwd(){
		return admPwd;
	}
};
int totalAdm(){
	ifstream f;
	f.open("Adm.txt");
	f.seekg(0,ios::end);
	return (int)f.tellg() / sizeof(Administration);
}
Student CourseForFaculty(){
	
}
floats::floats(){
	this->totMarks = 0;
	this->marksObt = 0;
	this->marksFlag = 0;
}
Marks::Marks(){
	for (int i = 0 ; i < 2 ; i++){
		sessionals[i].marksObt = 0;
		sessionals[i].totMarks = 0;
		sessionals[i].totalWeightage = 15;
	}
	for(int i = 0 ; i < 3 ; i++){
		assignments[i].marksObt = 0;
		assignments[i].totMarks = 10;
		assignments[i].totalWeightage = 3.33;
		assignments[i].weightageObt = 0;
		quizes[i].totMarks = 10;
		quizes[i].marksObt = 0;
		quizes[i].totalWeightage = 3.33;
		quizes[i].weightageObt = 0;
	}
	final.marksObt = 0;
	final.totMarks = 100;
	final.totalWeightage = 50;	
}
void Marks::setSessionalObtMarks(float marks , int n){
	sessionals[n].marksObt = marks;
	sessionals[n].marksFlag = 1;
	float a = ((sessionals[n].marksObt / sessionals[n].totMarks) *sessionals[n].totalWeightage);
	sessionals[n].weightageObt = a;
//	gg += a;
//	sessionals[n].weightageObt = 
//	Course::updateGpa('s');
}
float Marks::getSessionalObtMarks(int n){
	return sessionals[n].marksObt;
}
float Marks::getAssignmentObtMarks(int n){
	return assignments[n].marksObt;
}
void Marks::setAssignmentObtMarks(float marks,int n){
	assignments[n].marksObt = marks;
	assignments[n].marksFlag = 1;
	float a = ((assignments[n].marksObt / assignments[n].totMarks) * assignments[n].totalWeightage);
	assignments[n].weightageObt = a;
//	gg += a;

//	Course::updateGpa('s');
}
float Marks::getQuizObtMarks(int n){
	return quizes[n].marksObt;
}
void Marks::setQuizObtMarks(float marks,int n){
	quizes[n].marksObt = marks;
	quizes[n].marksFlag = 1;
	float a = ((quizes[n].marksObt / quizes[n].totMarks) * quizes[n].totalWeightage);
//	gg += a;
//	Course::updateGpa('q');
}
void Marks::setSessionalTotMarks(float marks , int n){
	sessionals[n].totMarks = marks;
	sessionals[n].marksFlag = 1;
}
void Marks::setAssignmentTotMarks(float marks,int n){
	assignments[n].totMarks = marks;
	assignments[n].marksFlag = 1;
}
void Marks::setQuizTotMarks(float marks,int n){
	quizes[n].totMarks = marks;
	quizes[n].marksFlag = 1;
}
void Marks::setFinalObtMarks(float marks){
	final.marksObt = marks;
	final.marksFlag = 1;
	float a = ((final.marksObt / final.totMarks) * final.totalWeightage);
//	gg += a;

}
void Marks::setFinalTotMarks(float marks){
	final.totMarks = marks;
	final.marksFlag = 1;
}
Course::Course(string courseName1,double creditHours,string courseCode1,string instructor){
				stringCopy(this->courseName ,courseName1,courseName1.length());
				this->creditHours = creditHours;
				stringCopy(this->courseCode ,courseCode1,courseCode1.length());
				stringCopy(this->courseInstructor,instructor,instructor.length());

			}
void Course::courseDisplay(){
				cout << "Course Name : " << courseName << endl;
				cout << "Course Code : " << courseCode << endl;
				cout << "Credit Hours : " << creditHours << endl;
			}
void Course::updateGpa(char c){
	if(c == 's' || c == 'S'){
	for(int i = 0 ; i < 2 ; i++){
		if(marks.sessionals[i].totMarks != 0){
			float a = ((marks.sessionals[i].marksObt / marks.sessionals[i].totMarks) * marks.sessionals[i].totalWeightage);
			 marks.sessionals[i].weightageObt = a;
			gg += a;
		}
	}
	return;
  }
  if(c == 'a' || c == 'A'){
	for(int i = 0 ; i < 3; i++){
		if(marks.assignments[i].totMarks != 0){
			float a = ((marks.assignments[i].marksObt / marks.assignments[i].totMarks) * marks.assignments[i].totalWeightage);
			marks.assignments[i].weightageObt = a;
			gg = gg +a;
		}
	}
	return;
  }
  if(c == 'q' || c == 'Q'){
	for(int i = 0 ; i < 3; i++){
		if(marks.quizes[i].totMarks != 0){
			float a = (( marks.quizes[i].marksObt / marks.quizes[i].totMarks) * marks.quizes[i].totalWeightage );
			marks.quizes[i].weightageObt = a;
			gg += a;
		}
	}
	return;
  }
  if(c == 'f' || c == 'F'){
  	if(marks.final.totMarks != 0){
  		float a = ((marks.final.marksObt / marks.final.totMarks) * marks.final.totalWeightage);
  		marks.final.weightageObt = a;
		  gg += a;
	  }	
  }
}
void Course::updateGrade(){
	bool flag;
	for(int i = 0 ; i < 2 ; i++){
		if(marks.sessionals[i].marksFlag){
			flag = false;
			break;
		}
	}
}
//int Course::getNumOfStudEnrolled(){
//	return numberOfStudEnrolled;
//}
int Employee::totEmps = 0;
Employee::Employee(string n,string a,string c,string p){
			stringCopy(this->name,n,n.length());
			stringCopy(this->address,a,a.length());
			stringCopy(this->cnic,c,c.length());
			stringCopy(this->phoneNo,p,p.length());
		}
		
void Employee:: display(){
			cout << "Name : " << name << endl;
			cout << "Address : " << address << endl;
			cout << "Cnic : " << cnic << endl;
			cout << "Phone Number : " << phoneNo << endl;
		}
void Employee::setWarningFlag(bool f){
	this->warningFlag = f;
}
bool Employee::getWarningFlag(){
	return warningFlag;
}
void Employee::setSalary(double a){
	this->salary = a;
}
double Employee::getSalary(){
	return salary;
}
int Administration::forID = 10;
int Course::attendanceCounter = 0;
int Faculty::forId = 1;
int Faculty::forEmail = 1;


void Faculty::viewAssignedCourses(){
	for(auto it = assignedCourses.begin() ; it != assignedCourses.end(); it ++){
		it->courseDisplay();
	}
}
void Faculty::assignCourse(Course c){
	assignedCourses.push_back(c);
}
void loading(){
	system("pause");
	system("cls");
	cout << "Loading......" << endl;
	for(int i = 0 ; i < 1000000; i++);
}
void viewQuizMarks(Course c)
{
	int n;
	cout<<"ENTER 1 TO VIEW QUIZ 1 MARKS"<<endl;
	cout<<"ENTER 2 TO VIEW QUIZ 2 MARKS"<<endl;
	cout<<"ENTER 3 TO VIEW QUIZ 3 MARKS"<<endl;
	cout<<"ENTER 4 TO GO BACK"<<endl;
	cin >> n;
	n--;
	if(n >= 0 && n <= 3){
	system("cls");
	cout << "Quiz : " << n + 1 << endl;
	cout << "Total Marks : " << c.marks.quizes[n].totMarks << "Marks Obtained : " << c.marks.quizes[n].marksObt << endl; 
	cout << "Total Weightage : " << c.marks.quizes[n].totalWeightage << "Weightage Obtained : " << c.marks.quizes[n].weightageObt << endl; 
	}
	if(n == 4)
		return;
	else{
		cout << "Enter Correct Option !" << endl;
		viewQuizMarks(c);
	}
}
void viewAssignmentMarks(Course c)
{
	int n;
	cout<<"ENTER 1 TO VIEW ASSIGNMENT 1"<<endl;
	cout<<"ENTER 2 TO VIEW ASSIGNMENT 2"<<endl;
	cout<<"ENTER 3 TO VIEW ASSIGNMENT 3"<<endl;
	cout<<"ENTER 4 TO Fo Back"<<endl;
	cin >> n;
	n--;
	if(n >= 0 && n <= 3){
	system("cls");
	cout << "Assignment : " << n + 1 << endl;
	cout << "Total Marks : " << c.marks.assignments[n].totMarks << "Marks Obtained : " << c.marks.assignments[n].marksObt << endl; 
	cout << "Total Weightage : " << c.marks.assignments[n].totalWeightage << "Weightage Obtained : " << c.marks.assignments[n].weightageObt << endl; 
	}
	if(n == 4)
		return;
	else{
		cout << "Enter Correct Option !" << endl;
		viewAssignmentMarks(c);
	}
}
void viewSessionalMarks(Course c)
{
	int n;
	cout<<"ENTER 1 TO VIEW SESSIONAL 1 MARKS"<<endl;
    cout<<"ENTER 2 TO VIEW SESSIONAL 1 MARKS"<<endl;
	cout << "ENTER 3 TO Fo Back" << endl;
	cin >> n;
	n--;
	if(n >= 0 && n <= 2){
	system("cls");
	cout << "Sessional : " << n + 1 << endl;
	cout << "Total Marks : " << c.marks.sessionals[n].totMarks << "Marks Obtained : " << c.marks.sessionals[n].marksObt << endl; 
	cout << "Total Weightage : " << c.marks.sessionals[n].totalWeightage << "Weightage Obtained : " << c.marks.sessionals[n].weightageObt << endl; 
	}
	if(n == 3){
		loading();
		return;
	}
		
	else{
		cout << "Enter Correct Option !" << endl;
		viewQuizMarks(c);
	}
}
void viewFinalMarks(Course c)
{
	system("cls");
	cout << "Final " << endl;
	cout << "Total Marks : " << c.marks.final.totMarks << "Marks Obtained : " << c.marks.final.marksObt << endl; 
	cout << "Total Weightage : " << c.marks.final.totalWeightage << "Weightage Obtained : " << c.marks.final.weightageObt << endl; 
	
}
void view_courses_offer()
{
	char course;
	cout<<"ENTER 1 TO SEE FRESHMEN COURSES"<<endl;
	cout<<"ENTER 2 TO SEE SPHOMORE COURSES"<<endl;
	cout<<"ENTER 3 TO SEE JUNIOR COURSES"<<endl;
	cout<<"ENTER 4 TO SEE SENIOR COURSES"<<endl;
	cin>>course;
	switch(course)
	{
		case '1':
			cout<<"Freshmen (BATCH-2021):"<<endl;						
            cout<<"All Non-muslim Students have to register Ethics instead of Pakistan Studies and Islamic Studies."<<endl;							
            cout<<"If Programming Fundamentals(Theory  + Lab) is not cleared so can't register Object Oriented programming."<<endl;							
            cout<<"If Calculus and Analaytical Geometry is not cleared so can't register Differential Equations."<<endl;		
			break;
			
		case '2':
		    cout<<"Sophomore (BATCH-2020):"<<endl;													
            cout<<"Elective Track			CHOOSE ANY ONE ELECTIVE"<<endl;				
            cout<<"BCS MG/SS Elective Track			Psychology"<<endl;                      			
            cout<<"BSE MG/SS Elective Track			Psychology"<<endl;                          		
            cout<<"If DataStructures(Theory  + Lab) is not cleared,so can't register Operating Systems."<<endl;							
            break;
        case '3':
        	cout<<"Juniors (BATCH-2019):"<<endl;			
            cout<<" Elective Track			CHOOSE ANY ONE ELECTIVE"<<endl; 				
            cout<<"BCS CS Elective Track:	Deep Learning for Perception      OR    Information Retrieval   OR  Business Analytics Technique   OR  Data Science"<<endl;
            break;
        case '4':
        	cout<<"Seniors (BATCH-2018):"<<endl;			
            cout<<"Elective Track			CHOOSE ANY ONE ELECTIVE:"<<endl;				
            cout<<"CS Elective Track # 1	Data Science               OR             Deep Learning for Perception "<<endl;				
            cout<<"CS Elective Track # 2    Introduction to Cloud Computing       OR       Fundamentals of Internet of things"<<endl;  				
            break;
        default:
        	cout<<"invalid";
	}
}
void studentLogin(Student s){
	char ch;
	cout << "Welcome : " << s.getStudName() << endl;
	cout << "1. Personal Info" << endl;
	cout << "2. Courses Registered" << endl;
	cout << "3. View Marks " << endl;
	cout << "4. View Attendance" << endl;
	cout << "5. View Courses Offer" << endl;
	cout << "6. Logout" << endl;
	cin >> ch;
	if(ch == '1'){
	s.completeStudDisplay();
	loading();
	studentLogin(s);
	}
	if(ch == '2'){
		for(auto it = s.courses.begin() ; it != s.courses.end() ; it++){
			cout << "Course Name : " << it->getCourseName() << " " << "Course Code : " << it->getCourseCode() << endl;
		}
		for(auto it = s.labs.begin() ; it != s.labs.end() ; it++){
			cout << "Course Name : " << it->getCourseName() << " " << "Course Code : " << it->getCourseCode() << endl;
		}
		loading();
		studentLogin(s);
	}
	if(ch == '3'){
		string str;
		bool flag;
		cout << "Enter Course Code : ";
		cin >> str;
		system("cls");
		for(auto it = s.courses.begin() ; it != s.courses.end() ; it++){
			if(it->getCourseCode() == str){
				flag =  false;
				while(1){
				cout << "1. View Quiz Marks" << endl;
				cout << "2. View Assignment Marks" << endl;
				cout << "3. View Sessional Marks" << endl;
				cout << "4. View Final Marks" << endl;
				cout << "5. View Total Marks" << endl;
				cout << "6. Go back to menu" << endl;
				cin >> ch;
				switch(ch){
					case '1':
						viewQuizMarks(*it);
						break;
					case '2':
						viewAssignmentMarks(*it);
						break;
					case '3':
						viewSessionalMarks(*it);
						break;
					case'4':
						viewFinalMarks(*it);
						break;	
					case '5':
						it->courseMarksDisplay();
						break;
					case '6':
						studentLogin(s);
						break;
					default :
						cout << "Wrong details" << endl;
						sleep(4);
						system("cls");
						break;	
				}
				loading();
			}
		}
	}
  }
	if(ch == '4'){
		cout << "Your Attendance : " << endl;
		for(auto it = s.courses.begin() ; it != s.courses.end() ;it++){
			cout << "For Course : " << it->getCourseName() << "Attendance" << it->viewAttendancePercent() << endl;
		}
		loading();
		studentLogin(s);
	}
	if(ch == '5'){
	view_courses_offer();
		loading();
		studentLogin(s);
	}
	if(ch== '6'){
		loading();
		exit(0);
	}
}

void facultyLogin(Faculty f){
	char ch;
	cout << "1. View Courses Assigned Theory" << endl;
	cout << "2. View Courses Assigned Labs" << endl;
	cout << "3. Mark Attendance" << endl;
	cout << "4. Update Total Marks For Theory Course" << endl;
	cout << "5. Update Marks Obtained For Theory Course" << endl;
	cin >> ch;
	if(ch == '1'){
		for(auto it = f.assignedCourses.begin() ; it != f.assignedCourses.end() ; it++){
			it->courseDisplay();
		}
		loading();
		facultyLogin(f);
	}
	if(ch == '2'){
		for(auto it = f.assignedLabs.begin() ; it != f.assignedLabs.end() ; it++){
			it->courseDisplay();
		}
		loading();
		facultyLogin(f);
	}
	if(ch == '3'){
		string str;
		cout << "Enter Course Code : ";
		cin >> str;
		f.markAttendanceOfAllStuds(str);
		loading();
		facultyLogin(f);
	}
	if(ch == '4'){
		cout << "1.	Set Assignments Total Marks" << endl;
		cout << "2.	Set Quiz Total Marks" << endl;
		cout << "3.	Set Sessional Total Marks" << endl;
		cout << "4.	Set Final Total Marks" << endl;
		cin >> ch;
		if(ch == '1')
			f.setAssignmentTotMarksForAllStud();
		if(ch == '2')
			f.setQuizTotMarksForAllStud();
		if(ch == '3')
			f.setSessionalTotMarksForAllStud();
		if(ch == '4')
			f.setFinalTotMarksForAllStud();
		loading();
		facultyLogin(f);	
	}
	if(ch == '5'){
		cout << "1.	Set Assignments Obtain Marks" << endl;
		cout << "2.	Set Quiz Obtain Marks" << endl;
		cout << "3.	Set Sessional Obtain Marks" << endl;
		cout << "4.	Set Final Obtained Marks" << endl;
		cin >> ch;
		if(ch == '1')
			f.setAssignmentObtMarksForAllStud();
		if(ch == '2')
			f.setQuizObtMarksForAllStud();
		if(ch == '3')
			f.setSessionalObtMarksForAllStud();
		if(ch == '4')
			f.setFinalObtMarksForAllStud();
		loading();
		facultyLogin(f);
	}
}
void admLogin(Administration a){
	int ch;
	cout << "1. Add Student " << endl;
	cout << "2. Remove Student" << endl;
	cout << "3. Add Faculty" << endl;
	cout << "4. Remove Faculty" << endl;
	cout << "5. View Total Number Of Students Enrolled In A Course" << endl;
	cout << "6. Update Faculty" << endl;
	cout << "7. Add Administrator" << endl;
	cout << "8. Remove Administrator" << endl;
	cout << "9. Close Marks Submission" << endl;
	cout << "10. Personal Information" << endl;
	cout << "11. Course Registration" << endl;
	cout << "12. Assign Course To Faculty" << endl;
	cout << "13. Exit" << endl;
	cin >> ch;
	while(1){
		switch(ch){
			case 1:
			{
				Student s = a.createStudent();
				s.writeInFile();
				loading();
				admLogin(a);
			break;
			}
			case 2:
			{
				
				string id;
				cout << "Enter Student ID : ";
				cin >> id;
				a.removeStudent(id);
				loading();
				admLogin(a);
				break;
			}
			case 3:
			{
				Faculty f = a.createFaculty();
				f.writeInFile();
				loading();
				admLogin(a);
				break;
			}
			case 4:
			{
				cout << "Enter ID : ";
				string str;
				cin >> str;
				a.removeFaculty(str);
				loading();
				admLogin(a);
				break;
			}
			case 5:{
				string code;
				cout << "Enter Course Code" << endl;
				cin >> code;
				cout << "Total Students in Course : " << a.getNumOfStudEnrolled(code) << endl;
				loading();
				admLogin(a);
				break;
			}
		case 6:{
			string id;
			int n;
			bool flag = true;
			cout << "Enter Faculty ID : " << endl;
			cin >> id;
			Faculty f = a.searchFaculty(id);
			if(flag){
				cout << "What Do You Want to Update" << endl;
				cout << "1. Salary" << endl;
				cout << "2. Name" << endl;
				cin >> n;
				if(n == 1){
					cout << "Enter New Amount" << endl;
					double sal;
					cin >> sal;
					f.setSalary(sal);
					a.updateFacultyRecord(f.getFacultyId());
				}
				if(n == 2){
					cout << "This Feature isnt implemented yet" << endl;
				}
				loading();
				admLogin(a);
			}
			break;
		}
		case 7:{
			Administration adm = a.createAdministrator();
			adm.writeInFile();
			loading();
			admLogin(a);
			break;
		}
		case 8:{
			string id;
			cout << "Enter ID :";
			cin >> id;
			a.removeAdm(id);
			loading();
			admLogin(a);
			break;
		}
		case 9:{
			Student s;
			for(int i = 0 ; i < totalStudents() ; i++){
				s.readFromFile(i);
				s.setGpa();
			}
			loading();
			admLogin(a);
			break;
		}
		case 10:{
			a.display();
			loading();
			admLogin(a);
			break;
		}
		case 11:{
			cout << "Enter Student ID  :";
			string id;
			cin >> id;
			studRegCourse(a.searchStudent(id));
			loading();
			admLogin(a);
			break;
		}
		case 12:{
			string id;
			cout << "Enter ID : ";
			cin >> id;
			a.addCourseToFaculty(id);
			loading();
			admLogin(a);
			break;
		}
		case 13:{
			exit(0);
			break;
		}
		
	}
	}
}
class Login{
	int count;
    string id,pass,u,p;
    ifstream fileRead;
    ofstream fileWrite;
    bool fg;
    public:
    	void getInput(){
        system("cls");
        cout << "please enter the following details " << endl;
        cout << "Your ID :";
        cin >> id;
        cout<<"Your Password :";
        cin >> pass;
        int fileToBeOpen;
        Student s;
		if(id[0] == 'S' || id[0] == 's'){
			bool flag = true;
			fileRead.open("Student.txt");
			for(int i = 0 ; i < totalStudents() ;i++){
				s.readFromFile(i);
				if(s.getStudId() == id){
					loading();
						studentLogin(s);
						flag = false;
					}
				}
					if(flag){
						cout << "Your password is incorrect !" << endl;
						system("pause");
						getInput();
					}
		}
	

		if(id[0] == 'F' || id[0] == 'f'){
			bool flag = true;
			Faculty f;
			fileRead.open("Faculty.txt");
			for(int i = 0 ; i < facultyCount() ;i++){
				f.readFromFile(i);
				if(f.getFacultyId() == id){	
						loading();
						facultyLogin(f);
						flag = false;
					}
				}
					if(flag){
						cout << "Your password is incorrect !" << endl;
						system("pause");
						getInput();
					}
			}
			
		if(id[0] == 'A' || id[0] == 'a'){
			bool flag = true;
			Administration a;
			fileRead.open("Adminstration.txt");
			for(int i = 0 ; i < totalAdm() ;i++){
				a.readFromFile(i);
				if(a.getAdmId() == id){
					loading();
						admLogin(a);
						flag = false;
					}
				}
					if(flag){
						cout << "Your password is incorrect !" << endl;
						system("pause");
						getInput();
					}
				}
		else {
			cout << "Enter Correct Details" << endl;
			loading();
			getInput();
		}
	
}
void forgotPassword(){
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter your phone number : ";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgotPassword();
        }
}
void menu(){
	    int choice;
	    system("cls");
        cout<<"***********************************************************************\n\n";
		cout<<"                      Welcome to login page                               \n\n";    
	    cout<<"*******************        MENU        ********************************\n\n";
        cout<<"1.LOGIN\n";
        cout<<"2.FORGOT PASSWORD (or) USERNAME\n";
        cout<<"3.Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        getInput();
                        break;
                case 2:
                        forgotPassword();
                        break;
                case 3:

                        cout<<"Thanks for using this program\nThis program is created by Anas ,Hashmi and Saif\n";
                        break;
                default:
                        system("cls");
                        cout<<"Wrong Choice Intered\n"<<endl;
                        menu();
        }
		
}
};
// s-k-mo10 71s8j#
// 71s8j#
int main()
{	

	Course c1("Object Oriented Programming Theory",3,"OOP-18s","Abeer Gohar");
	c1.marks.setSessionalTotMarks(40,0);
	c1.marks.setSessionalObtMarks(30,0);
	c1.marks.setSessionalTotMarks(40,1);
	c1.marks.setSessionalObtMarks(30,1);
	c1.marks.setQuizTotMarks(10,0);
	c1.marks.setQuizObtMarks(10,0);
	c1.marks.setQuizTotMarks(15,1);
	c1.marks.setQuizObtMarks(10,1);
	c1.marks.setQuizTotMarks(15,2);
	c1.marks.setQuizObtMarks(10,2);
	c1.marks.setAssignmentTotMarks(100,0);
	c1.marks.setAssignmentObtMarks(80,0);
	c1.marks.setAssignmentTotMarks(100,1);
	c1.marks.setAssignmentObtMarks(80,1);
	c1.marks.setAssignmentTotMarks(100,2);
	c1.marks.setAssignmentObtMarks(100,2);
	c1.marks.setFinalTotMarks(100);
	c1.marks.setFinalObtMarks(70);																			
	c1.updateGpa('s');
	c1.updateGpa('q');
	c1.updateGpa('a');
	c1.updateGpa('f');
	c1.writeInFile();
	course 2
	Course c2("Differential Equation",3,"MT-109s","Nadeem Khan");
	c2.marks.setSessionalTotMarks(50,0);
	c2.marks.setSessionalObtMarks(45,0);
	c2.marks.setSessionalTotMarks(40,1);
	c2.marks.setSessionalObtMarks(30,1);
	c2.marks.setQuizTotMarks(10,0);
	c2.marks.setQuizObtMarks(10,0);
	c2.marks.setQuizTotMarks(15,1);
	c2.marks.setQuizObtMarks(13,1);
	c2.marks.setQuizTotMarks(15,2);
	c2.marks.setQuizObtMarks(12,2);
	c2.marks.setAssignmentTotMarks(100,0);
	c2.marks.setAssignmentObtMarks(80,0);
	c2.marks.setAssignmentTotMarks(100,1);
	c2.marks.setAssignmentObtMarks(90,1);
	c2.marks.setAssignmentTotMarks(100,2);
	c2.marks.setAssignmentObtMarks(100,2);
	c2.marks.setFinalTotMarks(100);
	c2.marks.setFinalObtMarks(80);
	c2.updateGpa('s');
	c2.updateGpa('q');
	c2.updateGpa('a');
	c2.updateGpa('f');
	c2.writeInFile();
	Student s1("Mohammad Anas","mohammadanas1a.333@gmail.com","03131009753",2);
	s1.courses.push_back(c1);
	s1.courses.push_back(c2);
	s1.writeInFile();
	s1.getStudentIDPWd();

	Login m;
	m.menu();

	return 0;

}


















