#include <iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};
class Queue{
	Node* head , * tail;
	public:
		Queue(){
			head = tail = NULL;
		}
		void addMember(int x){
			Node *newNode = new Node(x);
			if(head == NULL){
				head = newNode;
				tail = newNode;
				return;
			}
			tail->next = newNode;
			tail = newNode;
		}
		void removeMember(){
			if(head == tail){
				cout << "Empty "<<endl;
				return;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		void print(){
			Node * temp = head;
			while(temp!=NULL){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};
int main(){
	Queue q;
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	for(int i = 0 ; i < 10 ; i++){
		q.addMember(array[i]);
	}
	q.print();
}
