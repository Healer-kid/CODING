Three way partitioning 

Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input: 
n = 3 
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement 
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.

METHOD-1
SORTING 
TIME:O(nLOGN)

void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        sort(array.begin(),array.end());
        
        
        
    }





METHOD-2
USING DUTCH NATIONAL FLAG PROBLEM
TIME:O(N)





void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int mid=0,low=0;
        int high=array.size()-1;
        while(mid<=high){
            
            if(array[mid]<a)
            swap(array[low++],array[mid++]);
            
            else if(array[mid]>b)
            swap(array[mid],array[high--]);
            
            else
            mid++;
        }
        