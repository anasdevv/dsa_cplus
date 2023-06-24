#include<iostream>
using namespace std;
int insertAt(int arr[],int start,int end,int key){
	while(end > start){
		int mid = (start + end) / 2;
		if(key > arr[mid])
			start = mid + 1;
		else if(key < arr[mid])
			end = mid;
	}
	return end;
}
void insertionSort(int arr[],int n){
	for(int i = 1; i < n ;i++){
		int idx = insertAt(arr,0,i,arr[i]);
		int key = arr[i];
		int j = i - 1;
		while(j >= idx ){
			arr[j+1] = arr[j];
			j--;
		}
		arr[idx] = key;
	}
}
int main(){
	int arr[] = {5,8,1 ,2 ,9 , 4 , 10,7,6,3};
	insertionSort(arr,10);
	for(int i = 0 ; i < 10 ; i++)
		cout << arr[i] << " ";
}
