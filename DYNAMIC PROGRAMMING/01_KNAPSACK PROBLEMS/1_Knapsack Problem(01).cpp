LINK:https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4


KNAPSACK USING MEMOIZATION (TOP DOWN)
------------------------------------------

class Solution
{
    int dp[1002][1002];
    public:
    int knapsacks(int W, int wt[], int val[], int n){
        if(n==0 or W==0)
       return 0;
       
       if(dp[n][W]!=-1)
       return dp[n][W];
       
       
       if(wt[n-1]>W)
       return dp[n][W]= knapsacks(W,wt,val,n-1);
       else if(wt[n-1]<=W)
       {
           dp[n][W]=max(knapsacks(W,wt,val,n-1),val[n-1]+knapsacks(W-wt[n-1],wt,val,n-1));
           return dp[n][W];
           
       }
    }
     
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
    memset(dp,-1,sizeof(dp));
       return knapsacks(W,wt,val,n);
      
       
    }
};

----------------------------------------------

TABULATION (BOTTOM UP)
------------------------
class Solution
{
    int dp[1002][1002];
    public:
    int knapSack(int W, int wt[], int val[], int n){
       
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               
               if(i==0 or j==0)
               dp[i][j]=0;
               else if(wt[i-1]>j)
               dp[i][j]=dp[i-1][j];
               else 
               {
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                   
               }
               
               
               
           }
           
       }
       
       return dp[n][W];
    }
     
    
};
