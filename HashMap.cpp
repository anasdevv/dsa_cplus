#include<iostream>
using namespace std;
class HashMap{
	int key;
	int val;
	int size;
	int *arr;
	public:
	HashMap(){
		 size = 10;
		this->arr = new int[size];
		for(int i = 0 ; i < 10 ; i++){
			arr[i] = -1;
		}
	}
	void insert(int key , int val){
		int index = key % size;
		while(arr[index] != -1){
			index = (index + 1) % size;
		}
		arr[index] = val;
	}
	int searchKey(int key){
		int index = key % size;
		while(index != key){
			index = (index + 1)  % size;
		}
		return arr[index];
	}
};
int main(){
	HashMap map;
	map.insert(5,55);
	map.insert(1,67);
	map.insert(2,67);
	map.insert(3,67);
	cout << map.searchKey(1);
}
