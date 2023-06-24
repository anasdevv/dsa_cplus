#include<iostream>
using namespace std;
bool canSum(int target,int *arr,int size){
	if(target == 0) return true;
	if(target < 0) return false;
	for(int i = 0 ; i < size ; i++){
		int rem = target - arr[i];
		if(canSum(rem,arr,size)){
			return true;
		}
	}
	return false;
}
int main(){
	int arr[3] = {1,2,3};
	cout << canSum(6,arr,3);
}
