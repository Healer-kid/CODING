Common elements 

Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C. 









METHOD -1
TIME O(N) ,SPACE O(N)


vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            unordered_map<int,int> mp;
            vector<int> v;
            mp[A[0]]++;
            
            for(int i=1;i<n1;i++)
            {
                if(A[i-1]!=A[i])
                mp[A[i]]++;
                
            }
            mp[B[0]]++;
            
            for(int i=1;i<n2;i++)
            {
                if(B[i-1]!=B[i])
                mp[B[i]]++;
                
            }
            mp[C[0]]++;
             if(mp[C[0]]==3)
                        v.push_back(C[0]);
            for(int i=1;i<n3;i++){
                if(C[i-1]!=C[i]){
                mp[C[i]]++;
                if(mp[C[i]]==3)
                v.push_back(C[i]);
                } 
            }
            return v;
        }

};



METHOD-2
TIME:O(N)  ,SPACE:O(1)



vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i = 0, j = 0, k = 0;
            
            vector <int> res;
            int last = INT_MIN;
            while (i < n1 and j < n2 and k < n3)
            {
                if (A[i] == B[j] and A[i] == C[k] and A[i] != last) 
                {
                    res.push_back (A[i]);
                    last = A[i];
                    i++;
                    j++;
                    k++;
                }
                else if (min ({A[i], B[j], C[k]}) == A[i]) i++;
                else if (min ({A[i], B[j], C[k]}) == B[j]) j++;
                else k++;
            }
            return res;
        }






