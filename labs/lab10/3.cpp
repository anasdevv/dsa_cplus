#include<iostream>
#include<fstream>
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
	int capacity;
	int size;
	kv_pair<k,v> *arr;
	int hash(int key){
		return key % capacity;
	}
	int linearProbing(int index){
		return (index + 1) % capacity;
	}
	public:
	HashMap(){
		capacity = 10;
		 size = 0;
		this->arr = new kv_pair<k,v>[capacity];
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
		size += 1;
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
				size -= 1;
				return temp;
			}
			index = linearProbing(index);
		}
		return -1;
	}
	bool isEmpty(){
		return size == 0;
	}
	int getSize(){
		return size;
	}
};
int main(){
	HashMap<int,int> phonebook;
	char input;
	int st_id, st_no;
	while(1){
	string myText;
	ifstream MyReadFile("a.txt");
	while (getline (MyReadFile, myText)) {
	  cout << myText << endl;
	}
	MyReadFile.close();
	cin >> input;
	switch(input){
		case '1':
			if(phonebook.isEmpty())
				cout << "Phonebook is empty" << endl;
			else
				cout << "Phonebook is not empty" << endl;
			
		break;
		case '2':
			cout << "Size of phonebook is " << phonebook.getSize() << endl;
		break;
		case '3':
			cout << "Enter Student ID : ";;
			cin >> st_id;
			cout << phonebook.searchKey(st_id) << endl;
		break;
		case '4':
			cout << "enter student id  :";
			cin >> st_id;
			cout << "enter student phone number :";
			cin >> st_no;
			phonebook.insert(st_id,st_no);
			cout << "student added!" << endl;
		break;
		case '5':
			cout << "Enter Student ID : ";;
			cin >> st_id;
			cout << phonebook.deleteKey(st_id) << endl;
		break;
		case '6':
			return 0;
		break;	
	}
	}
		
}
