Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

METHOD-1
SIMPLE  BRUTE FORCE APPROACH
TIME:O(N)

simply compare with each element in the array (one complete traversal)







METHOD-2 
BINARY SEARCH
TIME:O(LOGN)


int search(vector<int>& nums, int target) {
     int low=0,high=nums.size()-1;
        int mid;
        while(low<=high){
        mid=low+(high-low)/2;
            if(nums[mid]==target)
            return mid;
           
            if(nums[mid]<nums[high])    
            {
                if(nums[mid]<target && target<=nums[high])
                low=mid+1;
                else
                 high=mid-1;  
                
            }
            else{
                
                
                if(nums[low]<=target && target<nums[mid])
                high=mid-1;
                else
                low=mid+1;    
                
                
            }
            
            
        
            
            
        }
        
       return -1; 
        
        
    }
};