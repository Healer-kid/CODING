Longest consecutive subsequence 

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.


METHOD-1
USING SORTING
TIME:O(NLOGN)

sort(a,a+n);
	    int count=0;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        
	        if(i!=0 && a[i-1]+1==a[i] )
	        count++;
	       else if(a[i-1]==a[i]){
	           continue; 
	        }
	        else
	        count=1;
	        ans=max(ans,count);
	        
	    }



METHOD-2
USING SETS


{
    unordered_set<int> S;
    int ans = 0;

 
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
