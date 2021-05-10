Length Unsorted Subarray 

Given an unsorted array Arr of size N. Find the subarray Arr[s...e] such that sorting this subarray makes the whole array sorted.

Example 1:

Input:
N = 11
Arr[] ={10,12,20,30,25,40,32,31,35,50,60}
Output: 3 8
Explanation: Subarray starting from index
3 and ending at index 8 is required
subarray. Initial array: 10 12 20 30 25
40 32 31 35 50 60 Final array: 10 12 20
25 30 31 32 35 40 50 60
(After sorting the bold part)


METHOD-1
USING EXTRA ARRAY

int v[n],i=0;
	    vector<int>k;
	    if(n==1)
	   {
	       k.push_back(0);
	       k.push_back(0);
	       return k;
	   }
	    
	    while(i<n){v[i]=arr[i];
	    i++;
	    }
    sort(v,v+n);
    // return v;
    
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]!=v[i])
        {
            if(k.size()>1)
            {
                k.pop_back();
            }
            k.push_back(i);
        }
        
    }
    if(k.size()==0)
    k.push_back(-1);
    return k;
	}


METHOD-2
TIME:O(N),SPACE:O(N)
LOGIC;
a) Scan from left to right and find the first element which is greater than the next element.
b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). 
C) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. 
D)Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element.
E) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element.



 int s;
	    vector<int> v;
	    for(s=0;s<n-1;s++)
	    {
	        if(arr[s]>arr[s+1])
	        break;
	        
	    }
	    if(s==n-1)
	    {
	        
	        return {0,0};
	        
	    }
	    int e=n-1;
	    for(;e>0;e--)
	    {
	        if(arr[e]<arr[e-1])
	        break;
	        
	    }
	    int mini=arr[s],maxi=arr[s];
	    for(int i=s+1;i<=e;i++)
	    {
	        if(arr[i]<mini)
	        mini=arr[i];
	        if(arr[i]>maxi)
	        maxi=arr[i];
	    }
	    for(int i=0;i<s;i++)
	    {
	        if(arr[i]>mini){
	        v[0]=i;
	        break;
	        }
	    }
	     for(int i=n-1;i>=e+1;i--)
	    {
	        if(arr[i]<maxi){
	        v[1]=i;
	        break;
	        }
	    }
	    
	   return v; 
	    
	}