#include<iostream>
using namespace std;
class Vehicle{
	protected:	
		string typeOfCar;
		string make;
		string model;
		double milesDriven;
	public:
		string color;
		string year;
		Vehicle(string typeOfCar,string make,string model,double milesDriven,string color,string year){
			this->typeOfCar = typeOfCar;
			this->make = make;
			this->model = model;
			this->milesDriven = milesDriven;
			this->color = color;
			this->year = year;
//			cout << "p1" << endl;
		}
		Vehicle(){
		  //  cout << "1" << endl;
		};
		void virtual display(){
			cout << "Type Of Car : " << typeOfCar << endl;
			cout << "Make : " << make << endl;
			cout << "Model : " << model << endl;
			cout << "Miles Driven : " << milesDriven << endl;
			cout << "Color : " << color << endl;
			cout << "Year : " << year << endl;
		}
};
class GasVehicle : virtual public Vehicle{
	protected:
	string fuelTankSize;
	public:
		GasVehicle(){
		  //  cout << "2" << endl;
		};
		GasVehicle(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f):
		Vehicle(typeOfCar,make,model,milesDriven,color,year){
			this->fuelTankSize = f;
// 			cout << "P2" << endl;
		}
		void display(){
			Vehicle::display();
			cout << "Fuel Tank Size : " << fuelTankSize << endl;
		}
};
class ElectricVehicle : virtual public Vehicle{
	protected:
	string energyStorage;
	public:
		ElectricVehicle(){
		  //  cout << "3" << endl;
		}
		ElectricVehicle(string typeOfCar,string make,string model,double milesDriven,string color,string year,string e):
		Vehicle(typeOfCar,make,model,milesDriven,color,year){
			this->energyStorage = e;
// 			cout << "P3" << endl;
		}
		void display(){
			Vehicle::display();
			cout << "Energy Storage : " << energyStorage << endl;
		}
};
class HighPerfomance : virtual public GasVehicle{
	protected:
	string horsePower;
	string topSpeed;
	public:
		HighPerfomance(){};
		HighPerfomance(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f,string h,string t):
			GasVehicle(typeOfCar,make,model,milesDriven,color,year,f){
				this->horsePower = h;
				this->topSpeed = t;
			}
			void display(){
				GasVehicle::display();
				cout << "Horse Power : " << horsePower << endl;
				cout << "Top Speed : " << topSpeed << endl;
			}
};
class SportsCar : public HighPerfomance{
	protected:
	string gearBox;
	string driveSystem;
	public:
		SportsCar(){};
		SportsCar(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f,string h,string t,string b,string d):
			HighPerfomance(typeOfCar,make,model,milesDriven,color,year,f,h,t){
				this->gearBox = b;
				this->driveSystem = d;
			}
			void display(){
				HighPerfomance::display();
				cout << "Gear Box : " << gearBox << endl;
				cout << "Drive system : " << driveSystem << endl;
			}
};
class HeavyVehicle : virtual public GasVehicle , virtual public ElectricVehicle{
	protected:
	double maxWeight;
	int numOfWheels;
	double length;
	public:
		HeavyVehicle(){
		  //  cout << "4" << endl;
		};
		HeavyVehicle(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f,string e,double m,int w,double len):
			GasVehicle(typeOfCar,make,model,milesDriven,color,year,f),ElectricVehicle(typeOfCar,make,model,milesDriven,color,year,e),
			Vehicle(typeOfCar,make,model,milesDriven,color,year){
//				fuelTankSize = f;
//				energyStorage = e;
// cout << "P4" << endl;
				this->maxWeight = m;
				this->numOfWheels = w;
				this->length = len;
			}
		void display(){
// 			GasVehicle::display();
// 			ElectricVehicle::display();
			Vehicle::display();
			cout << "Fuel Tank Size : " << fuelTankSize << endl;
			cout << "Energy Storage : " << energyStorage << endl;
			cout << "Maximum Weight : " << maxWeight << endl;
			cout << "Number Of Wheels : " << numOfWheels << endl;
			cout << "Length : " << length << endl;
		}
};
class ConstructionTruck : public HeavyVehicle {
	string cargo;
	public:
		ConstructionTruck(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f,string e,double m,int w,double len,string c):
			HeavyVehicle(typeOfCar,make,model,milesDriven,color,year,f,e,m,w,len){
				this->cargo = c;
			}
		void display(){
		
			HeavyVehicle::display();
			cout << "Cargo : "  << cargo << endl;
		}
};
class Bus : public HeavyVehicle{
	int noOfSeats;
	public:
		Bus(string typeOfCar,string make,string model,double milesDriven,string color,string year,string f,string e,double m,int w,double len,int n):
		HeavyVehicle(typeOfCar,make,model,milesDriven,color,year,f,e,m,w,len),GasVehicle(typeOfCar,make,model,milesDriven,color,year,f),ElectricVehicle(typeOfCar,make,model,milesDriven,color,year,e),
			Vehicle(typeOfCar,make,model,milesDriven,color,year){
			this->noOfSeats = n;
// 			cout << "p5" << endl;
		}
		void display(){
			HeavyVehicle::display();
			cout << "Number Of Seats : " << noOfSeats << endl;
		}
};
int main()
{
	Bus b("SUV","Abc","20-s1a",500,"black","2018","100","200",10000,4,50,70);
	b.display();
	return 0;
}
