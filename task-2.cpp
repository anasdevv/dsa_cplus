#include<iostream>
using namespace std;
template <typename T>
struct node{
	T val;
	node *next;
	node *prev;
	node(T val){
		this->val = val;
		this->next = NULL;
	}
	node(){
		next = NULL;
	}
};
template <typename U>
class List{ 
	/* double link*/
	node<U> *head;
	node<U> *tail;
	public:
		List(){
			head = NULL;
			tail = NULL;
		}
		List(U val){
			node <U>*temp = new node<U>(val);
			this->head = temp;
			head->prev = NULL;
			tail = head;
			tail->prev = NULL;
			tail->next = NULL;
		}
		void addNode(U val){
			node <U>*temp = new node<U>(val);
			if(head == NULL){
				head = temp;
				tail = head;
				head->prev = NULL;
				head->next = NULL;
				tail->prev = NULL;
				tail->next = NULL;
				return;
			}		
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		void deleteNode(U val){
//			if(head == addr)
			node <U>*temp = head;
			if(head->val == val){
				head = head->next;
				head->prev = NULL;
				delete temp;
				return;
			}
			while(temp != NULL){
				if(temp->val == val){
					break;
				}
				temp = temp->next;
			}
			temp->prev = temp->next;
			delete temp;
		}
		void printAll(){
			node <U>*temp = head;
			while(temp != NULL){
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		node<U> *getHead(){
			return head;
		}
		void addNodes(U arr[],int n){
			for(int i = 0 ; i < n ;i++)
				this->addNode(arr[i]);
		}
};
template <typename K>
class Graph{
	List <K>L[10];
	int index;
	public:
		Graph(){
			index = 0;
		}
		void addEdge(int node,List<K> adjacencyList){
			L[node-1] = adjacencyList;
			index++;
		}
		void printGraph(){
			for(int i = 0 ; i < index ; i++){
				cout << i + 1 << " ->";
				L[i].printAll();
				cout << endl;
			}
		}
};
int main(){
	List <int>L;
	int arr0[] = {1,4};
	int arr1[] = {0,2,3};
	int arr2[] = {1,3};
	int arr3[] = {1,2,4};
	int arr4[] = {0,3};
	L.addNodes(arr0,2);
	List <int>L2;
	List <int>L3;
	List <int>L4;
	List <int>L5;
	L2.addNodes(arr1,3);
	L3.addNodes(arr2,2);
	L4.addNodes(arr3,3);
	L5.addNodes(arr4,2);
	Graph <int>g;
	g.addEdge(1,L);
	g.addEdge(2,L2);
	g.addEdge(3,L3);
	g.addEdge(4,L4);
	g.addEdge(5,L4);
	g.printGraph();
	
}
