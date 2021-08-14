

int dp[1002][1002];
    int solve(int arr[],int i,int j){
        if(i>=j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        dp[i][j]=INT_MAX;
        for(int k=i;k<j;k++){
            
            dp[i][j]=min(dp[i][j],solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
            
        }
        
        return dp[i][j];
        
    }


    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
       return  solve(arr,1,N-1);
    }
};




-------------------------
BOTTOM UP
--------------------
 int dp[n][n];
	    for(int i=1;i<n;i++)
	    dp[i][i]=0;
	    for(int L=2;L<n;L++)
	    for(int i=1;i<n-L+1;i++){
	        
	        int j=i+L-1;
	        dp[i][j]=INT_MAX;
	        for(int k=i;k<=j-1;k++){
	            int q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
	            if(dp[i][j]>q)
	            dp[i][j]=q;
	        }
	        
	        
	        
	        
	    }
	   cout<<dp[1][n-1]<<"\n"; 
	}