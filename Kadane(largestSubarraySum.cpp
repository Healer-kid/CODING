Kadane's Algorithm 

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

 

Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.


int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int locsum=arr[0];
    int globsum=arr[0];
    for(int i=1;i<n;i++)
    {
        locsum=max(arr[i],locsum+arr[i]);
        globsum=max(globsum,locsum);
        
        
    }
    
    return globsum;
}