#include<iostream>
using namespace std;
class Employee{
	protected:
		string name;
		string code;
	public:
		Employee(){};
		Employee(string name,string code){
			this->name = name;
			this->code = code;
		}
};
class Consultant : virtual public Employee{
	protected:
		int yearsOfExperience;
	public:
		Consultant(){};
		Consultant(string name,string code,int y):
			Employee(name,code){
				this->yearsOfExperience = y;
			}
};
class Manager : virtual public Employee{
	protected:
		int noOfTeams;
	public:
		Manager(){};
		Manager(string name,string code,int t):
		Employee(name,code){
			this->noOfTeams = t;
		}
};
class ConsultantManager : public Consultant , public Manager{
	public:
		ConsultantManager(string name,string code,int y,int t):
			Employee(name,code){
				yearsOfExperience = y;
				noOfTeams = t;
			}
		void display(){
			cout << "Name : " << name << endl;
			cout << "Code : " << code << endl;
			cout << "Years Of Experience : " << yearsOfExperience << endl;
			cout << "Number Of Teams : " << noOfTeams << endl;
		}
};
int main(){
	ConsultantManager *p = new ConsultantManager("Ali","S-123",17,5);
	p->display();
	return 0;
}
