#include<iostream>
using namespace std;
bool checkLeap(int year){
	return (year % 400 == 0 || (year % 4 == 0) && (year % 100) != 0);
}
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
string a = "Error";
struct Date{
	int day;
	int month;
	int year;
	Date(int day,int month ,int year){
		bool flag = true;
		if(day < 0 || month < 0 || year < 0){
			throw a;
		}
		if(month > 12)
			throw a;
		if(days[month-1] < day)
			throw a;
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void print(){
		cout << day << "/" << month << "/" << year << endl;
	}
	bool operator > (Date &d){
		if(year > d.year)
			return true;
		else if(year == d.year){
			if(month > d.month)
				return true;
			else if(month == d.month){
				if(day > d.day)
					return true;
				else 
					return false;
			}
			else
				return false;
		}
		else 
			return false;
	}
};
int main(){
	
}

