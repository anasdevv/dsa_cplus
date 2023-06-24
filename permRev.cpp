#include<iostream>
using namespace std;
void perm(string str,int k = 0){
	static int flag[10] = {0};
	static char res[10];
	int i = 0 ;
	for(i = 0 ; i < str.length() ; i++) {
		if(flag[i] == 0){
			res[k] = str[i];
			flag[i] = 1;
			 perm(str,k+1);
			flag[i] = 0;
		}
	}
	if(str[k] == '\0'){
		res[k] = '\0';
		k = 0;
		cout << res << endl;
		return;
	}
}
int main(){
 perm("abc" ) ;
	return 0;
}
