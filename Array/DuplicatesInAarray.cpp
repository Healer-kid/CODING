Find duplicates in an array 

Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once
in the given array.

METHOD-1
SORTING
TIME:O(NLOGN)

sort(a,a+n);
for(int i=1;i<n;i++){
if(a[i]==a[i-1])
s.insert(a[i]); //we cant use vector here,cause it will store duplicates too eg) 1,2,2,2,3
 //in this case it will store 2,2 in vector thats why we use set
}


METHOD-2
HASHING
TIME:O(N),SPACE:O(N)


METHOD-3
USING THE GIVEN ARRAY AS HASH MAP


vector<int> duplicates(int a[], int n) {
    // code here
    vector<int> v;
    int index;
    for(int i=0;i<n;i++){
        index=a[i]%n;
        a[index]+=n;
        
        
    }
    for(int i=0;i<n;i++){
        
        if(a[i]/n>1){
            v.push_back(i);
        }
        
    }
    if(v.empty()){
     v.push_back(-1);
     return v;
    }
    
  return v;  
}



