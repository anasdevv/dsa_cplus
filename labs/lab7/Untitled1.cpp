#include<iostream>
using namespace std;
struct node{
	int val;
	node *next;
	node(){
		val = 0;
		next = NULL;
	}
	node(int val = 0){
		this->next = NULL;
		this->val = val;
	}
};
class LinkedList{
	public:
	node *head;
	node *tail;
	public :
		LinkedList(int val){
			node * temp = new node(val);
			head = tail = temp;
		}
		void push(int val){ /* adding node to the tail */
			node *temp = new node(val);
			this->tail->next = temp;
			this->tail = temp;
			this->tail->next = NULL;
		}
		void unshift(int val){  /* adding node before head */
				node *temp = new node(val);
				temp->next = this->head;
				this->head = temp;
		}
		void printList(){
			node * temp = head;
			while(temp){
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		bool valInList(int val){
			node *temp = head;
			while(temp){
				if(temp->val == val){
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		bool checkHead(int val){
			return (head->val == val);
		}
		bool checkTail(int val){
			return (tail->val == val);
		}
		void insertAfter(int key , int val){
			cout << "here" << endl;
			if(!valInList(key)){
				cout << "Value not found in List" << endl;
				return;
			}
			node *current = head;
			node *prev;
			while(current){
				prev = current;
				current = current->next;
				if(prev->val == key){
					break;
				}
			}
			node *temp = new node(val);
			prev->next = temp;
			temp->next = current;
			if(checkTail(key)){
				this->tail = temp;
			}
		}
		int pop(){  /* deleting the last node */
			node *current = head;
			node *prev;
			while(current->next){
				prev = current;
				current = current->next;
			}
			int val = current->val;
			delete current;
			prev->next = NULL;
			this->tail = prev;
			return val;
		}
		int dequeue(){  /* deleting the first node */
			node *temp = head->next;
			delete head;
			head = temp;
		}
		void remove(int val){
			if(!this->valInList(val)){
				cout << "Value not found" << endl;
				return;
			}
			if(this->checkHead(val)){
				this->dequeue();
				return;
			}
			if(this->checkTail(val)){
				this->pop();
				return;
			}
			node *current = head;
			node *prev; 
			while(current->next){
				if(current->val == val){
					break;
				}
				prev = current;
				current = current->next;
			}
			prev->next = current->next;
			delete current;
		}
		void update(int val,int new_val){
			if(!this->valInList(val)){
				cout << "Can not found value in the List" << endl;
				return;
			}
			node *temp = head;
			while(temp->next){
				if(temp->val)	break;
				temp = temp->next;
			}
			temp->val = new_val;
		}
		node *evenBeforeOdd(){
			node *temp = this->head;
			node *prevTail = this->tail;
			while(temp->next){
			bool flag = true;
				if(temp->val % 2 != 0){
					flag = false;
					int key = temp->val;
					temp = temp->next;
					this->remove(key);
					this->push(key);
				}
				if(flag)
					temp = temp->next;
				if(temp == prevTail) break;	
			}
			
		}
//		void myEvenOdd(){
//			node *temp = head;
//			node *even;
//			while(temp->next){
//				if(temp->val % 2 != 0){
//					break;
//				}
//			}
//			node *even = temp->next
//			while(even->next){
//				if()
//			}
//		}
		void swapAllNodes(){
			node *curr = head;
			node *prev = NULL;
			node *next = head->next;
			this->head = head->next;
			while(curr && next){
				if(prev)
					prev->next = next;
				curr->next = next->next;
				next->next = curr;
				prev = curr;
				curr = curr->next;
				if(curr)
					next = curr->next;
			}
		}
};
void reverseList(node *head){
	if(!head){
		return;
	}
	reverseList(head->next);
	cout << head->val << endl;
}
node * myReverse(node *head){
	node *q = NULL;
	node *r = NULL;
	while(head){
		r = q;
		q = head;
		head = head->next;
		q->next = r;
	}
	return q;
}

int main(){
	LinkedList myList(17);
	myList.push(15);
	myList.push(8);
	myList.push(12);
	myList.push(10);
	myList.push(5);
	myList.push(4);
	myList.push(1);
	myList.push(7);
	myList.push(6);
	myList.printList();
	cout << "\naftet" << endl;
	myList.evenBeforeOdd();
	myList.printList();
	LinkedList list(8);
	list.push(12);
	list.push(10);
	list.push(5);
	list.push(4);
	list.push(1);
	list.push(6);
	cout << endl;
	list.printList();
	cout << "\nafter" << endl;
	list.evenBeforeOdd();
	list.printList();
	return 0;
}
