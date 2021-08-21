Negative weight cycle 
Medium Accuracy: 50.77% Submissions: 11453 Points: 4
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
 




int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	  
	    
	    vector<int> dis(n);
	   for(int i=0;i<n;i++)
	    dis[i]=INT_MAX;
	    dis[0]=0;
	  
	   for(int i=0;i<n-1;i++ )  //the longest path is n-1 edges
	    {
	        for(auto x:edges){
	            
	            if(dis[x[0]]!=INT_MAX and dis[x[0]]+x[2]<dis[x[1]])
	            dis[x[1]]=dis[x[0]]+x[2];
	            
	        }
	        
	    }
	    
	    for(auto x:edges){
	        if(dis[x[0]]!=INT_MAX and dis[x[0]]+x[2]<dis[x[1]]){
	         return 1;
	            
	        }         
	        
	    }
	    return 0;
	    
	}