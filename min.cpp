#include<iostream>
using namespace std;
class Heap{
	int *arr;
	int count;
	int capacity;
	public:
		Heap(int n){
			count = 0;
			this->capacity = n;
			this->arr = new int[n];
			for(int i = 0 ; i < n ; i++)
				this->arr[i] = -1;
		}
		void siftUp(int val,int &i){
			while(i > 0 && val < arr[(i-1)/2]){
				arr[i] = arr[(i-1)/2];
				i = (i-1) / 2;
			}
		}
		void siftDown(int i){
			int left , right , min;
			left = (2 * i) + 1;
			right = (2 * i) + 2;
			if(left < count && arr[i] > arr[left])
				min = left;
			else 
				min = i;
			if(right < count && arr[min] > arr[right])
				min = right;
			if(min != i){
				swap(arr[min],arr[i]);
				siftDown(min);
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
		void print(){
			for(int i = 0 ; i < capacity ; i++){
				cout << Delete() << " ";
			}    
		}
};
int main(){
	Heap h(5);
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(4);
	h.insert(5);

	for(int i = 0 ; i < 5 ; i++){
		cout << h.Delete() << " ";
	} 
	return 0;
}
