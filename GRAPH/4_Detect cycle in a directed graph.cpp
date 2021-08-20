Detect cycle in a directed graph 
Medium Accuracy: 30.19% Submissions: 100k+ Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105







class Solution
{
    public:
    bool dfs(vector<int> &vis,vector<int> &anc, int i,vector<int> adj[]){
        
        vis[i]=1;
        anc[i]=1;
        for(auto x:adj[i]){
            
            if(vis[x]==0)
            {
                if(dfs(vis,anc,x,adj))
                return true;
            }else{
                
                if(anc[x]==1)
                return true;
                
            }
            
        }
        anc[i]=0; //BACKTRACK
       return false; 
        
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> vis(V,0);
	   	vector<int> anc(V,0);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(vis[i]!=1)
	   	    {
	   	        if(dfs(vis,anc,i,adj))
	   	        return true;
	   	    }
	   	    
	   	}
	   	
	   	return false;
	}
};
