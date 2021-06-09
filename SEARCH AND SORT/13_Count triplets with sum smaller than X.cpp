Count triplets with sum smaller than X 

Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.

 

Example 1:

Input: N = 6, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:

Input: N = 5, X = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).


TIME:O(N^2)
SPACE:O(1)



LOGIC:
-->sort the array
-->use a for loop to pick an outer element and a while loop which will pick the other 2 elements using j and k
-->if the sum of the three elements is greater than X,then decrement k as it points the largest element in the array
-->so what if the sum of the three elements is less than x,then we will add k-j to the answer  
(since the addition of all those elements will also be less than x for sure)


EXAMPLE:

-->  Consider an array {4, 6, 8, 12, 15, 18, 20} with sum = 29.
-->  The outer most loop will fix the i (1st element), so in the first iteration we have fixed one of our element to be 4.
-->  Now we need to find the pairs whose sum is less than 25. 
-->  Starting with j=1, k=6; 6+20=26>25, this pair do not contribute to ans so k--. 
-->  j=1, k=5; 6+18=24<25, now observe that along with {6, 18}; 
-->  sum of pairs {6, 15}, {6, 12} and {6, 8} are also less than 25.
-->  So with i and j fixed there are k-j (5-1=4 in this case) triplets.




CODE:

long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    
	    sort(arr,arr+n);
	    long long ans=0;
	    for(int i=0;i<n-2;i++)
	    {
	        
	        int j=i+1,k=n-1;
	        while(j<k){
	            
	            if(arr[i]+arr[j]+arr[k]>=sum)
	            k--;
	            else{
	                ans+=(k-j);
	                j++;
	                
	            }
	            
	        }
	        
	        
	    }
	   return ans; 
	}
		 

};