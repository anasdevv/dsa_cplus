#include<iostream>
#include<vector>
#include<bits/stdc++.h>
vector<int> shortestPath(vector<vector<int>> edges,int n,int s,int e){
	unordered_map<int,list<int>> adj;
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
//	adj list
	for(int i = 0 ; i < n ; i++){
		int src = edges[i][0];
		int dest = edges[i][1];
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
//	bfs
	queue<int> q;
	parent[s] = -1;
	visited[s] = true;
	q.push(s);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto i : adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}
//	prepare shortest path
	vector<int> ans;
	int currentNode = e;
	ans.push_back(e);
	while(s != currentNode){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	return ans;
}
