#include<iostream>
using namespace std;
void permutation(string s,int k){
	static int flag[10] = {0};
	static char res[10];
	for(int i = 0 ; s[i] != '\0' ; i++){
		if(flag[i] == 0){
			res[k] = s[i];
			flag[i] = 1;
			cout << "going forward value of i is " << i << "value of k is " << k << endl;
			permutation(s,k+1);
			cout << "going back value of i is " << i << "value of k is " << k << endl;
			flag[i] = 0;
		}
	}
	if(s[k] == '\0'){
		cout << res << endl;
	}
}
int main(){
	permutation("ABC",0);
	return 0;
}
