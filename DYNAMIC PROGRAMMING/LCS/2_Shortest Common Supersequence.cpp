Shortest Common Supersequence 
Medium Accuracy: 54.34% Submissions: 14417 Points: 4
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
Your Task:
Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100



class Solution
{
    public:
    int dp[102][102];
    int solve(string X,string Y,int m,int n){
        
        if(m==0 or n==0)
        return 0;
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        
        else if(X[m-1]==Y[n-1])
        return dp[m][n]=solve(X,Y,m-1,n-1)+1;
        else
        return dp[m][n]=max(solve(X,Y,m-1,n),solve(X,Y,m,n-1));
        
        
    }
    
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        return m+n-solve(X,Y,m,n);
    }
};