#include<iostream>
using namespace std;
void strRev(string &s,int len,int i,char c = ' '){
	if(i > len)
		return;
	strRev(s,len,i+1,s[i]);
	s[i] = c;
}
int main(){
	string s = "anas";
	char c;
	strRev(s,3,0);
	cout << s << endl;
}
