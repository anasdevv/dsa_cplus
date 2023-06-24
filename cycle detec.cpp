#include<iostream>
using namespace std;
struct node{
	int val;
	node *next;
		node(int val){
		this->val = val;
		this->next = NULL;
	}
	node(){
		next = NULL;
	}
};
class List{
	node *head;
	node *tail;
	public:
		List(){
			head = NULL;
			tail = NULL;
		}
		List(int val){
			node *temp = new node(val);
			this->head = temp;
			tail = head;
		}
		void addNode(int val){
			node *temp = new node(val);
			if(head == NULL){
				head = temp;
				tail = head;
				return;
			}		
			tail->next = temp;
			tail = temp;
		}
		node *getHead(){
			return head;
		}
		void addNodes(int arr[],int n){
			for(int i = 0 ; i < n ;i++)
				this->addNode(arr[i]);
		}
};
node *_del_(node *head1,node *head2){
	node *temp1 = head1;
	node *prev = NULL;
	while(temp1 && temp1->next){
		node *temp2 = head2;
		bool flag = true;
		while(temp2->next){
			if(temp1->val == temp2->val){
				if(prev == NULL){ /* head to be deleted */
					node *dd = temp1;
					temp1 = temp1->next;
					head1 = temp1;
					delete dd;
				}
				else{
					prev->next = temp1->next;
					node *d = temp1;
					temp1 = temp1->next;
					delete d;
				}
//				flag = false;
			}
			temp2 = temp2->next;
		}
			prev = temp1;
			temp1 = temp1->next;
	}
	return head1;
}
int main(){
	List L1;
	List L2;
	int arr1[] = {1,3,5,7,8,9,10,12};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {1,2,5,6,18,9,10,12};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	L1.addNodes(arr1,n1);
	L2.addNodes(arr2,n2);
	node * temp = _del_(L1.getHead(),L2.getHead());
	while(temp != NULL){
		cout << temp->val << " ";
		temp = temp->next;
	}
}
