LINK:https://www.youtube.com/watch?v=9hWUJZuvvMw&list=PLzuyfLB3dZM4w5oUpEGqWgXTkmcZzwiyY&index=13
Check if a given graph is tree or not
Difficulty Level : Medium
Last Updated : 25 Jun, 2021
Write a function that returns true if a given undirected graph is tree and false otherwise. For example, the following graph is a tree.
 
4 5
1 0
2 0
0 3
3 4 

cycleGraph

But the following graph is not a tree. 
5 5
0 4
0 1
1 2
2 3
3 4

cycleGraph

-------------------------
LOGIC
-----------
An undirected graph is tree if it has following properties. 
1) There is no cycle. 
2) The graph is connected.


CODE:
------------
#include<bits/stdc++.h>
using namespace std;
#define MAX 101

vector<int> g[MAX];
int vis[MAX]={0};

bool isCycle(int u,int parent)
{

	vis[u]=1;
	for(auto it:g[u]){
		if(!vis[it]){			//if it has not been visited ,then explore 
			if(isCycle(it,u))
			return true;
		}
		else if(it!=parent)		//if visited ,then check if it is the parent of the current node
			return true;
	}
	return false;
}


void connectedComponents(int u)
{

	vis[u]=1;
	for(auto it:g[u])
	{
		if(!vis[it])
		 connectedComponents(it);
	}
}

bool utitlity(m){

		bool x=isCycle(0,-1);
		if(x) return false;

	memset(vis,0,sizeof(vis));//we need to reset it,since we are visiting it again
	connectedComponents(0);

for(int i=0;i<m;i++)
{
	if(!vis[i])return false;
}


return true;

int main(){

	int n,m;
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if( utility(m))
	cout<<"YES";
	else
	cout<<"NOT";
	return 0;
}