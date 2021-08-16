Egg Dropping Puzzle 
Medium Accuracy: 54.38% Submissions: 23653 Points: 4
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200





class Solution
{
    public:
    
    int dp[205][205];
    int solve(int e,int f){
        
        if(e==1 or f==0 or f==1)
        return f;
        
        if(dp[e][f]!=-1)
        return dp[e][f];
        
        int temp=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int brek,nbrek;
            if(dp[e-1][k-1]!=-1)
            {
                brek=dp[e-1][k-1];
            }else{
                
                dp[e-1][k-1]=solve(e-1,k-1);
                brek=dp[e-1][k-1];
                
            }
            if(dp[e][f-k]!=-1)
            {
                nbrek=dp[e][f-k];
            }else{
                
                dp[e][f-k]=solve(e,f-k);
                nbrek=dp[e][f-k];
                
            }
            
            
            
            
            
            int ans=1+max(dp[e-1][k-1],dp[e][f-k]);
            
            temp=min(temp,ans);
        }
        
        return temp;
        
    }
    
    
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
        
    }
};
