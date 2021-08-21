Topological sort 
Medium Accuracy: 40.0% Submissions: 66765 Points: 4
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:


Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 2, 1, 3, 4, 0.



class Solution
{
	public:
	
	void dfs(stack<int> &s,vector<int> &vis,int i,vector<int> adj[]){
	    
	    vis[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	        dfs(s,vis,i,adj);
	        
	    }
	    
	    s.push(i);
	    
	    
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        
	        if(!vis[i]){
	            dfs(s,vis,i,adj);
	        }
	        
	        
	    }
	    vector<int> v;
	    while(!s.empty()){
	        
	        v.push_back(s.top());
	        s.pop();
	        
	    }
	   return v; 
	    
	    
	}
};
