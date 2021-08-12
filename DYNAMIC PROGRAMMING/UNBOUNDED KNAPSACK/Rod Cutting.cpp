
ROD CUTTING -->UNBOUNDED KNAPSACK 

int dp[1002][1002];
  int solve(int W,int price[],int n,int length[]){
      
      if(n==0)
      return 0;
      
      if(dp[n][W]!=-1)
      return dp[n][W];
      
      if(length[n-1]>W)
      return dp[n][W]=solve(W,price,n-1,length);
      
      return dp[n][W]=max(solve(W,price,n-1,length),price[n-1]+solve(W-length[n-1],price,n,length));
      
      
      
  }
  
  
    int cutRod(int price[], int n) {
        //code here
        
        memset(dp,-1,sizeof(dp));
        int length[n];
        for(int i=0;i<n;i++)
        length[i]=i+1;
        int W=n;
        return solve(W,price,n,length);
        
    }
};
