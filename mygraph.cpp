#include<iostream>
#include<bits/stdc++.h>
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
struct Edge{
	int src;
	int dest;
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
				cout << temp->val << " -> " << flush;
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
	int numOfVertices;
	bool *visited;
	public:
	List *L;
	Graph(Edge edges[],int numOfEdges,int numOfVertices){
		this->numOfVertices = numOfVertices;
		visited = new bool[numOfVertices];
		L = new List[numOfVertices];
		for(int i = 0 ; i < numOfEdges;i++){
			int src = edges[i].src;
			int dest = edges[i].dest;
			L[src].addNode(dest);
			L[dest].addNode(src);
		}
	}
	void print(){
		for(int i = 0 ; i < numOfVertices ; i++){
			cout << i + 1 << " -> ";
			L[i].printAll();
			cout << endl;
		}
	}
	void _bfs(List *L,bool visited[],List &ans,int n){
		queue<int> q;
		q.push(n);
		visited[n] = 1;
		while(!q.empty()){
			int frontNode = q.front();
			q.pop();
			ans.addNode(frontNode);
			int i = 0;
			node * temp = L[frontNode].getHead();
			while(temp->next != NULL){
				if(!visited[i++]){
					q.push(i);
					visited[i] = 1;
				}
				temp = temp->next;
			}
		}
	}
	void bfs(){
		List ans;
		for(int i = 0 ; i < numOfVertices ; i++){
			if(!visited[i]){
				_bfs(L,visited,ans,i);
			}
		}
		ans.printAll();
	}
	void _dfs(List *L , bool visited[],int n,List &ans){
		ans.addNode(n);
		visited[n] = 1;
		node *temp = L[n].getHead();
		int i = 0;
		while(temp->next != NULL){
			if(!visited[i++]){
				_dfs(L,visited,i,ans);
			}
			temp = temp->next;
		}
	}
	void dfs(){
		for(int i = 0; i < numOfVertices;i++){
			if(!visited[i]){
				List comp;
				_dfs(L,visited,i,comp);
				comp.printAll();
			}
		}
	}
};
int main(){
		Edge edges[] =
	{
		{0, 1}, {0, 2} ,{0,3}, // Node 0 is connected to Node 1 and 4
		{1, 4}, // Node 1 is connected to Node 3 and 2
		{2, 3},			// Node 2 is connected to Node 3
		{3, 4}, // Node 3 is connected to Node 0 and 4
			// Node 4 is connected to Node 1
	};

	int num_of_edges = sizeof(edges) / sizeof(edges[0]);	// Calculating # of elements in edges array
	int num_of_vertices = 5;								// # of vertices in our graph

	Graph g1(edges, num_of_edges, num_of_vertices);	
	g1.print();
//	g1.bfs();
	g1.dfs();
}
