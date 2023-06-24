#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	ifstream f;
	f.open("ques1.txt");
	double a;
	double sum = 0,sd = 0;
	int i = 0;
	if(f.fail()){
		cout << "Can not open file" << endl;
		exit(0);
	}
	while(f >> a){
//		cout << "hi" <<endl;
//		f >> a;
//		cout << a << endl;
 		sum += a;
		i++;
	
	}
		f.close();
	f.open("ques1.txt");
//	i--;
	double avg = sum / i;
	cout << "Avg : " <<  avg << endl;
	a = 0;
	while(f >> a){
		cout << "Hi" << endl;
		sd += pow((a - avg),2);
		cout << sd << endl;
	}
	sd =  sqrt(sd/i);
	cout << "Sd is : " << sd << endl;
}
