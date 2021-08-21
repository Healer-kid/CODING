PRIMS
----------
Minimum Spanning Tree 
Medium Accuracy: 49.39% Submissions: 31976 Points: 4
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

Example 1:

Input:

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the distance between edge i and j is w.
 

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
Graph is connected and doesn't contain self loops & multiple edges.


	--------------->METHOD-1<--------------------TIME COMPLEXITY:O(V^2)

class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int> key(V,INT_MAX),parent(V,-1);
        vector<bool> mstset(V,false);
        
        parent[0]=-1;
        key[0]=0;
        
        for(int i=0;i<V-1;i++){
            
          int mini=INT_MAX,u;
            for(int i=0;i<V;i++)
            {
               if(mstset[i]==false and key[i]<mini)
               mini=key[i],u=i;
            }
            
            mstset[u]=true;
            
           for(auto x:adj[u] )
            {
                int f=x[0];
                int s=x[1];
                
                if(mstset[f]==false and s<key[f])
                key[f]=s,parent[f]=u;
                
            }
            
            
            
            
            
            
            
        }
        int sum=0;
        
        for(int i=0;i<V;i++)
        {
            sum+=key[i];
        }
        
       return sum; 
        
        
    }
};
--------------------------------------------------------------------------------------
METHOD-2
---------------
TC:O(ELOGV)
---------------


int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
   
   
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 	-->PRINTING PARENT NODE //WE CAN CALCULATE SUM AS WELL
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

--------------
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 

