#include<iostream>
using namespace std;
void myQuickSort(int arr[],int s,int e){
	if(s >= e)
		return;
	int mid = (s + e) /2;
	int i = s;
	int j = e;
	int pivot = arr[mid];
	while(i <= j){
//		move i pointer towards right until you get a value greater than pivot
		while (arr[i] < pivot)
			i += 1;
//		move j pointer towards left until you get a value smaller than pivot
		while (arr[j] > pivot)
			j -= 1;
		/*if found swap*/
		if( i <= j){
			swap(arr[i],arr[j]);
			i = i +1;
			j = j - 1;
		}	
//		recursive calls by dividing the list into two parts
		myQuickSort(arr,s,j);
		myQuickSort(arr,i,e);
	}
}
int main(){
	 int arr[] = {18 , 2 , 3 ,9 , 6 ,55 ,12 ,13 , 99};
	 int size = sizeof(arr)/sizeof(int);
	 myQuickSort(arr,0,size-1);
	 for(int i = 0; i < size ; i++)
	 	cout << arr[i] << " ";
} 
