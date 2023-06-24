/* remove zero sum consecutive nodes */
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
node *checkZeroSum(node *head,bool flag = false){
	if(head == NULL)
		return head;
	node *temp = head;
	int sum = 0;
	while(temp){
		sum += temp->val;
		if(sum == 0)
			break;
		temp = temp->next;
	}
	if(sum == 0){
		flag = true;
		return temp->next;
	}
	head->next = checkZeroSum(head->next,flag);
	return head;
}
node *removeZeroSum(node *head){
	node *temp = head;
	while(temp)
	{
		bool flag = false;
		temp = checkZeroSum(temp,flag);
		if(temp == NULL || !flag)
			break;
	}
	return temp;
}
 
int main(){
	node *head = new node(1);
	node *temp = head;
	head->next = new node(2);	
	head = head->next;
	head->next = new node(-3);
	head = head->next;	
	head->next = new node(3);
	head = head->next;	
	head->next = new node(1);
	head = head->next;	
	temp = removeZeroSum(temp);
		while(temp){
		cout << temp->val << endl;
		temp = temp->next;
	}
}
