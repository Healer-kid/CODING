First and last occurrences of x 

Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 


METHOD-1
ONE LOOP
TIME:O(N)


	    int last=-1;
	    int first=-1;
	    for(int i=0;i<n;i++){
	        
	        if(first==-1 && a[i]==x)
	        {first=i;
	        last=i;     
	        }
	        if(last!=-1 && a[i]==x)
	        last=i;
	        
	    }
	    if(first!=-1)
	    cout<<first<<" "<<last<<"\n";
	    else
	    cout<<-1<<"\n";






METHOD-2
USING TWO LOOPS 
TIME:O(n)
SPACE:O(1)

LOGIC:
1) traverse from the start and find the first occurence of the char,once you find the number,then
break the loop
2) traverse from the back(right) and find the first occurence of the char,once you find the 
number,then break the loop

vector<int> find(int arr[], int n , int x )
{
    int a1=-1;
    int a2=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            a1=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==x){
            a2=i;
            break;
        }
    }
    return {a1,a2};
}


METHOD-3
USING BINARY SEARCH(since it is sorted)
TIME:O(logn)
SPACE:O(LOGN)



int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}
 

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}



