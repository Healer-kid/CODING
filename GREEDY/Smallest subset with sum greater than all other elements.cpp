Smallest subset with sum greater than all other elements
Difficulty Level : Easy
Last Updated : 09 Apr, 2021
Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.
Examples : 
 

Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of
this subset is greater than all
other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not 
enough. We can pick elements with 
values 1, 2 or 2, 2. In any case, 
the minimum count is 2.
 

int minElements(int arr[], int n)
{
    				// calculating HALF of array sum
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];   
    halfSum = halfSum / 2;
 
   					 // sort the array in descending order.
    sort(arr, arr + n, greater<int>());
 
    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
 
        curr_sum += arr[i];
        res++;
 
      					  // current sum greater than sum
        if (curr_sum > halfSum)        
            return res;
    }
    return
}