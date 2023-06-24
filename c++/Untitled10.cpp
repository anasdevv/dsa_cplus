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
		cout << a << endl;
 		sum += a;
		i++;
	}
	i--;
	double avg = sum / i;
	while(f>>a){
		sd += pow((a - avg),2);
	}
	sd =  sqrt(sd/i);
	cout << "Sd is : " << sd << endl;
}
