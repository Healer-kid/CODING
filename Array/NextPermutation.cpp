Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]  


IDEA:
1.if the numbers are in descending order,then next permutation is not possible
2.find an element such that it is just greater(must be taken from the array end) than the smallest element,so that we can swap them

TRY THIS EXAMPLE

158476531

STEP 1: 158576431   SWAPPED
STEP 2: 158513467   REVERSE


void nextPermutation(vector<int>& nums) {
      int n=nums.size(),k;
      for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if(k==-1){
            
            reverse(nums.begin(),nums.end());
            
        }else{
            
            for(int i=nums.size()-1;i>k;i--){
                
                if(nums[i]>nums[k]){
                    
                    swap(nums[i],nums[k]);
                    break;
                }
            }    
              reverse(nums.begin()+k+1,nums.end());  
                
                
           
            
            
        }
        
        
    }
};