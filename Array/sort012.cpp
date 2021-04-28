 
Sort an array of 0s, 1s and 2s 

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.


METHOD -1
DUTCH FLAG PROBLEM
O(N)
O(1)


int mid=0,low=0,high=n-1;
        while(mid<=high){
            if(a[mid]==0)
            swap(a[low++],a[mid++]);
            else if(a[mid]==1)
            mid++;
            else
            swap(a[mid],a[high--]);
        }
