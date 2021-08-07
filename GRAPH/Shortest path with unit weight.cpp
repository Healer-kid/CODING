SHORTEST PATH FROM SOURCE TO A PARTICULAR NODE WITH UNIT WEIGHT


USING BFS
-------------------

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int V,e;
	cin>>V>>e;
	vector<int> adj[V+1];
	int u,v;
	for(int i=0;i<e;i++){
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int source,dest;
	cin>>source>>dest;
	
	int dist[V+1];
	for(int i=0;i<=V;i++)
	dist[i]=INT_MAX;
	
	queue<int> q;
	dist[source]=0;
	q.push(source);
	
	while(!q.empty()){
	    int node=q.front();
	    q.pop();
	    
	    for(auto i:adj[node]){
	        
	        if(dist[node]+1<dist[i])
	        {
	            dist[i]=dist[node]+1;
	            q.push(i);
	          
	        }
	        
	    }
	    
	    
	}
	
	if(dist[dest]==INT_MAX)
	cout<<0<<"\n";
	else
	cout<<dist[dest]<<"\n";
	
	
	
	
	
	return 0;
}
