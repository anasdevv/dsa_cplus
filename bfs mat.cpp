#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	
};
vector<vector<int>> mat = {
      {4, 4, 6, 5, 5, 1, 1, 1, 7, 4},
      {3, 6, 2, 4, 6, 5, 7, 2, 6, 6},
      {1, 3, 6, 1, 1, 1, 7, 1, 4, 5},
      {7, 5, 6, 3, 1, 3, 3, 1, 1, 7},
      {3, 4, 6, 4, 7, 2, 6, 5, 4, 4},
      {3, 2, 5, 1, 2, 5, 1, 2, 3, 4},
      {4, 2, 2, 2, 5, 2, 3, 7, 7, 3},
      {7, 2, 4, 3, 5, 2, 2, 3, 6, 3},
      {5, 1, 4, 2, 6, 4, 6, 7, 3, 7},
      {1, 4, 1, 7, 5, 3, 6, 5, 3, 4}};
void bfs(int start = 0){
	vector<bool> visited(10,false);
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		int front = q.front();
		cout << front << " ";
		q.pop();
		for(int i = 0 ; i < mat[front].size() ; i++){
			if(mat[front][i] != visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main(){
 	bfs();
}
