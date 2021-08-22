Travelling Salesman Problem 
Hard Accuracy: 49.8% Submissions: 1315 Points: 8
Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
 

Example 1:

Input: cost = {{0,111},{112,0}}
Output: 223
Explanation: We can visit 0->1->0 and 
cost = 111 + 112.
Example 2:

Input: cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
Output: 3000
Explanation: We can visit 0->1->2->0 and cost 
= 1000+1000+1000 = 3000
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function total_cost() which takes cost as input parameter and returns the total cost to visit each city exactly once starting from city 0 and again comback to city 0.
 

Expected Time Complexity: O(2n * n2)
Expected Space Compelxity: O(2n * n)
 



void tsp(vector<int> &vis,vector<vector<int>>cost,int V,int i,int &mini,int curpath,int count)
{
    
    vis[i]=1;
    count++;
    
    if(count==V and cost[i][0]){
        mini=min(mini,curpath+cost[i][0]);
        vis[i]=0; //this line is important
        return;
    }
    
    for(int x=0;x<V;x++){
        
        if(vis[x]!=1 and cost[i][x]){
            tsp(vis,cost,V,x,mini,curpath+cost[i][x],count);
            
        }
        
        
    }
    vis[i]=0;
    
    
}


int total_cost(vector<vector<int>>cost){
    // Code here
    int V=cost.size();
    vector<int> vis(V,0);
    
    if(V==1)  //if only one node
    return 0;
    
    int mini=INT_MAX;
    
    
       int curpath=0,count=0;
        tsp(vis,cost,V,0,mini,curpath,count);
        
        
   
    
  return mini;  
    
    
    
}
};