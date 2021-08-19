Maximum sum increasing subsequence 
Medium Accuracy: 49.92% Submissions: 23254 Points: 4
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)





	int maxSumIS(int arr[], int n)  
	{  
	  
	    int maxi=0;
	    int dp[n+1];
	    
	   for(int i=0;i<n;i++)
	   dp[i]=arr[i];
	   
	    for(int i=1;i<n;i++ )
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j] and dp[j]+arr[i]>dp[i])
	            dp[i]=dp[j]+arr[i];
	        }
	        
	    }
	    
	    for(int i=0;i<n;i++)
	    maxi=max(maxi,dp[i]);
	    
	    
	    return maxi;
	}  
};
