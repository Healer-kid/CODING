Sort by Set Bit Count 

Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
Example 2:
Input: 
arr[] = {1, 2, 3, 4, 5, 6};
Output: 
3 5 6 1 2 4
Explanation:
3  - 0110
5  - 0101
6  - 0110
1  - 0001
2  - 0010
4  - 0100
hence the non-increasing sorted order is
{3, 5, 6}, {1, 2, 4}



TIME:O(NLOGN)

LOGIC:

1)use sort (stable sort,so that we can maintain the indeces as well if both elements have same number of setbits)

2) use builtin_popcount,which will give the no of set bits




 static bool comp(int a ,int b)
    {
        
        return __builtin_popcount(a)>__builtin_popcount(b);
    }
    
    
    
    void sortBySetBitCount(int arr[], int n)
    {
       
        
        
        stable_sort(arr,arr+n,comp);
    }
};













NOTE:

right shift -->    x>>1  ==> divide (shift by 1 to the right)

eg) 1000 >> 1   ==> 100
eg) 1000 >> 2   ==> 10


left shift -->     x<<1  ==> multiply

eg) 1000 >> 1  ==> 10000