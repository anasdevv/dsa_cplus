#include<iostream>
using namespace std;
class Min_Heap{
	int *arr;
	int count;
	int capacity;
	public:
		Min_Heap(int n){
			count = 0;
			this->capacity = n;
			this->arr = new int[n];
			for(int i = 0 ; i < n ; i++)
				this->arr[i] = -1;
		}
		void siftUp(int val,int &i){
			while(i > 0 && val < arr[(i-1)/2]){
				arr[i] = arr[(i-1)/2];
				i = (i-1 )/ 2;
			}
		}
		void siftDown(int i){
			int left , right , max;
			left = (2 * i) + 1;
			right = (2 * i) + 2;
			if(left < count && arr[i] > arr[left])
				max = left;
			else 
				max = i;
			if(right < count && arr[max] > arr[right])
				max = right;
			if(max != i){
				swap(arr[max],arr[i]);
				siftDown(max);
			}	
		
	}
		void insert(int val){
			count++;
			int i = count - 1;
			if(count > capacity){
				count --;
				return;
			}
			siftUp(val,i);
			arr[i] = val;
		}
		int Delete(){
			int data;
			if(count == 0)
				return -1;
			data = arr[0];
			arr[0] = arr[count-1];
			count -= 1;
			siftDown(0);
			return data;
		}
		void sort_(){
			for(int i = 0 ; i < capacity ; i++){
					cout << Delete() << " ";
			}    
		}
};
int main(){ 
	int arr[] = {35 ,33 ,42 ,10 ,14 ,19, 27, 44 ,26 ,31};
	Min_Heap h(15); // capacity 10
	for(int i = 0 ; i < 10 ; i++){
		h.insert(arr[i]);
	}
	h.sort_();
}
