Minimize the Heights II 

Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11. 

LOGIC:

1.we know that if we sort the array,the difference between the first and the last element will be the maximum difference
2. we have to modify each and every element either add k or subtract k 
3. so we can do one thing,we can add k to the first value and subtract k from the last value,so that the difference between them will be minimum
   but there is a catch,what if when we add k to some other element and it becomes greater than the last element

eg)  k=3
	1 2 3 4 5
we know ans will be the difference bw first and last element after modification
 first-->	1+3 ==> 4
 last-->	5-3 ==> 2

here  ,the last element is not the largest not to mention that the first element is not the smallest after modification
so we need to check further,thats why we are comparing each time when we subtract k from an element with the smallest found so far
and same goes with the largest one


4)  what if the smallest element becomes negative,then when we find the difference ,it will give a bigger number (ma-(-mi)) ==> ma+mi//so to avoid this we 
should not include negative numbers


CODE



class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int smallest=arr[0]+k;   //HERE ADD K
        int largest=arr[n-1]-k;
        int mini=arr[n-1]-arr[0];
        int mi,ma;
        for(int i=0;i<n-1;i++)
        {
            
            mi=min(smallest,arr[i+1]-k);  //HERE SUBTRACT K
            ma=max(largest,arr[i]+k);
            if(mi<0)
            continue;
            mini=min(mini,ma-mi);
        }
        
        
        return mini;
    }
};