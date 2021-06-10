LINK:https://www.youtube.com/watch?v=1BxbBgNSwHo


Minimum Swaps to Sort 

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.


LOGIC:
1.use an auxillary array,which can store the sorted numbers,so that when we compare it with the
original array,we will know it is not in the right order

2.It should be a vector pair(number and its index),so that we can know which place we can swap it with
3.EXPLANATION
-->pair the index and the number and store it in an array 
-->sort the array
--> now traverse the sorted array
--> check if the index in the pair has the same value as the iterator//v[i].second ==i
-->if yes,then it is in the right place
-->else,we need to swap it with the element in the index
-->decrement i,so that we can check that the swap has been done right (correct swap)


INTUITION:
SORTED ARRAY  ---> ORIGINAL ARRAY


CODE:
//Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> v(nums.size());
	    for(int i=0;i<nums.size();i++)
	    {
	        v[i]={nums[i],i};
	        
	        
	    }
	    sort(v.begin(),v.end());
	    
	    int c=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        if(v[i].second==i)
	        continue;
	        else{
	           c++;
	           swap(v[i],v[v[i].second]);
	           i--;
	           
	        }
	        
	        
	    }
	    
	    return c; 
	}
};

