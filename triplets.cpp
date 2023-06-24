#include<bits/stdc++.h>
using namespace std;
void fun(vector<int> arr,int n){
	 map<int,int> obj;
    sort(arr.begin() , arr.end());
    int i = 0;
    for(int el : arr){
        obj[el] = i++;
    }
    
    bool flag = true;
    for(int i = 0 ; i < n-2 ; i++){
    	int s = i+1; int e = n-1;
    	while(s <= e){
    		if(arr[i] + arr[s] + arr[e] == 0){
    			cout << arr[i] << " " << arr[s] << " " <<arr[e] << endl;
    			s++;
    			e--;
			}
		else if(arr[i] + arr[s] + arr[e] > 0){
			e--;
		}
		else
			s++;	
		}       
    }
}
int main(){
//	vector<int> arr = {-10 ,3 ,5 ,5 ,2};
	vector<int> arr = {-1 -1 ,2 ,2 ,-1, -1};
	fun(arr,arr.size());
}
