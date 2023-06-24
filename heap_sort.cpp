#include<iostream>
using namespace std;
class MaxHeap{
	int *arr;
	int count;
	int capacity;
	public:
		MaxHeap(int n,int array[]){
			this->arr = new int[n];
			count = 0;
			capacity = n;
			for(int i = 0 ; i < n ; i++){
				arr[i] = array[i];
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
		void buildHeap(){
			for(int i = ((capacity/2 )- 1)  ; i >= 0 ; i--){
				heapify(i);
			}
		}
		void print(){
			for(int i = 0 ; i < capacity ; i++){
				cout << arr[i] << " ";
			}
		}
};
int main(){
	int arr[5] = {7 , 2, 1, 4,9};
	MaxHeap h(5,arr);
	h.buildHeap();
	h.print();
}
