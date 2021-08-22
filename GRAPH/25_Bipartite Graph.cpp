Bipartite Graph 
Medium Accuracy: 40.1% Submissions: 43935 Points: 4
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105



bool solve(vector<int> &vis,vector<int>adj[],int cr,int i){
    
    vis[i]=cr;
  
    for(auto x:adj[i])
    {
        if(vis[x]==-1){
           
            if(!solve(vis,adj,1-cr,x))
            
            return false;
            
        }else{
            if(vis[x]==vis[i])
            return false;
        }
        
    }
    
    return true;
    
    
    
}


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	  vector<int> vis(V,-1);
	   
	   int cr=0;
	  
	   for(int i=0;i<V;i++)
	       
	   {  if(vis[i]==-1)
	       if(!solve(vis,adj,cr,i))
	        return false;
	   }
	   
	   return true;
	   
	}

};