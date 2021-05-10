Minimum swaps and K together 

Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:

Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation:
To bring elements 2, 1, 3 together, swap element '5' with '3'
such that final array will be- arr[] = {2, 1, 3, 6, 5}

Example 2:

Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2 

METHOD:USING SLIDIDNG WINDOW
TIME;O(N),SPACE:O(1)
LOGIC:
1.find the subarray size.(by counting the number of elements <=k will give the subarray size)
2.find the no.of.elements greater than k in the first subarray
3.now apply sliding window,that is increment if the element is greater than k in the current window
4.decrement if the element is greater than k in the previous window


{
int count=0;
	    for(int i=0;i<n;i++)
	        if(a[i]<=k)
	        count++;
	        
	    
	    int count1=0;
	    for(int i=0;i<count;i++)
	    if(a[i]>k)count1++;
	    
	    
	    int ans=count1;
	    int j=count;
	    int i=0;
	    while(j<n){
	        if(a[j]>k)
	        count1++;
	        if(a[i]>k)
	        count1--;
	        i++;
	        j++;
	        
	        ans=min(ans,count1);
	    }
	    
	    
	   cout<<ans<<"\n"; 
	    
	}