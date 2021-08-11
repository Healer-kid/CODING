RECURSION:
---------------
// Recursion : Time = O(2^n) and Space = O(n)
int subsetSumUtil(int arr[], int n, int sumCalculated, int sum){

if( n == 0 ){
return abs( sum - (2 * sumCalculated));
}

return min( subsetSumUtil(arr, n-1, sumCalculated + arr[n-1], sum),
subsetSumUtil(arr, n-1, sumCalculated, sum));
}
------------------------------------

BOTTOM UP
----------------

	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range=0;
	   for(int i=0;i<n;i++){
	       
	       range+=arr[i];
	   } 
	   
	   int dp[n+1][range+1];
	   
	   for(int i=0;i<n+1;i++){
	       
	       for(int j=0;j<range+1;j++){
	           
	           if(i==0 and j==0)
	           dp[i][j]=1;
	           else if(j==0)
	           dp[i][j]=1;
	           else if(i==0)
	           dp[i][j]=0;
	           else if(j<arr[i-1])
	           dp[i][j]=dp[i-1][j];
	           else
	           dp[i][j]=(dp[i-1][j]||dp[i-1][j-arr[i-1]]);
	           
	           
	           
	       }
	       
	       
	   }
	   
	   
	   
	   vector<int> v;
	   for(int i=0;i<range+1/2;i++){
	       
	       if(dp[n][i])
	       v.push_back(i);
	   }
	   
	   int mini=INT_MAX;
	   for(int i=0;i<v.size();i++)
	    mini=min(mini,abs(range-2*v[i]));
	    
	    return mini;
	    
	    
	    
	} 
};

