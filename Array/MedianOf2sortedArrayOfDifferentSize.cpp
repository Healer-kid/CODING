Median of two sorted arrays of different sizes


Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5
Your Task:
The task is to complete the function MedianOfArrays() that takes array1 and array2 as input and returns their median. 

Expected Time Complexity: O(min(log n, log m)).
Expected Auxiliary Space: O(1).



METHOD:1
TIME:O(M+N),SPACE:O(1)
LOGIC:
-->Given two arrays are sorted. So they can be merged in O(m+n) time. Create a variable count to have a count of elements in the output array.
-->f the value of (m+n) is odd then there is only one median else the median is the average of elements at index (m+n)/2 and ((m+n)/2 – 1).
-->To merge the both arrays, keep two indices i and j initially assigned to 0. Compare the ith index of 1st array and jth index of second, increase the index of the smallest element and increase the count.
-->Check if the count reached (m+n) / 2 if (m+n) is odd and store the element, if even store the average of (m+n)/2 th and (m+n)/2 -1 th element and print it.

int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    
    
    if((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
     
    else
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            m2 = m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2)/2;
    }
}





METHOD-2
using binary search
time:o(min(logx,logy))

LOGIC:
1.Make sure the first array is smaller than the second 
2.we know that there should be half of the total elements on the left side and for the right side as well
3.so every time we will make adjustment according to the half elements
4.if the maximum in the left half of the first array is less than the minimum of the right half of the second array given that the maximum in the left half of the second array is less than the minimum of the right half of the first array
	-->then crct partition
	-->we can move further,that is we found the median
	-->if even ,take avg 
	-->else return the max of two left half elements(since in the left half only we get the extra element bcoz of (x+y+1)/2 has been used)

5.if the partition is not correct that is if the maxleft in the first array is greater than the 
minright of second array,then we should move back in the first array

6.else
go front in the first array


double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    // Your code goes here
    if(array1.size()>array2.size())
    {
        return MedianOfArrays(array2,array1);
    }
    int x=array1.size();
    int y=array2.size();
    int low=0;
    int high=x;
    double ans=0;
   
    while(low<=high){
        
         int partitionX=(low+high)/2;
         int partitionY=(x+y+1)/2-partitionX;
        
        int maxleftX=(partitionX==0)?INT_MIN:array1[partitionX-1];
        int minrightX=(partitionX==x)?INT_MAX:array1[partitionX];
        
        
        int maxleftY=(partitionY==0)?INT_MIN:array2[partitionY-1];
        int minrightY=(partitionY==y)?INT_MAX:array2[partitionY];
        
        if(maxleftX<=minrightY && maxleftY <=minrightX){
            
            if((x+y)%2==0){
              ans=((max(maxleftX,maxleftY)+min(minrightY,minrightX))/2.0);
                return ans;
                
            }else
            {
                ans=max(maxleftX,maxleftY);
                return ans;
                
            }
            
            
        }else if(maxleftX >minrightY)
        {
            high=partitionX-1;
        }
        else{
            low=partitionX+1;
        }
        
        
        
    }
    
    
    










