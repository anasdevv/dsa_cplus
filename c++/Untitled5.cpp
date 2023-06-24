#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char array[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
bool isInt(string s){
	bool flag = true;
	for(int i = 0 ; i < s.length() ;i++){
		if(!isdigit(s[i])){
			flag = false;
			break;
		}
	}
	return flag;
}
int convertToInt(string s){
	int num =0;
	for(int i = 0 ; i < s.length() ;i++){
		string ch;
		ch.push_back(s[i]);
		int x  = stoi(ch);
		num *= 10;
		num += x;
	}
	return num;
}

int main(){
	ofstream w;
	w.open("Encrypted.txt");
	ifstream f;
	f.open("input.txt");
	if(f.bad() ){
		cout << "Can not open file!" << endl;
		exit(0);
	}
	string ch;
	while(f >> ch){
		if(isInt(ch)){
			int n = convertToInt(ch);
			if(n > 0 && n <= 26){
				n--;
				w << array[n];
				cout << array[n];
			}
			else{
				n = 25;
				w << array[n];
				cout << array[n];
			}
		}
		else{
			for(int i = 0 ; i < ch.length() ; i++){
				if(isdigit(ch[i])){
					string s;
					s.push_back(ch[i]);
					int x = stoi(s);
					x--;
					w << array[x];
					cout << array[x];
				}
			}
		}
	}
	return 0;
}
