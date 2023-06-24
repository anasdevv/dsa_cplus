#include<iostream>
using namespace std;
void findingDuplicates(string s){
	int x;
	long int h = 0; /*for 8 bytes and 32 bits it will serve as hashmap*/
	for(int i = 0 ; i < s.length() ; i++){
		x = 1;
		x = x << s[i] - 97;
		if((x & h) > 0) cout << s[i] << "is duplicate " << endl;
		else h = x | h;
	}
}
int main(){
	findingDuplicates("MedicalALLAldsas");
	return 0;
}
