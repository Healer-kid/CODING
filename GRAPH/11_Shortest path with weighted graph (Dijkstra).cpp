
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> dis(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	dis[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		
		int dist=pq.top().first;
		int u=pq.top().second;

		for(auto x:adj[u]){----------------------- //since this is adj list (first->source node,second->weight)

			
				v=x.first;
				dist1=x.second;
				if(dis[v]>dis[u]+dist1)
				{
					dis[v]=dis[u]+dist1;
					pq.push(make_pair(dis[v],v));
				}

		}
		
	}
	
	
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}










