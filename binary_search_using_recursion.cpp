#include<iostream>
using namespace std;
int search(int *arr , int start,int end , int key){
	if(start >= end) return -1;
	int mid = start + end / 2;
	if(arr[mid] == key) return mid;
	if(arr[mid] < key) return search(arr,mid + 1 , end,key);
	if(arr[mid] > key) return search(arr,start , mid - 1 , key);
}
int main(){
	int arr[8] = {1,2,3,4,5,6,7,8};
	cout << search(arr,0,8,5);
	cout << search(arr,0,8,9);
}
