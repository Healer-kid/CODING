Array Subset of another array 

Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
 

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

ONLY METHOD-4 WORKS FOR DUPLICATES//

METHOD-1
BRUTE FORCE:
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
 
        
        if (j == m)
            return 0;
    }
 
   
    return 1
}



METHOD-2:
SORTING

{
if (m < n)
        return 0;
 
    // Sort both the arrays
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
 
  
    while (i < n && j < m)
    {
        
        if (arr1[j] < arr2[i])
            j++;
        
        else if (arr1[j] == arr2[i])
        {
            j++;
            i++;
        }
        else if (arr1[j] > arr2[i])
            return 0;
    }
 
    return (i < n) ? false : true;
}

METHOD:3
HASHING (SET)

set<int> mp;
	    for(int i=0;i<m;i++)
	    mp.insert(a[i]);
	    
	    for(int i=0;i<n;i++){
	        if(mp.find(b[i])==mp.end())
	        {
	            flag=1;
	            
	            break;
	        }
	        
	        
	    }
	    
	    
	    
	    if(flag==0)
	    cout<<"Yes"<<"\n";
	    else
	    cout<<"No"<<"\n";
	    



METHOD-4
Use Frequency Table
NOTE: THIS METHOD CAN HANDLE THE DUPLICATES
EG) A1=1,4,4,2
    A2=1,4,2

ANS:NO
BUT THE ABOVE METHODS WILL GIVE YES

 map<int, int> frequency;
     
   
    for (int i = 0; i < m; i++)
    {
        frequency[arr1[i]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;
        else
        {
            return false;
        }
    }
    return true; 




