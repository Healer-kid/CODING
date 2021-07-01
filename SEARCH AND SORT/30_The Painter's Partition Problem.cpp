The Painter's Partition Problem 
Hard Accuracy: 37.8% Submissions: 7577 Points: 8
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60

Your task:
Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns the minimum time required to paint all partitions.


Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)



LOGIC:
COPY THE ALLOCATE MINIMUM NUMBER OF PAGES

class Solution
{
  public:
  
  bool canpartition(int a[],int n,int barrier,int m)
    {
       int painterscount=1,boards=0;
        for(int i=0;i<n;i++)
        {
            
                 if(a[i]>barrier)
               return false;
            
            if(boards+a[i]>barrier)
            {
                painterscount++;
                boards=a[i];
                
                 if(painterscount>m)
                 return false;
               
            }
            else{
                boards+=a[i];
            }
        }
           //why it doesnt work if studcount>m,then false?
        return true;
        
        
        
    }
    long long minTime(int arr[], int n, int m)
    {
        // code here
        // return minimum time
        
        
         long long res=-1;
        long long low=arr[0],high=0;
        for(int i=0;i<n;i++)
        {
            high+=arr[i];
            low=max(low,(long long)arr[0]);
        }
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(canpartition(arr,n,mid,m))
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
