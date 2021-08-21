
Strongly Connected Components (Kosaraju's Algo) 
Medium Accuracy: 49.73% Submissions: 29660 Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106















class Solution
{
	public:
	void dfs(vector<int> adj[],vector<int> &vis,int i,stack<int> &s)
	{
	    vis[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	        dfs(adj,vis,x,s);
	        
	    }
	    
	    s.push(i);
	    
	    
	    
	    
	}
void dfs1(vector<int> adj1[],int i,vector<int> &vis){
    
    
     vis[i]=1;
	    for(auto x:adj1[i])
	    {
	        if(!vis[x])
	        dfs1(adj1,x,vis);
	        
	    }
    
    
}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(adj,vis,i,s);
            
        }
        
       vector<int> adj1[V];
       
       for(int i=0;i<V;i++){
           
           for(auto x:adj[i]){
               
               adj1[x].push_back(i);
           }
           
           
       }
       int count=0;
      
      for(int i=0;i<V;i++)
      vis[i]=0;
     
      
      while(!s.empty()){
          
         int i=s.top();
         s.pop();
         
        
             if(!vis[i]){
                  count++;
                 dfs1(adj1,i,vis);
                
             }
             
         
          
          
          
          
      }
      
      
      
      return count;
       
        
    }
};