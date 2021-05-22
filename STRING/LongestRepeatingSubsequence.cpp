Longest Repeating Subsequence 

Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 

Exampel 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".
Example 2:

Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".

METHOD-1
USING TABULATION

int dp[n+1][n+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0||j==0)
	            dp[i][j]=0;
	            else if(s[i-1]==s[j-1] && i!=j)
	            dp[i][j]=dp[i-1][j-1]+1;
	            else
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            
	            
	            
	        }
	        
	        
	        
	        
	    }

	    cout<<dp[n][n]<<"\n";

}





METHOD-2
USING MEMOIZATION
(Storing the recursive soln in an array)

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
            vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
            return recursive(str,str,n,n,dp);
		}
int recursive(string &x,string &y,int m,int n , vector<vector<int>> &dp)
{
        if(m==0 || n==0)
        return 0;
        if(dp[m][n] != -1)
        return dp[m][n];
        if(x[m-1]==y[n-1] && n!=m)
        return dp[m][n] = 1+recursive(x,y,m-1,n-1,dp);
        else
        return dp[m][n] = max(recursive(x,y,m-1,n,dp),recursive(x,y,m,n-1,dp));
}
};
