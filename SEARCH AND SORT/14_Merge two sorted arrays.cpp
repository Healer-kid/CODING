Merge two sorted arrays

 
Given two sorted arrays, the task is to merge them in a sorted manner.
Examples: 

Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8} 
Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}
Input: arr1[] = { 5, 8, 9}, arr2[] = {4, 7, 8} 
Output: arr3[] = {4, 5, 7, 8, 8, 9} 





METHOD-1
 
Using Maps (O(nlog(n) + mlog(m)) Time 
 O(N) Extra Space) 

void mergeArrays(int a[], int b[], int n, int m)
{
    
    map<int, bool> mp;
     
    
    for(int i = 0; i < n; i++)
    mp[a[i]] = true;
     
    for(int i = 0;i < m;i++)
    mp[b[i]] = true;
     
  
    for(auto i: mp)
    cout<< i.first <<" ";
}


METHOD-2
Time Complexity : O(n1 + n2) 
Auxiliary Space : O(n1 + n2)

void mergeArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
 
   
    while (i<n1 && j <n2)
    {
       
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    
    while (j < n2)
        arr3[k++] = arr2[j++];
}





