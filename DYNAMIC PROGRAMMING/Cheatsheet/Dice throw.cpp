Dice throw 
Medium Accuracy: 55.36% Submissions: 3112 Points: 4
Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

 

Example 1:

Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.
Example 2:

Input:
M = 2, N = 3, X = 6
Output:
1
Explanation:
There is only 1 way to get
the Sum 6 using 3 dices with
faces from 1 to 2. All the
dices will have to land on 2.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function noOfWays() which takes 3 Integers M,N and X as input and returns the answer.

 

Expected Time Complexity: O(M*N*X)
Expected Auxiliary Space: O(N*X)

 




long long dp[55][55];
  long long solve(int X,int M,int N){
      
      if(N==0 and X==0)
      return 1;
      if(X<=0)
      return 0;
      if(N==0)
      return 0;
      
      if(dp[N][X]!=-1)
      return dp[N][X];
      
      long long count=0;
      
     for(long long i=1;i<=M;i++)
      {
          count+=solve(X-i,M,N-1);
          
      }
      return dp[N][X]=count;
      
      
  }
  
  
    long long noOfWays(int M , int N , int X) {
     
   memset(dp,-1,sizeof(dp));
     return solve(X,M,N);
     
     
     
        // code here
    }
};
