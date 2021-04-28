Cyclically rotate an array by one 

Given an array, rotate the array by one position in clock-wise direction.
 

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4


1) Store last element in a variable say x.
2) Shift all elements one position ahead.
3) Replace first element of array with x.


void rotate(int arr[], int n)
{
    int last=arr[n-1];
	    for(int i=n-1;i>=1;i--){
	        arr[i]=arr[i-1];
	        
	    }
	    arr[0]=last;
    
}