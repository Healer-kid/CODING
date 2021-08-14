

int dp[102][102];
  int solve(string s,int n,string t,int m)
  {
      if(n==0)
      return m;
      else if(m==0)
      return n;
      else if(n==0 and m==0)
      return 0;
      else if(dp[n][m]!=-1)
      return dp[n][m];
      
      else if(s[n-1]==t[m-1])
      return dp[n][m]=solve(s,n-1,t,m-1);
      else
      return dp[n][m]=min(min(solve(s,n-1,t,m-1),solve(s,n-1,t,m)),solve(s,n,t,m-1))+1;
      
      
      
  }