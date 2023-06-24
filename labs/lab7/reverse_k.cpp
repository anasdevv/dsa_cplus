/* reverse list from given position */
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
void* reverse(node *head,int start , int end){
	int i = 0;
	node *p;
	node *q;
	node *r;
	node *temp = head;
	p = head;
	do{
		i += 1;
		q = p;
		p = p->next;
	}while(i < start);
	 i = 0;
	 temp = head;
	 while(i <= end){
	 	r = temp;
	 	i += 1;
	 	temp = temp->next;
	 }
	 i = 0;
	 int count = end - start;
	while(i <= count){
		if(i == 0){
			q->next = r;
			q = p;
			node *t = p;
			p = p->next;
			t->next = r->next;
		}else{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
		}
		i +=1 ;	
	}
}
int main(){
	node *head = new node(1);
	node *temp = head;
	head->next = new node(2);	
	head = head->next;
	head->next = new node(3);
	head = head->next;	
	head->next = new node(4);
	head = head->next;
	head->next = new node(5);
	head = head->next;	
	head->next = new node(6);
	head = head->next;	
	head->next = new node(7);
		head = head->next;	
	head->next = new node(8);
	reverse(temp,1,4);
	while(temp){
	cout << temp->val << " ";
	temp = temp->next;
	}	
}
