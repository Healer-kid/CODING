Maximum subsequence sum such that no three are consecutive
Difficulty Level : Medium
Last Updated : 28 May, 2021
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
Examples : 

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27

int solve(int arr[],int n){
        
        if(n<=-1)
        return 0;
        if(n==0)
        return 0;
        if(n==1)
        return arr[0];
        if(n==2)
        return arr[0]+arr[1];
        
        if(dp[n]!=-1)
        return dp[n];
        
     
        return dp[n]=max(solve(arr,n-1),max(arr[n-1]+solve(arr,n-2),
        arr[n-1]+arr[n-2]+solve(arr,n-3)));
       
        
    }
    
    
    
   
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        memset(dp,-1,sizeof(dp));
       return solve(arr,n);
        
        
    }
};