#include<iostream>
#include<fstream>
using namespace std;
template<class T>

class LED{
	int screenSize;
	string model;
	int yearOfManufacture;
	int noOfSupportedApps;
	public:
		LED(int s,string m,int yom,int n){
			this->screenSize = s;
			this->model = model;
			this->yearOfManufacture = yom;
			this->noOfSupportedApps = n;
		}
};
class MobilePhone{
	string model;
	int yearOfManufacture;
	string cameraResolution;
	public:
		MobilePhone(string m,int yom,string c){
			this->model = m;
			this->yearOfManufacture = yom;
			this->cameraResolution = c;
		}

};
class Tablet{
	string model;
	int yearOfManufacture;
	int screenSize;
	public:
		Tablet(string model,int yom,int s){
			this->model = model;
			this->yearOfManufacture = yom;
			this->screenSize = s;
		}
	
};
class TrackingDevice{
	friend class RedTech;
	int yearOfManufacture;
	double accuracy;
	public:
		TrackingDevice(int y,double d){
			this->yearOfManufacture = y;
			this->accuracy = d;
		}
	int getYearOfManufacture(){
			return yearOfManufacture;
		}
};
class SmartRing : virtual public MobilePhone ,virtual public TrackingDevice{
	SmartRing(string m,int yom,string c,int y,double d):
		MobilePhone(m,yom,c),TrackingDevice(y,d){}
};
class RedTech{
	public:
		void checker(TrackingDevice a){
			if(a.yearOfManufacture < 2010){
				throw ("User Defined Exception");
			}
		}
};
int main(){
	
}
