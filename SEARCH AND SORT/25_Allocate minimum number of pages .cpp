Allocate minimum number of pages 

LINK:https://www.youtube.com/watch?v=gYmWHvRHu-s

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:
113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.
Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:
32
Explanation:
Allocation is done as 
{15,17} and {20}


CODE:

class Solution 
{
    public:
    bool canallocate(int a[],int n,int barrier,int m)
    {
       int studcount=0,pages=0;
        for(int i=0;i<n;i++)
        {
            
            if(pages+a[i]>barrier)
            {
                studcount++;
                pages=a[i];
                
                 if(a[i]>barrier)
            return false;
               
            }
            else{
                pages+=a[i];
            }
        }
        if(studcount<m)     //why it doesnt work if studcount>m,then false?
        return true;
        return false;
        
        
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int res=-1;
        int low=arr[0],high=0;
        for(int i=0;i<n;i++)
        {
            high+=arr[i];
            low=min(low,arr[0]);
        }
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(canallocate(arr,n,mid,m))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
                
            
            
            
        }
        
     
        
        
      return low;  
             
        
        
        
        
        
    }
};