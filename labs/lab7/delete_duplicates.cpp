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
 node* deleteDuplicates(node* head) {
        if(head == NULL){
            return head;
        }
        node *temp = head;
        while(temp->next){
            if(temp->val == temp->next->val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return head;
}
int main(){
	node *head = new node(1);
	node *temp = head;
	head->next = new node(1);	
	head = head->next;
	head->next = new node(1);
	head = head->next;	
	head->next = new node(4);
	head = head->next;
	head->next = new node(5);
	head = head->next;	
	head->next = new node(6);
	head = head->next;	
	head->next = new node(7);
	temp = deleteDuplicates(temp);
	while(temp){
	cout << temp->val << " ";
	temp = temp->next;
	}	
}
