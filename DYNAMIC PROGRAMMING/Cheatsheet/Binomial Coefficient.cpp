
			BINOMIAL FORMULA -->C(n-1,r-1)+C(n-1,r)
			PERMUTATION-----> r*C(n-1,r-1)+C(n-1,r)
------------------------------------------------------------------------------------
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.





class Solution{
public:

    int dp[1002][1002];
    int solve(int n,int r){
        
        if(n==r)
        return 1;
        else if(r==1)
        return n;
        else if(r==0)
        return 1;
        else if(r>n)
        return 0;
        else if(dp[n][r]!=-1)
        return dp[n][r];
        else
        return dp[n][r]=(solve(n-1,r-1)%1000000007+solve(n-1,r)%1000000007)%1000000007;
        
        
    }


    int nCr(int n, int r){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n,r);
    }
};
