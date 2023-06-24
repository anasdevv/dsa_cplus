#include<iostream>
using namespace std;
template <class T>
class Node{
	public:
	T data;
	Node* next,*prev;
	Node(T data){
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};
template <class T>
class Stack{
	Node<T> * head ,*tail;
	public:
		Stack(){
			head = NULL;
			tail = NULL;
		}
		bool isEmpty(){
			if(head == NULL)
				return true;
			return false;
		}
		void push(T val){
			Node<T> * newNode = new Node<T>(val);
			if(head == NULL){
				head = newNode;
				tail = head;
				return ;
			}
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
			
		}
		T top(){
			if(isEmpty()){
				return -1;
			}
			return tail->data;
		}
		void pop(){
			if(isEmpty()){
				return;
			}
			if(head == tail){
				Node<T> *t = head;
				head = NULL;
				tail = NULL;
				delete t;
				return;
			}
			Node<T>* t = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete t;
		}
};
void print(Stack<int> st){
	if(st.isEmpty())
		return;
	while(!st.isEmpty()){
		cout << st.top() << " ";
		st.pop();
	}
}
int main(){
	Stack<int> stk;
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	for(int i = 0 ; i < 10 ; i++){
		stk.push(array[i]);
	}
	print(stk);
	return 0;
}
