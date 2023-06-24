#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insertAtSortedPos(stack<int>&s,int x){
	if(s.empty() || s.top() > x){
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	insertAtSortedPos(s,x);
	s.push(y);
}
void sortStack(stack<int> &s){
	if(s.empty())
		return;
	int x = s.top();
	s.pop();
	sortStack(s);
	insertAtSortedPos(s,x);
}
int main(){
	stack<int> s;
	s.push(5);
	s.push(1);
	s.push(3);
	s.push(10);
	s.push(9);
	sortStack(s);
	for(int i = 0 ; i < 5 ; i++){
		cout << s.top() << " ";
		s.pop();
	}
}
