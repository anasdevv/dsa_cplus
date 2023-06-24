#include<iostream>
using namespace std;
class Heap{
	public:
	int *arr;
	int count;
	int capacity;
		Heap(int n){
			count = 0;
			this->capacity = n;
			this->arr = new int[n];
			for(int i = 0 ; i < n ; i++)
				this->arr[i] = -1;
		}
		void siftUp(int val,int &i){
			while(i > 0 && val > arr[(i-1)/2]){
				arr[i] = arr[(i-1)/2];
				i = (i-1) / 2;
			}
		}
		void siftDown(int i){
			int left , right , max;
			left = (2 * i) + 1;
			right = (2 * i) + 2;
			if(left < count && arr[i] < arr[left])
				max = left;
			else 
				max = i;
			if(right < count && arr[max] < arr[right])
				max = right;
			if(max != i){
				swap(arr[max],arr[i]);
				siftDown(max);
			}	
		
	}
		int leftChild(int i){
			return (2 * i )+ 1;
		}
		int rightChild(int i){
			return (2 * i )+ 2;
		}
	void heapify(int i){
			int left , right , max;
			left = leftChild(i);
			right = rightChild(i);
			if(left < count && arr[left ] > arr[i])
				max = left;
			else
				max = i;
			if(right < count && arr[right] > arr[max])
				max = right;
			if(i != max){
 				swap(arr[i],arr[max]);
				heapify(max);
			}
		}
		void heapify(){
			for(int i = (capacity/2); i>=0 ; i--){
				this->heapify(i);
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
				cout << arr[i] << " ";
			}    
			cout << endl;
		}
};
bool isHeap(int *arr,int n){
	for(int i = 0 ; i < n - 2 ; i++){
		int left = (2*i) + 1;
		int right = (2*i) + 2;
//		if(left >= n || right >= n)
//			return false;
		if((left < n && arr[i] < arr[left]) || ( right < n && arr[i] < arr[right]))
			return false;
	}
	return true;
}
int main(){
	Heap h(8);
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(4);
	h.insert(5);
//	h.insert(6);
	h.insert(7);
	h.insert(8);
	h.insert(9);
	h.heapify();
	h.print();
//
//	for(int i = 0 ; i < 8 ; i++){
//		cout << h.Delete() << " ";
//	}
	cout << isHeap(h.arr,h.capacity);
	return 0;
}
