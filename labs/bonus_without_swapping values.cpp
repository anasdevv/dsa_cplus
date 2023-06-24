#include<iostream>
#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
struct node{
	int val;
	node *next;
	node *prev;
	node(int val){
		this->val = val;
		this->next= NULL;
		this->prev = NULL;
	}
	
};
class DoublyLinkedList{
	node *head;
	node *tail;
	void delHead(){
		node *t = head;
		head = head->next;
		head->prev = NULL;
		delete t;
	}
	void delTail(){
		node *t = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete t;
	}
	public:
		DoublyLinkedList(int val){
			node *temp = new node(val);
			this->head = temp;
			this->tail = temp;
		}
		node *getTail(){
			return tail;
		}
		void setHead(node *head){
			this->head = head;
		}
		void setTail(node *tail){
			this->tail = tail;
		}
		node *getHead(){
			return head;
		}
		void push(int val){
			node *temp = new node(val);
			temp->prev = tail;
			this->tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
		void unshift(int val){
			node *temp = new node(val);
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		void insertAt(int val,int pos){
			if(pos == 0){
				this->unshift(val);
				return;
			}
			node *temp = head;
			int counter = 0;
			while(temp->next){
				if (counter == pos)
					break;
				temp = temp->next;
				counter += 1;	
			}
			node *curr = new node(val);
			temp->prev->next = curr;
			curr->prev = temp->prev;
			curr->next = temp;
			temp->prev = curr;
		}
		void printList(){
			node *temp = this->head;
			while(temp){
				cout << temp->val <<  " ";
				temp = temp->next;
			}
		}
		void deleteByVal(int val){
			node *temp = head;
			bool flag;
			if(val == temp->val){
				this->delHead();
				return;
			}
			if(val == this->tail->val){
				this->delTail();
				return;
			}
			while(temp){
				if(temp->val == val){
					flag = true;
					break;
				}
				temp = temp->next;
			}
			if(!flag){
				cout << "Element Not Found" << endl;
				return;
			}
			node *curr = temp;
			temp->prev->next = temp->next; 
			temp->next->prev = temp->prev;
			delete curr;
		}
		void deleteNode(node *curr){
			if(curr == head){
				if(!curr->next){
					delete curr;
					return;
				}
				this->delHead();
				return;
			}
			if(curr==tail){
				this->delTail();
				return;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			return;
			
		}
		void deleteByPos(int pos){
			if(pos == 0){
				node *t = head;
				head = head->next;
				head->prev = NULL;
				delete t;
				return;
			}
			node *temp = head;
			int count = 0;
			while( count < pos){
				count += 1;
				temp = temp->next;
			}
			cout << temp->val << endl;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		void reversePrint(){
			node *temp = tail;
			while(temp){
				cout << temp->val << " ";
				temp = temp->prev;
			}
			cout << endl;
		}
		int numberOfNodes(){
			node *temp = head;
			int count = 1;
			while(1){
				if(!temp->next){
					break;
				}
				if(!temp->next->next){
					count += 1;
					break;
				}
				temp = temp->next->next;
				count += 2;
			}
			return count;
		}
};
node *findSmallestNode(DoublyLinkedList L){
	node *curr = L.getHead();
	if(!curr->next || !curr)
		return curr;
	node *temp = new node(9999999);
	while(curr ){
	if(temp->val > curr->val)
		temp = curr;
	curr = curr->next;		
	}
	cout << endl << endl;
	return temp;
}
DoublyLinkedList sort(DoublyLinkedList list){
	DoublyLinkedList L2(-1);
	node *temp = list.getHead();
	int i = 0;
	int len = list.numberOfNodes();
	while(i < len){
		node *smallest = findSmallestNode(list);
		L2.push(smallest->val);
		list.deleteNode(smallest);
		i += 1;
	}
// 		list.getHead()->val << endl;
	L2.deleteByPos(0);
	return L2;
}
int main(){
	DoublyLinkedList List(8);
	List.push(1);
	List.push(9);
	List.push(7);
	List.push(2);
	List.push(4);
	List.push(10);
	List.printList();
	DoublyLinkedList l2 = sort(List);
	l2.printList();
	
}
