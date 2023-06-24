#include <bits/stdc++.h>
using namespace std;
int main(){
	int num = 1234;
	string s = to_string(num);
	  vector <char> odd;
        vector <char> even;
        int j = 0 , k = 0 ;
		char n = 0 ;
		string sum ;
        for(int i = 0 ; i < s.length() ; i++){
            n = s[i] - '0';
            if(n % 2 != 0){
                odd.push_back(s[i]);
            } else{
                even.push_back(s[i]);
            }
        }
        sort(odd.begin(),odd.end(),greater<char>());
         sort(even.begin(),even.end(),greater<char>());
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] - '0' % 2 != 0){
            	cout << "odd : " << sum << endl;
                sum = sum + odd[k++];
            }else{
            	cout << "even : " << sum << endl;
                sum = sum + even[j++];
            }
        }
    cout << "sum : " << sum << endl;
}
