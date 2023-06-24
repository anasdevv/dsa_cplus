#include<iostream>
using namespace std;
template <class T>
bool checkPalindrome(T *array,int n);
template <class T>
T copyAndSum(T *arr ,int n);
template <class T>
class Test{
	int n;
	T array[100];
	public:
		void getInput(){
			cout << "Enter size of array : " << endl;
			cin >> n;
			cout << "Enter Elements : " << endl;
			for(int i = 0 ; i < n ; i++){
				cout << "At position " << i << " : ";
				cin >> array[i];
			}
		}
		void checkPal(){
			if(checkPalindrome<T>(array,n)){
				cout << "The Given Array is palindrome !" << endl;
			}
			else{
				cout << "The Given array is not palindorme !" << endl;
			}
		}
		void getSum(){
			cout << "Sum is : " << copyAndSum<T>(array ,n) << endl;
 	}	
		
};
template <class T>
bool checkPalindrome(T *arr,int n){
	int t = n - 1;
	bool flag = true;
	for(int i = 0 ; i < n; i++,t--){
		if(arr[i] != arr[t]){
			flag = false;
			break;
		}
		}
	return flag;
}
template <class T>
T copyAndSum(T *arr ,int n){
	T temp[n];
	T sum;
	for(int i = 0 ; i < n ; i++){
		temp[i] = arr[i];
		sum += arr[i];
	}
	return sum;
}
int main(){
	Test <int>a;	
	a.getInput();
	a.checkPal();
	a.getSum();
}
