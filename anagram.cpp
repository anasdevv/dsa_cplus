#include<iostream>
using namespace std;
bool checkAnagram(string s1,string s2){
	if(s1.length() > s2.length()) return false;
	int array[26] = {0};
	for(int i = 0 ; i < s1.length() ; i++){
		array[s1[i] - 97] += 1;
	}
	for(int i = 0 ; i < s2.length() ; i++){
		array[s2[i] - 97] -= 1;
		if(array[s2[i] - 97] < 0) return false;
	}
	return true;
}
int main(){
	cout<<checkAnagram("decimal","medical");
}
