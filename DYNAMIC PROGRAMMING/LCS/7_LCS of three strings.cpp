LCS of three strings 
Medium Accuracy: 60.72% Submissions: 8867 Points: 4
Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
â€‹Example 2:

Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.



int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
 
    
    int dp[n1+1][n2+1][n3+1];
    
    for(int i=0;i<=n1;i++){
        
        for(int j=0;j<=n2;j++){
            
            for(int k=0;k<=n3;k++){
                
                if(i==0 or j==0 or k==0){
                    dp[i][j][k]=0;
                }else if(A[i-1]==B[j-1] and B[j-1]==C[k-1])
                dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else
                dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                
            }
            
            
        }
        
    }
    
    return dp[n1][n2][n3];
    
}
-------------------------------
PASS BY REFERENCE :
---------------
no new copy of the variable is made, so overhead of copying is saved .Many questions it works without passing by refernce also.
---------------------------------------


int dp[101][101][101];
int lcs(string a , string b, string c, int i, int j, int k) {
	if (i == 0 || j == 0 || k == 0)
	return 0;

	if (dp[i][j][k] != -1)
	return dp[i][j][k];

	if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1] && c[k - 1] == a[i - 1])
	return dp[i][j][k] = 1 + lcs(a, b, c, i - 1, j - 1, k - 1);

	else
	return dp[i][j][k] = max(lcs(a, b, c, i - 1, j, k), max(lcs(a, b, c, i, j - 1, k), lcs(a, b, c, i, j, k - 1)));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
memset(dp, -1, sizeof(dp));
return lcs(A, B, C, n1, n2, n3);
}