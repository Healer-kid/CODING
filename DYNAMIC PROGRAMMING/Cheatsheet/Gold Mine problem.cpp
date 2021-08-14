Gold Mine Problem 
Easy Accuracy: 51.7% Submissions: 17494 Points: 2
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.


Example 1:

Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}.

Example 2:

Input: n = 4, m = 4
M = {{1, 3, 1, 5},
     {2, 2, 4, 1},
     {5, 0, 2, 3},
     {0, 6, 1, 2}};
Output: 16
Explaination: 
The path is {(2,0) -> (3,1) -> (2,2) 
-> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
-> (0,3)}.




---------------------------------

 int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
      
        int dp[n][m];
        int maxii=0;
        
        if(n==1){		//if there is only one row ,sum all the values
            for(int i=0;i<m;i++)
            maxii=maxii+M[0][i];
            return maxii;
        }
        
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++)
            {
                if(j==m-1){
                    dp[i][j]=M[i][j];
                    
                }else if(i==0){
                    
                    dp[i][j]=M[i][j]+max(dp[i+1][j+1],dp[i][j+1]);
                }else if(i==n-1){
                    
                    dp[i][j]=M[i][j]+max(dp[i-1][j+1],dp[i][j+1]);
                }
                else{
                    dp[i][j]=M[i][j]+max(max(dp[i-1][j+1],dp[i][j+1]),dp[i+1][j+1]); 
                }
                
            }
            
            
        }
        int maxi=dp[0][0];
        for(int i=1;i<n;i++)
        maxi=max(maxi,dp[i][0]);
        
        return maxi;
        
        
    }
};