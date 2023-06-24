#include<iostream>
#include <cmath>
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
	kv_pair<k,v> *arr;
	protected:
	int size;
	int capacity;
	int virtual hash(int key) = 0;
	int  linearProbing(int index){
		return (index + 1) % capacity;
	}
	public:
	HashMap(){
		 capacity = 10;
		 size = 0;
		this->arr = new kv_pair<k,v>[size];
		for(int i = 0 ; i < 10 ; i++){
			arr[i].key = -1;
			arr[i].val = -1;
		}
	}
	void insert(k key , v val){
		if(!(size < capacity))
			return;
		int index = hash(key);
		while(arr[index].key != -1  && arr[index].key!= key ){
			index = linearProbing(index);
		}
		arr[index].key = key;
		arr[index].val = val;
		size += 1;
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
template <typename k , typename v>
class HashMap_Mod : public HashMap<k,v>{
	float A;
	public:
	HashMap_Multiplication(){};
	int hash(int key){
		return key % HashMap<k,v>::capacity;
	}
};
template <typename k , typename v>
class HashMap_Multiplication : public HashMap<k,v>{
	float A;
	public:
	HashMap_Multiplication(){
		A = 0.357;
	}
	int hash(int key){
		float n = key * A;
		float whole,fractional;
		fractional = std::modf(n, &whole);
		return floor(HashMap<k,v>::capacity * fractional);
	}
};
template <typename k , typename v>
class HashMap_FoldingHash : public HashMap<k,v>{
	public:
	HashMap_FoldingHash(){}
	int hash(int key){
		int temp = key;
		int s = 0;
		while(temp > 0){
			s += temp % 10;
			temp = temp / 10;
		}
		return s % HashMap<k,v>::capacity;
	}
};
template <typename k , typename v>
class HashMap_MidSquareHash : public HashMap<k,v>{
	public:
	HashMap_MidSquareHash(){}
	int hash(int key){
		int temp = key * key;
		temp = temp / 10;
		return temp % 10;
	}
};
int main(){
	HashMap_Multiplication <int,int>map;
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
	cout << endl << endl << "----" << endl;
	HashMap_MidSquareHash <int,int> map2;
	map2.insert(5,55);
	map2.insert(1,67);
	map2.insert(19,69);
	map2.insert(9,27);
	map2.insert(7,47);
	map2.insert(6,12);
	cout << map2.deleteKey(3) << endl;
	cout << map2.searchKey(19) << endl;
	cout << map2.searchKey(9) << endl;
	cout << map2.deleteKey(19) << endl;
//	cout << map.searchKey(19) << endl;
	
}
