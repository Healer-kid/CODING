Triplet Sum in Array 

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.

METHOD-1
BRUTE FORCE
TIME:O(N^3)



 for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++)
        {
 
            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << "Triplet is " << A[i] <<
                        ", " << A[j] << ", " << A[k];
                    return true;
                }
            }
        }
    }


METHOD-2
HASHING 
TIME:O(N2) AND SPACE:O(N)
 int flag=0;
	    int cursum=0;
	   
	    for(int i=0;i<n;i++){
	         unordered_set<int> s;
	         for(int j=i+1;j<n;j++){
	             
	             int ss=sum-(a[i]+a[j]);
	             if(s.find(ss)!=s.end()){
	                 flag=1;
	                 break;
	             }
	             s.insert(a[j]);
	             
	         }
	    if(flag)
	    break;
     }


METHOD-3
SORTING AND TWO POINTER TECHNIQUE
TIME:O(N^2),SPACE:O(1)



sort(A, A + arr_size);
 
   
    for (int i = 0; i < arr_size - 2; i++) {
 
        
        l = i + 1; 
 
        r = arr_size - 1; 
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else 
                r--;
        }
    }
 
   
    return false;
}

