#include<iostream>
using namespace std;
#include <bits/stdc++.h>
void subsets(string str , int index = 0, string current = ""){
	static int n = str.length();
	if(n == index){
		cout << current << endl;
		return;
	}
	subsets(str,index + 1,current+str[index]);
	subsets(str,index + 1,current);
}
int main(){
	subsets("ABC");
	return 0;
}
