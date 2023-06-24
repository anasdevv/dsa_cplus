#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 int romanToInt(string s) {
        int sum = 0;
        map<char,int> obj;
        obj['I'] = 1;obj['V'] = 5;obj['X'] = 10;obj['L'] = 50;obj['C'] = 100;
        obj['D'] = 500;obj['M'] = 1000;
        for(int i = s.length() - 1 ; i >= 0 ; --i){
            if(obj[s[i]] > obj[s[i-1]] && i!= 0){
                sum += obj[s[i]] - obj[s[i-1]];
                i--;
                continue;
            }
            else{
                sum += obj[s[i]];
            }
        }
        return sum;
    }
    int main(){
      cout << romanToInt("III");
    }
