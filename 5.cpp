#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee
{
	protected:
		string name;
		string type;
	
	public:
	void display(){
		cout << "Employee Name : " << name << endl;
		cout << "Employee Type: " << type << endl;
	}
	Employee(){};
	Employee(string name,string type){
		this->name = name;
		this->type = type;
	}	
};
class Pharmacy
{
	protected:
		Employee pharmcist;
		vector <Employee> counterStaff;
	public:
		Pharmacy(){};
	void displayAllCounterStaff(){
		for(auto it = counterStaff.begin() ; it!= counterStaff.end() ; it++)
			it->display();
	}
	void setPharmcist(Employee pharmicst){
		this->pharmcist;
	}
	void addCounterStaff(Employee counterStaff){
		this->counterStaff.push_back(counterStaff);
	}
};
class Medicine : public Pharmacy
{
	protected:
		string name;
		string formula;
		double price;
		string manufacturDate;
		string expiryDate;
		string type;
	public:
		
		Medicine(string name,string formula,double price,string manufactureDate,string expiryDate){
			this->name = name;
			this->formula = formula;
			this->price = price;
			this->expiryDate = expiryDate;
			this->manufacturDate = manufactureDate;
		}
};
class Tablet : public Medicine
{
	float sucroseLevel;
	public:
		Tablet(string name,string formula,double price,string manufactureDate,string expiryDate,float sucroseLevel):
		Medicine(name,formula,price,manufactureDate,expiryDate){
			sucroseLevel >= 0 && sucroseLevel <=1 ? this->sucroseLevel = sucroseLevel : this->sucroseLevel = 0;
			type = "Tablet";
		}
};
class Capsules : public Medicine
{
	float absorptionPercentage;
	public:
		Capsules(string name,string formula,double price,string manufactureDate,string expiryDate,float absorbtionPercentage):
			Medicine(name,formula,price,manufactureDate,expiryDate){
				absorptionPercentage >= 0 && absorptionPercentage <=100 ? this->absorptionPercentage = absorptionPercentage : this->absorptionPercentage = 0;
				type = "Capsules";
			}
};
class Syrup : public Medicine
{
	public:
		Syrup(string name,string formula,double price,string manufactureDate,string expiryDate):
			Medicine(name,formula,price,manufactureDate,expiryDate){
				type = "Capsules";
			}
};
int main()
{
	return 0;
}
