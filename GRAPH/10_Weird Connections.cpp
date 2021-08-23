 Number of Operations to Make Network Connected

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:



Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
 

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.






We need to connect all the computers (directly or indirectly).
 We have to return the minimum number of operations that are required to connect the computers. 
An operation consists of removing a cable between two directly connected computers and put it between two disconnected computers.

This problem is a simple variation of counting the number of islands.

We know that the minimum number of edges required for a graph with n nodes to remain connected is n - 1. Similarly,
 if there are k components in a disconnected graph, then we need at least k - 1 edges to connect every component.
With that in our mind, we will start with our base condition. If the number of edges in the graph is greater than n - 1 or not. If not, we will return -1.

Next, we will count the number of components (k). As I already mentioned, we will need k - 1 operations to connect the computers (components). And that is our answer!

We can also solve this using Union-Find approach and count the number of components. 

-----------------------------------------
class Solution {
public:
    void dfs(vector<int> &vis,int i,vector<int> adj[])
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x]){
                dfs(vis,x,adj);
            }
            
        }
        
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        if(connections.size()<n-1)
        return -1;
        vector<int> adj[n];
        
       
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
               dfs(vis,i,adj);  
                count++;
            }
        }
      
        
       return count-1; 
        
    }
};
