Find a pair with the given difference

Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.

Examples:

Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80)

Input: arr[] = {90, 70, 20, 80, 50}, n = 45
Output: No Such Pair


METHOD-1
USING 2 LOOPS
TIME:O(N^2)
SPACE:O(1)

for(int i=0;i<n-1;i++)
{
	for(int j=i+1;j<n;j++)
	{
		if(a[i]+a[j]==n)
			return true;
	}
}
return false;




METHOD-2
USING HASHMAP
TIME:O(2N)
SPACE:O(N)


bool findPair(int arr[], int size, int n){
    //code
    
    unordered_set<int> mp;
    for(int i=0;i<size;i++)
    {
       
        mp.insert(arr[i]);
    }
    for(int i=0;i<size;i++){
         if(mp.find(arr[i]+n)!=mp.end())
        {
            return true;
        }
    }
    
    return false;
}


METHOD-3
TIME:O(NLOGN)
SPACE:O(1)
		
WRONG CODE WRONG CODE WRONG CODE: WHERE IT WENT WRONG?


20 50 70 80 90 and n=20

Correct answer is true
But a/c to this code, the initial difference between first and last element is always greater than 20. So the value of r will become 0 and it will return false.


eg) 90 - 20 ==>70 
    so decrement j
    80 - 20 ==>60
    decrement j
    70 - 20 ==>50
    decrement j
    50 - 20 ==>30
    decrement j
    20 - 20 ==>0
now i will get incremented and the condition i<j will get failed


{
 sort(arr,arr+size);
    int i = 0;  
    int j = size-1;
 
    while (i<j)
    {
        if (i != j && arr[j]-arr[i] == n)
        {
            return true;
        }
        else if (arr[j]-arr[i] > n)
            j--;
        else
            i++;
    }
 
    return false;
    
}

--------------------------------------------------------------------------------------
		CORRECT CODE FOR THIS APPROACH


bool findPair(int arr[], int size, int n)
{
    sort(arr,arr+size);
    int i = 0;  
    int j = 1;  --> right condn
 
    while (i<size && j<size)
    {
        if (i != j && arr[j]-arr[i] == n)
        {
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }
 
    return false;
}





