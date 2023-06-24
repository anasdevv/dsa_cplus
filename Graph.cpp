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
		void deleteNode(int val){
//			if(head == addr)
			node *temp = head;
			if(head->val == val){
				head = head->next;
				delete temp;
				return;
			}
			node *prev = NULL;
			while(temp != NULL){
				if(temp->val == val){
					break;
				}
				prev = temp;
				temp = temp->next;
			}
			cout << prev->val << endl;
			prev->next = temp->next;
			delete temp;
		}
		void printAll(){
			node * temp = head;
			while(temp != NULL){
				cout << temp->val << " ";
				temp = temp->next;
			}
		}
		node *getHead(){
			return head;
		}
		void addNodes(int arr[],int n){
			for(int i = 0 ; i < n ;i++)
				this->addNode(arr[i]);
		}
};
class Graph{
	List L[10];
	int index;
	public:
		Graph(){
			index = 0;
		}
		void addEdge(int node,List adjacencyList){
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
	List L;
	int arr0[] = {1,4};
	int arr1[] = {0,2,3};
	int arr2[] = {1,3};
	int arr3[] = {1,2,4};
	int arr4[] = {0,3};
	L.addNodes(arr0,2);
	List L2;
	List L3;
	List L4;
	List L5;
	L2.addNodes(arr1,3);
	L3.addNodes(arr2,2);
	L4.addNodes(arr3,3);
	L5.addNodes(arr4,2);
	Graph g;
	g.addEdge(1,L);
	g.addEdge(2,L2);
	g.addEdge(3,L3);
	g.addEdge(4,L4);
	g.addEdge(5,L4);
	g.printGraph();
	
}
