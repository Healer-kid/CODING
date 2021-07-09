First negative integer in every window of size k 

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

METHOD-1
BRUTE FORCE 

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
                                                 
                                                 
      vector<long long> v(N-K+1,0);
      for(int i=0;i<N-K+1;i++)
      {
          for(int j=0;j<K;j++)
          {
              if(A[i+j]<0){
              v[i]=A[i+j];
              break;
          }
          }
          
      }                        
                                                 
       return v;                                          
                                                 
 }









METHOD-2
USING SLIDING WINDOW AND QUEUE:


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
                                                 
                                                 
     vector<long long> v;
     queue<int> q;
     for(int i=0;i<K;i++ )
     {
         if(A[i]<0)
         q.push(A[i]);
         
        
     } 
     if(q.empty())
     v.push_back(0);
     else
     v.push_back(q.front());
     
     
     int j=0;
     
     for(int i=K;i<N;i++)
     {
         if(A[j]==q.front())
         q.pop();
         
         j++;
         
         if(A[i]<0)
         q.push(A[i]);
         
         if(q.empty())
         v.push_back(0);
         else
         v.push_back(q.front());
         
         
         
     }
     
   
     
     
     
     
       return v;                                          
                                                 
 }