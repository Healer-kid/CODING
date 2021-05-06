Count More than n/k Occurences 

Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

Example 1:

Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.
Example 2:

Input:
N = 4
arr[] = {2,3,3,2}
k = 3
Output: 2
Explanation: In the given array, 3 and 2 
are the only elements that appears more 
than n/k times. So the count of elements 
are 2. 






unordered_map <int,int> mp;
        int count=n/k;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            
        }
        int ans=0;
        for(auto i:mp)
        {
            if(i.second >count)
            ans++;
        }
        return ans;
        
    }