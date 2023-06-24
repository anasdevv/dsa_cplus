#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
	int mid = (s +e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	int temp[e+1];
	while( i <= mid && j <= e){
		if(arr[i] > arr[j])
			temp[k++] = arr[j++];
		else
			temp[k++] = arr[i++];
	}
	while( i <= mid)
		temp[k++] = arr[i++];
	while(j<=e)
		temp[k++] = arr[j++];
	for(int i = s ; i <= e ; i++)
		arr[i] = temp[i];
}
void mergeSort(int arr[],int s,int e){
	if(s >= e)	return;
	
	int mid = (s + e) / 2;
	mergeSort(arr,s,mid-1);
	mergeSort(arr,mid+1,e);
	merge(arr,s,e);
}
int main(){
	 int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
    mergeSort(A,0,n-1);
    for(int i = 0 ; i < n ; i++)
    	cout << A[i] << " ";
}
