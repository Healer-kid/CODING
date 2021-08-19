Longest Increasing Subsequence 
Medium Accuracy: 46.69% Submissions: 51507 Points: 4
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3


METHOD-1
-----------------
TIME:O(N^2)
--------------------------


 		int dp[n];
	    for(int i=0;i<n;i++)
	    dp[i]=1;
	    
	    for(int i=1;i<n;i++){
	    for(int j=0;j<i;j++){
	        if(a[j]<a[i] && dp[i]<dp[j]+1)
	        dp[i]=dp[j]+1;
	        
	        
	    }
	}
	    
	    
	    int ans=0;
	        for(int i=0;i<n;i++)
	        ans=max(ans,dp[i]);
	        
	    
	    cout<<ans<<"\n";
	    
	}

----------------------------------------------

METHOD-2
-------------------
TIME:O(NLOGN)

----------------


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> seq;
     seq.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(seq.back()<a[i])
            seq.push_back(a[i]);
            else{
                int ind=lower_bound(seq.begin(),seq.end(),a[i])-seq.begin(); //gives the count of the elements which are less than or equal to a[i]
                seq[ind]=a[i];
            }
            
            
        }
     
     
     return seq.size();
     

    }
      
};



-------------------->NOTE:
ISTEAD USE BINARY SEARCH TO RETURN THE COUNT INSTEAD OF THE STL
--------------------
while(h>l)
        {
            int middle = (h+l)/2;
            
            if(arr[middle] == value)
            return middle;
            
            if(arr[middle] > value)
            h = middle;
            
            else 
            l = middle + 1;
        }
        
        return h;


