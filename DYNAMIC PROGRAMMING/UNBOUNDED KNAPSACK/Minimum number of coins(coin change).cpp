Number of Coins 
Medium Accuracy: 47.78% Submissions: 23614 Points: 4
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)




class Solution{

	public:
	int dp[1002][1002];
	int solve(int coins[],int n,int V){
	    
	    
	    if(n==0 and V==0)
	    return 0;
	    else if(V==0)
	    return 0;
	    else if(n==0)
	    return INT_MAX-1;
	    
	    else if(dp[n][V]!=-1)
	    return dp[n][V];
	    
	    else if(coins[n-1]>V)
	    return dp[n][V]=solve(coins,n-1,V);
	    else
	    return dp[n][V]=min(solve(coins,n-1,V),solve(coins,n,V-coins[n-1])+1);
	    
	    
	    
	}
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int n=M;
	   
	   memset(dp,-1,sizeof(dp));
	   
	   if(solve(coins,n,V)!=INT_MAX-1)
	    return solve(coins,n,V);
	   else
	    return -1;
	    
	} 
	  
};