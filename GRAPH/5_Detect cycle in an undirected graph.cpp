Detect cycle in an undirected graph 
Medium Accuracy: 35.66% Submissions: 100k+ Points: 4
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105

class Solution 
{
    public:
    bool dfs(vector<int> &vis,vector<int> adj[],int i,int parent){
        vis[i]=1;
        
        for(auto x:adj[i])
        {
            if(vis[x]==0)
            {
                if(dfs(vis,adj,x,i))
                return true;
            }else{
                
                if(x==i or x!=parent)  //checking self loop and not its parent,if so then there is a loop
                 return true;
                
            }
            
            
        }
        
      return false;  
        
        
    }
    
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	        if(dfs(vis,adj,i,-1))
	        return true;
	    }
	    return false;
	    
	    
	}
};
