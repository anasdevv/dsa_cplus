#include<iostream>
using namespace std;
struct node{
	int val;
	node * next;
};
class LinkedList{
	node *head;
	node *last;
	public:
		LinkList(){
			head = last = NULL;
		}
		LinkedList(int val){
			head = new node;
			head->val = val;
			head->next = NULL;
			last = head;
		}
		void push(int val){
			node *temp = new node;
			temp->val = val;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
		int countNodes(){
			int count = 0;
			node *temp = head;
			while(temp){
				count++;
				temp = temp->next;
			}
			return count;
		}
		int sum(){
			int sum = 0;
			node *temp = head;
			while(temp){
				sum += temp->val;
				temp = temp->next;
			}
			return sum;
		}
		void display(){
			node *temp = head;
			while(temp){
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		void insertAt(int index,int val){
			if(index == 0){
				node * temp = new node;
				temp->val = val;
				temp->next = head;
				head = temp;
				return;
			}
			int nodes = this->countNodes();
			if(index >= nodes + 1 ){ /* to be inserted at last */
			this->push(val);
			return;
			}
			node *current = head;
			node *prev = NULL;
			int count = 0;
			while(current){
				count++;
				if(count == index){
					node * temp = new node;
					temp->val = val;
					temp->next = current;
					prev->next = temp;
					return;
				}
				prev = current;
				current = current->next;
			}
		}
		void displayReverse(){
			static node * temp = this->head;
			if(temp == NULL) return;
			temp = temp->next;
			displayReverse();
			cout << temp->val << " ";
		}
		void deleteByVal(int val){
			node *current = head;
			node *prev = NULL;
			while(current){
				if(current->val == val) break;
				prev = current;
				current = current->next;
			}
			prev->next = current->next;
		}
		void pop(){
			node *current = head;
			node *prev;
			while(current){
				prev = current;
				current = current->next;
			}
			prev->next = NULL;
			last = prev;
		}
		reverseList(){
			node *current = head,*prev1,*prev2;
			prev1 = prev2 = NULL;
			while(current){
				prev2 = prev1;
				prev1 = current;
				current = current->next;
				prev1->next = prev2;
			}
			last = head;
			head = prev1;
		}
		 ~LinkedList(){
			delete(head);
			delete(last);
		}
};	
 
int main(){
	LinkedList list(12);
	list.push(5);
	list.push(6);
	list.push(9);
	list.insertAt(0,11);
	list.insertAt(2,-6);
	cout << "Number of Nodes : " << list.countNodes() << endl;
	list.display();
	list.reverseList();
//	list.deleteByVal(-6);
	cout << "\nAfter Reversing " << endl;
	list.display();
	LinkedList l;
//	cout << "Reverse" << endl;
//	list.displayReverse();
	return 0;
}
