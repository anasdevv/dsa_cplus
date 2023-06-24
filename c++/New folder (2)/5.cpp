#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee
{
	private:
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
	void setEmployee(string name,string type){
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
		this->pharmcist = pharmicst;
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
		string manufactureDate;  /* Use dd/mm/yy format for date */
		string expiryDate;
		string type;
	public:
		
		Medicine(string name,string formula,double price,string manufactureDate,string expiryDate){
			this->name = name;
			this->formula = formula;
			this->price = price;
			this->expiryDate = expiryDate;
			this->manufactureDate = manufactureDate;
		}
		bool operator == (Medicine &m){
			int a = stoi(expiryDate[expiryDate.length()-1]);
			int b = stoi(m.expiryDate[expiryDate.length()-1]);
			return (a == b)
		}
		void display(){
			cout << "Name : " << name << endl;
			cout << "Formula : " << formula << endl;
			cout << "Price : " << price << endl;
			cout << "Manufacture Data : " << manufactureDate << endl;
			cout << "Expiry Date : " << expiryDate << endl;
		}	
};
class Pharmcist : virtual public Medicine
{
	public:
		searchMedicine( vector <Medicine> tabl, vector <Medicine> cap,vector <Medicine> syp , string formula){
			vector <Medicine> temp;
			temp = tabl;
			temp.insert(temp.end(),cap.begin(),cap.end());
			temp.insert(temp.end(),syp.begin(),syp.end());
			for (auto it = temp.begin() ; it != temp.end() ; it++){
				if(it->formula == formula){
					flag = true;
					cout << "Medicine Found" << endl;
				}
			}
		}
}
class Tablet : public Medicine
{
	float sucroseLevel;
	public:
		Tablet(string name,string formula,double price,string manufactureDate,string expiryDate,float sucroseLevel):
		Medicine(name,formula,price,manufactureDate,expiryDate){
			this->sucroseLevel = (sucroseLevel >= 0 && sucroseLevel <=1) ? sucroseLevel : 0;
			type = "Tablet";
		}
};
class Capsules : public Medicine
{
	float absorptionPercentage;
	public:
		Capsules(string name,string formula,double price,string manufactureDate,string expiryDate,float absorbtionPercentage):
			Medicine(name,formula,price,manufactureDate,expiryDate){
//				absorptionPercentage >= 0 && absorptionPercentage <=100 ? this->absorptionPercentage = absorptionPercentage : this->absorptionPercentage = 0;
				this->absorptionPercentage = (absorptionPercentage >= 0 && absorptionPercentage <=100 ) ?  absorptionPercentage : 0;
				type = "Capsules";
			}
};
class Syrup : public Medicine
{
	public:
		Syrup(string name,string formula,double price,string manufactureDate,string expiryDate):
			Medicine(name,formula,price,manufactureDate,expiryDate){
				type = "Syrup";
			}
};
int main()
{
	Pharmacy a.display();
	Medicine m1;
	return 0;
}

