K-th element of two sorted Arrays 

LINK:https://www.youtube.com/watch?v=nv7F4PiLUzo

Given two sorted arrays arr1 and arr2 of size M and N respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.


LOGIC:

kth element of the sorted array is same as median of 2 sorted arrays of different size


class Solution{
    public:
    int kthElement(int array1[], int array2[], int n, int m, int k)
    {
        
         // Your code goes here
    if(n>m)
    {
        return kthElement(array2,array1,m,n,k);
    }
    
    int low=max(0,k-m);
    int high=min(n,k);
    
   
    while(low<=high){
        
         int partitionX=(low+high)/2;
         int partitionY=k-partitionX;
        
        int maxleftX=(partitionX==0)?INT_MIN:array1[partitionX-1];
        int minrightX=(partitionX==n)?INT_MAX:array1[partitionX];
        
        
        int maxleftY=(partitionY==0)?INT_MIN:array2[partitionY-1];
        int minrightY=(partitionY==m)?INT_MAX:array2[partitionY];
        
        if(maxleftX<=minrightY && maxleftY <=minrightX){
            
            return max(maxleftX,maxleftY);
            
            
        }else if(maxleftX >minrightY)
        {
            high=partitionX-1;
        }
        else{
            low=partitionX+1;
        }
        
        
    }
        
        
        
        
        
        
        
        
    }
};
