#include<iostream>
#include<vector>
using namespace std;
bool subsequent(string s1,string s2){
	static int i=0,j=0;
	if(i==s1.length()-1 && j != s2.size()-1){
		return false;
	}
	if(j==s2.length()-1){
		return true;
	}
	if(s1[i] == s2[j]){
		i++;
		j++;
	}else{
		i++;
	}
	return subsequent(s1,s2);
}
int main(){
	string s1,s2;
	cout<<"Enter actual string: ";
	cin>>s1;
	cout<<"Enter subsequent string: ";
	cin>>s2;
	if(subsequent(s1,s2)){
		cout<<s2<<" is subsequent of "<<s1<<endl;
	}else{
	cout<<s2<<" is not a subsequent of "<<s1<<endl;
	}
	return 0;
}