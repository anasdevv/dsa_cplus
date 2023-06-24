#include<iostream>
using namespace std;
void indirectSort(int arr[],int n){
	int idx[n];
	for(int i = 0 ; i < n ; i++){
		idx[i] = i;
	}
	for(int i = 0 ; i < n  ;i++){
		int least = i;
		for(int j = i+1 ; j < n  ; j++){
			if(arr[j] < arr[least])
				least = j;
		}
		if(least != i)
			swap(idx[i] , idx[least]);
			
	}
	for(int i = 0 ; i < 5 ; i++)
		cout <<idx[i] << " ";
}
int main(){
	int arr[] = {13,29,91,34,56};
	indirectSort(arr,5);
}
