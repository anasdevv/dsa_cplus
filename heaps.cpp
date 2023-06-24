#include<iostream>
using namespace std;
class Heap{
	int *arr;
	int cap;
	int count;
	public:
		Heap(int n){
			this->arr = new int[n];
			this->cap = n;
			count = 0;
		}
		int siftUp(int val,int i){
			while(i > 0 && val > arr[(i-1)/2]){
				arr[i] = arr[(i-1)/2];
				i = (i-1)/2;
			}
			return i;
		}
		void siftDown(int i = 0){
			int left = 2*i + 1;
			int right = 2*i + 2;
			int max;
			if(left < count && arr[left] > arr[i])
				max = left;
			else
				max = i;
			if(right < count && arr[right] > arr[max])
				max = right;
			if(max != i){
				swap(arr[i],arr[max]);
				siftDown(max);
			}		
		}	
		int delete_(){
			int data = arr[0];
			arr[0] = arr[count-1];
			count -= 1;
			siftDown();
			return data;
		}
		void insert(int val){
			int i = count ;
			count += 1;
			if(count > count){
				count--;
				return;
			}
			int idx = siftUp(val,i);
			arr[idx] = val;
		}
		void print(){
			for(int i = 0 ; i < count ; i++){
				cout << arr[i] << " ";
			}
		}
	
};
int main(){
	Heap h(5);
	h.insert(2);
	h.insert(3);
	h.insert(4);
	cout << h.delete_();
	cout << h.delete_();
	cout << h.delete_();
//	h.print();
}
