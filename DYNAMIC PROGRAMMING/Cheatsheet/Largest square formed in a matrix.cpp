Largest square formed in a matrix 
Medium Accuracy: 49.17% Submissions: 12579 Points: 4
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
Example 2:

Input: n = 2, m = 2
mat = {{0, 0}, 
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.
Your Task:




class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        
        int dp[n+1][m+1];
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                
                if(i==0 or j==0)
                dp[i][j]=mat[i][j];
                else if(mat[i][j]==1){
                    
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    
                }else
                dp[i][j]=0;
                
                maxi=max(maxi,dp[i][j]);
                
            }
            
        }
        
        return maxi;
        
    }
};
