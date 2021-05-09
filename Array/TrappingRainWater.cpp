Trapping Rain Water 

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10


METHOD-1
TIME:O(N^2)

int res = 0;
     
    // For every element of the array
    for (int i = 1; i < n-1; i++) {
         
        // Find the maximum element on its left
        int left = arr[i];
        for (int j=0; j<i; j++)
           left = max(left, arr[j]);
         
        // Find the maximum element on its right  
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]);
        
       // Update the maximum water   
       res = res + (min(left, right) - arr[i]);  
    }
 
    return res;


METHOD-2
USING ARRAY
TIME:O(N),SPACE:O(N)

	int left[n];
 
        int right[n];
 
   
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;

METHOD-3
USING TWO POINTERS
TIME:O(N),SPACE:O(1)


int result = 0;
 
    // maximum element on left and right
    int left_max = 0, right_max = 0;
 
    // indices to traverse the array
    int lo = 0, hi = n - 1;
 
    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
 
    return result;
}





