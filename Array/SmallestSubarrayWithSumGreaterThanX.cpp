Smallest subarray with sum greater than x 

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}


METHOD-1
USING TWO LOOPS 
TIME:O(N^2)


int minlength=INT_MAX;	    
for(int i=0;i<n;i++){
   int cursum=a[i];
    
    if(cursum>sum){
    minlength=1;
    break;
    
    }
    
    for(int j=i+1;j<n;j++){
    cursum+=a[j];
    if(cursum>sum && j-i+1<minlength) 
        minlength=j-i+1;
    }
       
    
    
}	    
	cout<<minlength<<"\n";    
	    
	}



METHOD-2
TIME :O(NLOGN)
TWO POINTER APPROACH
LOGIC:

1.start adding the element to get sum>x
2.once it becomes greater than x,start removing from start to get the minimum length as well as
sum > x



{
        int curr_sum = 0, min_len = n+1;
     
        
        int start = 0, end = 0;
        while (end < n)
        {
            // Keep adding array elements while current sum
            // is smaller than x
            while (curr_sum <= x && end < n)
                curr_sum += arr[end++];
     
            // If current sum becomes greater than x.
            while (curr_sum > x && start < n)
            {
                // Update minimum length if needed
                if (end - start < min_len)
                    min_len = end - start;
     
                curr_sum -= arr[start++];
            }
        }
        
    	if(min_len>n)
    	return 0;
        return min_len;
    }