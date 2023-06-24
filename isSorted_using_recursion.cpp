#include<iostream>
using namespace std;
bool isSorted(int *arr,int len , int i = 0){
	if(i == len - 1) return true;
	return arr[i] < arr[i+1] && isSorted(arr,len,i+1);
}
int main(){
	int arr[5] = {1,2,3,4,5};
	cout << isSorted(arr,5);
}
