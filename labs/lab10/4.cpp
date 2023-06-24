#include<iostream>
using namespace std;
struct kv_pair{
	int key;
	string val;
	kv_pair * next;
	kv_pair(int key , string val){
		this->key = key;
		this->val = val;
		this->next = NULL;
	}
	kv_pair(){
		next = NULL;
	}
};
class List{
	kv_pair * head; 
	kv_pair * tail;
	public:
		List(){}
		void push_back(int key , string val){
			kv_pair *temp = new kv_pair(key , val);
			if(head == NULL){
				head = temp;
				tail = temp;
				return;
			}
			tail->next = temp;
			tail = temp;
		}
		kv_pair *getHead(){
			return head;
		}
		void deleteNode(kv_pair *prev,kv_pair *curr){
			prev->next = curr->next;
			delete curr;
		}
};
class HashMap{
	List * table;
	int size = 0;
	int capacity;
	public:
		HashMap(){
			size = 0;
			capacity = 10;
			table = new List[capacity];
		}
	int hash(int key){
		return key % capacity;
	}
	bool isEmpty(){
		return (size == 0);
	}
	void insert(int key , string val){
		size += 1;
		int index = hash(key);
		table[index].push_back(key,val);
	}
	void _delete(int key){
		int index = hash(key);
		kv_pair *temp = table[index].getHead();
		if(!temp) return;
		if(!temp->next){
			delete temp;
			temp = NULL;
			size -= 1;
			return;
		}
		kv_pair *prev = NULL;
		while(temp != NULL){
			if(temp->key == key){
				break;
			}
			temp = temp->next;
			prev = temp;
		}
		if(prev == NULL || prev == temp)
			return;
		size -= 1;	
		table[index].deleteNode(prev,temp);
	}
	string searchKey(int key){
		int index = hash(key);
				string s = " ";
		kv_pair *temp = table[index].getHead();
		if(temp == NULL) return s;		
		while(temp != NULL){
			if(temp->key == key){
				return temp->val;
			}
			temp = temp->next;
		}
		return s;
	}
	int getSize(){
		return size;
	}
};
int main(){
	HashMap phonebook;
	phonebook.insert(1,"test");
	phonebook.insert(2,"test");
	phonebook.insert(3,"test");
	phonebook._delete(1);
	cout << phonebook.isEmpty() << endl;
	cout << phonebook.searchKey(2);
	cout << phonebook.getSize() << endl;
}
