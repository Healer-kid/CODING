Maximum path sum in matrix 
Medium Accuracy: 50.83% Submissions: 18429 Points: 4
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)






class Solution{
public:
    void dfs(int row,int col,vector<vector<int>> &Matrix,
    int cursum,int &maxi,int N){
        
        if(row==N)
        {
           maxi=max(maxi,cursum);
           return;
            
            
        }
        if(row>=N or col>=N or col<0)
        return ;
        
        dfs(row+1,col,Matrix,cursum+Matrix[row][col],maxi,N);
         dfs(row+1,col-1,Matrix,cursum+Matrix[row][col],maxi,N);
         dfs(row+1,col+1,Matrix,cursum+Matrix[row][col],maxi,N);
        
        
        
    }



    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
       
        int row=0;
        int maxi=INT_MIN;
        int cursum=0;
        for(int col=0;col<N;col++)
        dfs(row,col,Matrix,cursum,maxi,N);
        
        return maxi;
        
        
    }
};


----------------------------------------------------------

class Solution{
public:
int dp[502][502];
    int dfs(int row,int col,vector<vector<int>> &Matrix,
    int N){
        
        
        if(row>=N or col>=N or col<0 )
        return 0;
        
        if(dp[row][col]!=-1)
        return dp[row][col];
        
         int a=dfs(row+1,col,Matrix,N);
         int b=dfs(row+1,col-1,Matrix,N);
         int c=dfs(row+1,col+1,Matrix,N);
        
       return dp[row][col]=Matrix[row][col]+max(a,max(b,c));
        
    }



    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
       memset(dp,-1,sizeof(dp));
        int row=0;
        int maxi=INT_MIN;
        int cursum=0;
        for(int col=0;col<N;col++)
          maxi=max(maxi,dfs(row,col,Matrix,N));
        
       return maxi;
        
        
    }
};
