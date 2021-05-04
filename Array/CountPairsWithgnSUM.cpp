Count pairs with given sum 

Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.



Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.




MEHTOD-1
BRUTE FORCE

int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            if(i!=j && arr[i]+arr[j]==k)
            count++;
        }
        return count;










we cant use sets,cause it will remove duplicate elements.so dont use sets.

METHOD-2
USING HASHING


 int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(k-arr[i])!=mp.end()){
                count+=mp[k-arr[i]];
            }
            mp[arr[i]]++;
            
            
        }
        
        return count;