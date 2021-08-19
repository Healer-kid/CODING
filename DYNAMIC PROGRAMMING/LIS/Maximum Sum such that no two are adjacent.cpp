class Solution
{
    public:
    int dp[10003];
    int solve(int arr[],int n){
        
        if(n<=-1)
        return 0;
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]= max(arr[n-1]+solve(arr,n-2),solve(arr,n-1));
        
    }
    
    
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        memset(dp,-1,sizeof(dp));
       return solve(arr,n);
        
        
    }