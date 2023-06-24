#include<iostream>
using namespace std;
template <typename k , typename v>
struct kv_pair{
	k key;
	v val;
	pair(k key , v val){
		this->key = key;
		this->val = val;
	}
};
template <typename k , typename v>
class HashMap{
	int size;
	kv_pair<k,v> *arr;
	int hash(int key){
		return key % size;
	}
	int linearProbing(int index){
		return (index + 1) % size;
	}
	public:
	HashMap(){
		 size = 10;
		this->arr = new kv_pair<k,v>[size];
		for(int i = 0 ; i < 10 ; i++){
			arr[i].key = -1;
			arr[i].val = -1;
		}
	}
	void insert(k key , v val){
		int index = hash(key);
		while(arr[index].key != -1  && arr[index].key!= key ){
			index = linearProbing(index);
		}
		arr[index].key = key;
		arr[index].val = val;
	}
	v searchKey(k key){
		int index = hash(key);
		while(arr[index].key != -1){
			if(arr[index].key == key){
				return arr[index].val;
			}
			index = linearProbing(index);
		}
		return -1;
	}
	v deleteKey(k key){
		int index = hash(key);
		while(arr[index].key != -1 ){
			if(arr[index].key == key){
				v temp = arr[index].val;
				arr[index].key = -1;
				arr[index].val = -1;
				return temp;
			}
			index = linearProbing(index);
		}
		return -1;
	}
};
int main(){
	HashMap <int,int>map;
	map.insert(5,55);
	map.insert(1,67);
	map.insert(19,69);
	map.insert(9,27);
	map.insert(7,47);
	map.insert(6,12);
	cout << map.deleteKey(3) << endl;
	cout << map.searchKey(19) << endl;
	cout << map.searchKey(9) << endl;
	cout << map.deleteKey(19) << endl;

//	cout << map.searchKey(19) << endl;
	
}
