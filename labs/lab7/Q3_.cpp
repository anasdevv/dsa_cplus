/* remove zero sum consecutive nodes */
#include<iostream>
#include<string>
#include<cstring>
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
string reverse(string s){
	string str = "";
	for(char c : s){
		str += c;
	}
	return str;
}
node *addOne(node *head){
	node *temp = head;
	string s = "";
	while(temp){
		s += to_string(temp->val);
		temp = temp->next;	
	}
	int x = stoi(s);
	x += 1;
	s = to_string(x);
	node *temp2 = head;
	int len = s.length();
	int i = 0;
	while(i < len && temp2){
		temp2->val = int(s[i] - '0');
		i += 1;
		temp2 = temp2->next;
	}
	return head;
}
int main(){
	node *head = new node(1);
	node *temp = head;
	head->next = new node(9);	
	head = head->next;
	head->next = new node(9);
	head = head->next;	
	head->next = new node(9);
	head = head->next;		
	temp = addOne(temp);
		while(temp){
		cout << temp->val << endl;
		temp = temp->next;
	}
}
