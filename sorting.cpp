#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sort_(int arr[],int n){
	map<int,int> obj;
	map<int,bool> vis;
	for(int i = 0 ; i < n ; i++){
		obj[arr[i]]++;
		vis[arr[i]] = true;

	}
	for(int i = 0 ; i < n ; i++){
		if(vis[arr[i]]){
			vis[arr[i]] = false;
			for(int j = 0 ; j < obj[arr[i]] ; j++)
				cout << arr[i] << " ";
		}
	}
}
int main(){
	int arr[] = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };
	int n = sizeof(arr)/sizeof(arr[0]);
	sort_(arr,n);
	
}
