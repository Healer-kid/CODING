Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
 





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
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> adj[numCourses+1];
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            
        }
        
        vector<int> vis(numCourses+1,0);
        vector<int> anc(numCourses+1,0);
        
        for(int i=0;i<numCourses;i++)
        {
            
            if(dfs(vis,anc,i,adj))
                return false;
        }
        
        return true;
        
        
    }
};