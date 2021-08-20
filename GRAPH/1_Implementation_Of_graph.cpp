LINK:https://www.youtube.com/watch?v=xbTpKgKtddo&list=PLzuyfLB3dZM4w5oUpEGqWgXTkmcZzwiyY&index=3




#include<bits/stdc++.h>
using namespace std;
#define MAX 101

vector<int> g[MAX]; //columns are dynamic and rows are static (2d array)
int vis[MAX][MAX]={0};

void printgraph(int V)
{
    for(int i=0;i<V;i++)
    {
        for(auto it:g[i])
        {
          if(vis[it][i] or vis[i][it]) //since we dont want to print it two times
          continue;
          cout<<i<<" "<<it<<"\n";
          vis[it][i]=1;
          vis[i][it]=1;
        }
        
    }
}
void addEdge(int u,int v)
{
        g[u].push_back(v);
		g[v].push_back(u);
}
int main(){

	addEdge(0,1);
	addEdge(1,2);
	addEdge(3,4);
	addEdge(2,3);
	addEdge(4,1);
    printgraph(5);
}